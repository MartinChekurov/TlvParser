#ifndef TLV_VIEW_H_
#define TLV_VIEW_H_

#include "QWidget"
#include "QTreeWidget"

class TlvView : public QWidget {

	Q_OBJECT

public:
	TlvView(QWidget* parent = nullptr);
	~TlvView();

private slots:
	void parse();

private:
	QTreeWidget tree;
};

#endif
