#ifndef TLV_FIELD_H_
#define TLV_FIELD_H_

#include "QLineEdit"
#include "QPushButton"

class TlvField : public QWidget {

	Q_OBJECT

public:
	TlvField(QWidget* parent = nullptr);
	~TlvField();

	void connect(QObject* object);

private:
	QLineEdit* tlvField;
	QPushButton* tlvParseBtn;
};

#endif
