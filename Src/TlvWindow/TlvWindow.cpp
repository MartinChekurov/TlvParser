#include "TlvWindow.h"
#include "QVBoxLayout"
#include "QTreeWidgetItem"
#include <sstream>
#include <iostream>
#include "QDebug"

TlvWindow::TlvWindow(QWidget* parent)
	: QWidget{parent},
	  tlvField{},
	  tlvParseBtn{},
	  tlvTree{} {
	connect(&tlvParseBtn, SIGNAL(clicked()), this, SLOT(parse()));
	tlvParseBtn.setText("Parse");
	QHBoxLayout* h = new QHBoxLayout();
	if (h) {
		h->addWidget(&tlvField);
		h->addWidget(&tlvParseBtn);
	}
	tlvTree.setColumnCount(1);
	QVBoxLayout* v = new QVBoxLayout();
	if (v) {
		v->addLayout(h);
		v->addWidget(&tlvTree);
	}
	setLayout(v);
	setWindowTitle("TLV Parser");
}

TlvWindow::~TlvWindow() {

}
								
unsigned char HexChar (char c)
{
	if ('0' <= c && c <= '9') return (unsigned char)(c - '0');
	if ('A' <= c && c <= 'F') return (unsigned char)(c - 'A' + 10);
	if ('a' <= c && c <= 'f') return (unsigned char)(c - 'a' + 10);
	return 0xFF;
}

void TlvWindow::parse() {
	std::string field = tlvField.text().toStdString();
	unsigned int size = field.length();
	unsigned char* data = new unsigned char[size/2]{};
	unsigned int i = 0;
	for (int bytes = 0, ascii = 0 ; bytes < size && ascii < size ; bytes++, ascii++) {
		data[bytes] = HexChar(field[ascii]);
		data[bytes] <<= 4;
		data[bytes] |= HexChar(field[++ascii]);
		data[bytes] &= 0xFF;
	}
	while(i < size/2) {
		unsigned long long tag = 0;
		tag = data[i++];
		if ((data[i] & 0x1F) == 0x1F) {
			do {
				if (i < size) {
					tag <<= 8;
					tag |= data[i++];
				}
			} while (data[i] & 0x80);
		}
		printf("\ntag: %X", tag);
		unsigned long long length = 0;
		if (!(data[i] & 0x80)) {
			length = data[i++] & 0x7F;
		} else {
			unsigned int bytes = data[i] & 0x7F;
			for (unsigned int count = 0 ; count < bytes && i < size ; count++, i++) {
				length <<= 8;
				length |= data[i];
			}	
		}
		i += length;	
		printf("\nlength: %X", length);
	}
	tlvTree.clear();
}

void TlvWindow::addRoot(const QString& text) {
	QTreeWidgetItem* item = new QTreeWidgetItem(&tlvTree);
	item->setText(0, text);
}

void TlvWindow::addChild(QTreeWidgetItem* parent, const QString& text) {
	QTreeWidgetItem* item = new QTreeWidgetItem();
	item->setText(0, text);
	parent->addChild(item);
}
