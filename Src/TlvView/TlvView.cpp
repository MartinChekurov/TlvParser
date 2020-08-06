#include "TlvView.h"
#include "qlayoutitem.h"
#include "qtreewidget.h"

TlvView::TlvView(QWidget* parent)
	: QWidget{parent},
	  tree{} {

	tree.setColumnCount(1);
}

TlvView::~TlvView() {

}

void TlvView::parse() {
	QTreeWidgetItem* item = new QTreeWidgetItem(&tree);
	item->setToolTip(0, "aaaa");
	
}
