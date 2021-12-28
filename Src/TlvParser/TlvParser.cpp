//
// Created by marti on 19.12.21 г..
//
#include "TlvParser.h"

TlvParser::TlvParser(const QByteArray& data) :
                        data(data)

{

}

TlvParser::~TlvParser()
{

}

static QTreeWidgetItem* addTlvRoot(QTreeWidget* parent, const QString& text)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    if (item) {
        item->setText(0, text);
        item->setExpanded(true);
    }
    return item;
}

static QTreeWidgetItem* addTlvChild(QTreeWidgetItem* parent, const QString& text)
{
    if (!parent) {
        return nullptr;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    if (item) {
        item->setText(0, text);
        item->setExpanded(true);
        parent->addChild(item);
    }
    return item;
}

static unsigned int parseToQtTree_(const QByteArray& data, QTreeWidget* root, QTreeWidgetItem* child)
{
    unsigned int initialPos = 0, length = 0, tag = 0, lengthFirstByte = 0, tagBytes = 0, status = 0, size = 0;
    unsigned int i = 0;
    QString str;
    if (!data.length()) {
        return 1;
    }
    size = data.length();
    while(i < size) {
        tag = 0;
        length = 0;
        tagBytes = 0;
        if ((((unsigned char)data.at(i)) & 0x1F) == 0x1F) {
            do {
                if (i >= size) {
                    return 1;
                }
                tag <<= 8;
                tag |= ((unsigned char)data.at(i));
                i++;
                tagBytes++;
            } while (((unsigned char)data.at(i)) & 0x80);
            if (i >= size) {
                return 1;
            }
            tag <<= 8;
            tag |= ((unsigned char)data.at(i));
            i++;
            tagBytes++;
        } else {
            tag = ((unsigned char)data.at(i));
            i++;
            tagBytes++;
        }
        if (i >= size) {
            return 1;
        }
        if (!(((unsigned char)data.at(i)) & 0x80)) {
            length = ((unsigned char)data.at(i)) & 0x7F;
            lengthFirstByte = 0;
            str = QString::asprintf("%0*X  %02X  ", tagBytes, tag, length).toUpper();
            i++;
        } else {
            unsigned int bytes = ((unsigned char)data.at(i)) & 0x7F;
            lengthFirstByte = ((unsigned char)data.at(i));
            i++;
            for (unsigned int count = 0 ; count < bytes ; count++, i++) {
                if (i >= size) {
                    return 1;
                }
                length <<= 8;
                length |= ((unsigned char)data.at(i));
            }
            str = QString::asprintf("%0*X  %02X%0*X  ", tagBytes, tag, lengthFirstByte, bytes*2, length).toUpper();
        }
        if ((tag >> ((tagBytes - 1) * 8)) & 0x20) {
            QTreeWidgetItem* item = nullptr;
            if (child) {
                item = addTlvChild(child, str);
            }
            if (root){
                item = addTlvRoot(root, str);
            }
            status = parseToQtTree_(data.mid(i, length), nullptr, item);
            if (status) {
                return status;
            }
        }
        initialPos = i;
        i += length;
        if (i > size) {
            return 1;
        }
        str += QString(data.mid(initialPos, length).toHex()).toUpper();
        if (!(((tag >> ((tagBytes - 1) * 8)) & 0x20))) {
            if (child) {
                addTlvChild(child, str);
            }
            if (root){
                addTlvRoot(root, str);
            }
        }
    }
    return 0;
}

unsigned int TlvParser::parseToQtTree(QTreeWidget *root, QTreeWidgetItem *child)
{
    return parseToQtTree_(this->data, root, child);
}
