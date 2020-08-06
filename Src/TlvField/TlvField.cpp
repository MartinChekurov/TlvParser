#include "TlvField.h"
#include "qboxlayout.h"
#include "qobject.h"
#include "qobjectdefs.h"

TlvField::TlvField(QWidget* parent)
	: QWidget{parent},
	  tlvField{new QLineEdit{}},
	  tlvParseBtn{new QPushButton{}} {
	QHBoxLayout* layout = new QHBoxLayout();
	if (layout) {
		if (tlvField) {
			layout->addWidget(tlvField);
		}
		if (tlvParseBtn) {
			tlvParseBtn->setText("Parse");
			tlvParseBtn->setEnabled(true);
			layout->addWidget(tlvParseBtn);
		}
		setLayout(layout);
	}
}

TlvField::~TlvField() {

}

void TlvField::connect(QObject* object) {
	if (object && tlvParseBtn) {
		QObject::connect(tlvParseBtn, SIGNAL(clicked()), object, SLOT(parse()));
	}
}
