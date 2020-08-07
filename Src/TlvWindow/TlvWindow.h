#ifndef TLV_WINDOW_H_
#define TLV_WINDOW_H_

#include "QWidget"
#include "QLineEdit"
#include "QPushButton"
#include "QTreeWidget"

class TlvWindow : public QWidget {

	Q_OBJECT

public:
	TlvWindow(QWidget* parent = nullptr);
	~TlvWindow();

	QTreeWidgetItem* addRoot(const QString& text);
	QTreeWidgetItem* addChild(QTreeWidgetItem* parent, const QString& text);
	unsigned char hexChar(char c);
	unsigned char getIndex(const QString& str, unsigned int index);
	int parseRecursive(const QString& data, QTreeWidgetItem* parent);

private slots:
	void parse();

private:
	QLineEdit tlvField;
	QPushButton tlvParseBtn;
	QTreeWidget tlvTree;
};

#endif
