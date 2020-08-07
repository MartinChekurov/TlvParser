#include "TlvWindow.h"
#include "QVBoxLayout"
#include "QTreeWidgetItem"
#include "QHeaderView"

TlvWindow::TlvWindow(QWidget* parent)
	: QWidget{parent},
	  tlvField{},
	  tlvParseBtn{},
	  tlvTree{} {
	connect(&tlvParseBtn, SIGNAL(clicked()), this, SLOT(parse()));
	tlvField.setMinimumWidth(500);
	tlvParseBtn.setText("Parse");
	QHBoxLayout* h = new QHBoxLayout();
	if (h) {
		h->addWidget(&tlvField);
		h->addWidget(&tlvParseBtn);
	}
	tlvTree.setColumnCount(1);
	tlvTree.header()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tlvTree.header()->setStretchLastSection(false);
	tlvTree.setHeaderHidden(true);
	tlvTree.setMinimumHeight(500);
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
	unsigned int i{}, initialPos{}, length{}, tag{}, size = data.length();
	if (!size) {
		return 1;
	}
	while(i < size/2) {
		tag = 0;
		length = 0;
		initialPos = i;
		if ((getIndex(data, i) & 0x1F) == 0x1F) {
			do {
				if (i >= size) {
					return 1;
				}
				tag <<= 8;
				tag |= getIndex(data, i);
				i++;
			} while (getIndex(data, i) & 0x80);
			if (i >= size) {
				return 1;
			}
			tag |= getIndex(data, i);
			i++;
		} else {
			tag = getIndex(data ,i);
			i++;
		}
		if (i >= size) {
			return 1;
		}
		if (!(getIndex(data, i) & 0x80)) {
			length = getIndex(data, i) & 0x7F;
			i++;
		} else {
			unsigned int bytes = getIndex(data, i) & 0x7F;
			i++;
			for (unsigned int count = 0 ; count < bytes ; count++, i++) {
				if (i >= size) {
					return 1;
				}
				length <<= 8;
				length |= getIndex(data, i);
			}	
		}
		if (tag & 0x20) {
			QTreeWidgetItem* item = nullptr;
			if (parent) {
				item = addChild(parent, data.mid(initialPos*2, (i-initialPos)*2));
			} else {
				item = addRoot(data.mid(initialPos*2, (i-initialPos)*2));
			}
			parseRecursive(data.mid(i*2, length*2), item);
		}
		i += length;	
		if (i > size) {
			return 1;
		}
		if (!(tag & 0x20)) {
			if (parent) {
				addChild(parent, data.mid(initialPos*2, i*2));
			} else {
				addRoot(data.mid(initialPos*2, i*2));
			}
		}
	}
	return 0;
}

void TlvWindow::parse() {
	tlvTree.clear();
	int status = parseRecursive(tlvField.text(), nullptr);
}

QTreeWidgetItem* TlvWindow::addRoot(const QString& text) {
	QTreeWidgetItem* item = new QTreeWidgetItem(&tlvTree);
	item->setText(0, text);
	item->setExpanded(true);
	return item;
}

QTreeWidgetItem* TlvWindow::addChild(QTreeWidgetItem* parent, const QString& text) {
	QTreeWidgetItem* item = new QTreeWidgetItem(parent);
	item->setText(0, text);
	item->setExpanded(true);
	parent->addChild(item);
	return item;
}
