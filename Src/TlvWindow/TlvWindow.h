#ifndef TLV_WINDOW_H_
#define TLV_WINDOW_H_

#include "QWidget"
#include "QLineEdit"
#include "QPushButton"
#include "QTreeWidget"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qtreewidget.h"

class TlvWindow : public QWidget {

	Q_OBJECT

public:
	TlvWindow(QWidget* parent = nullptr);
	~TlvWindow();

	void addRoot(const QString& text);
	void addChild(QTreeWidgetItem* parent, const QString& text);

private slots:
	void parse();

private:
	QLineEdit tlvField;
	QPushButton tlvParseBtn;
	QTreeWidget tlvTree;
};

#endif
