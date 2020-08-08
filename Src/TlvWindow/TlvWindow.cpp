#include "TlvWindow.h"
#include "QVBoxLayout"
#include "QTreeWidgetItem"
#include "QHeaderView"
#include <iostream>
#include <stdio.h>

TlvWindow::TlvWindow(QWidget* parent)
	: QWidget{parent},
	  tlvField{},
	  tlvParseBtn{},
	  tlvTree{} {

	connect(&tlvParseBtn, SIGNAL(clicked()), this, SLOT(parse()));

	tlvField.setMinimumWidth(500);
	tlvField.setPlaceholderText("C20401020304.. no spaces");

	tlvParseBtn.setText("Parse");

	QHeaderView* header = tlvTree.header();
	if (header) {
		header->setSectionResizeMode(QHeaderView::ResizeToContents);
		header->setStretchLastSection(false);
	}
	tlvTree.setHeaderHidden(true);
	tlvTree.setMinimumHeight(500);
	tlvTree.setColumnCount(1);

	QVBoxLayout* v = new QVBoxLayout();
	if (v) {
		QHBoxLayout* h = new QHBoxLayout();
		if (h) {
			h->addWidget(&tlvField);
			h->addWidget(&tlvParseBtn);
			v->addLayout(h);
		}
		v->addWidget(&tlvTree);
		setLayout(v);
	}
	setWindowTitle("TLV Parser");
}

TlvWindow::~TlvWindow() {

}
								
unsigned char TlvWindow::hexChar(char c)
{
	if ('0' <= c && c <= '9') return (unsigned char)(c - '0');
	if ('A' <= c && c <= 'F') return (unsigned char)(c - 'A' + 10);
	if ('a' <= c && c <= 'f') return (unsigned char)(c - 'a' + 10);
	return 0xFF;
}

unsigned char TlvWindow::getIndex(const QString& str, unsigned int index) {
		
	unsigned char result{};
	unsigned int i = index * 2;
	if (i < str.length()) {
		result = hexChar(str[i].toLatin1());
	}
	i++;
	if (i < str.length()) {
		result <<= 4;
		result |= hexChar(str[i].toLatin1()) & 0x0F;
	}
	return result;
}

int TlvWindow::parseRecursive(const QString& data, QTreeWidgetItem* parent) {
	unsigned int i{}, initialPos{}, length{}, tag{}, size = data.length(), lengthFirstByte{}, tagBytes{};
	if (!size) {
		return 1;
	}
	char buf[100]{};
	while(i < size/2) {
		tag = 0;
		length = 0;
		tagBytes = 0;
		if ((getIndex(data, i) & 0x1F) == 0x1F) {
			do {
				if (i >= size) {
					return 1;
				}
				tag <<= 8;
				tag |= getIndex(data, i);
				i++;
				tagBytes++;
			} while (getIndex(data, i) & 0x80);
			if (i >= size) {
				return 1;
			}
			tag |= getIndex(data, i);
			i++;
			tagBytes++;
		} else {
			tag = getIndex(data ,i);
			i++;
			tagBytes++;
		}
		if (i >= size) {
			return 1;
		}
		if (!(getIndex(data, i) & 0x80)) {
			length = getIndex(data, i) & 0x7F;
			lengthFirstByte = 0;
			snprintf(buf, sizeof(buf), "%0*X %02X", tagBytes, tag, length);
			i++;
		} else {
			unsigned int bytes = getIndex(data, i) & 0x7F;
			lengthFirstByte = getIndex(data, i);
			i++;
			for (unsigned int count = 0 ; count < bytes ; count++, i++) {
				if (i >= size) {
					return 1;
				}
				length <<= 8;
				length |= getIndex(data, i);
			}	
			snprintf(buf, sizeof(buf), "%0*X %02X%0*X", tagBytes, tag, lengthFirstByte, bytes*2, length);
		}
		QString str(buf);
		if (tag & 0x20) {
			QTreeWidgetItem* item = nullptr;
			if (parent) {
				item = addChild(parent, str);
			} else {
				item = addRoot(str);
			}
			parseRecursive(data.mid(i*2, length*2), item);
		}
		initialPos = i;
		i += length;	
		if (i > size) {
			return 1;
		}
		str += " " + data.mid(initialPos*2, (i - initialPos)*2);
		if (!(tag & 0x20)) {
			if (parent) {
				addChild(parent, str);
			} else {
				addRoot(str);
			}
		}
	}
	return 0;
}

void TlvWindow::parse() {
	tlvTree.clear();
	int status = parseRecursive(tlvField.text(), nullptr);
	if (status) {
		tlvTree.clear();
	}
}

QTreeWidgetItem* TlvWindow::addRoot(const QString& text) {
	QTreeWidgetItem* item = new QTreeWidgetItem(&tlvTree);
	if (item) {
		item->setText(0, text);
		item->setExpanded(true);
	}
	return item;
}

QTreeWidgetItem* TlvWindow::addChild(QTreeWidgetItem* parent, const QString& text) {
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
