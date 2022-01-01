//
// Created by marti on 18.12.21 г..
//

#ifndef TEST_TLVPARSERWINDOW_H
#define TEST_TLVPARSERWINDOW_H

#include "QWidget"
#include "QPushButton"
#include "QLineEdit"
#include "QTreeWidget"
#include "TlvInfo.h"

class TlvParserWindow : public QWidget {

    Q_OBJECT

public:
    TlvParserWindow(QWidget *parent = nullptr);
    ~TlvParserWindow();

private:
    QPushButton* parseButton;
    QLineEdit* parseField;
    QTreeWidget* parsedField;

    void initUi();
    QString buildTagInfo(TlvInfo* tagInfo);

private slots:
    void parse();
    void enableParseButton(const QString& text);
    void tagClicked(QTreeWidgetItem *item, int column);
    void tagDoubleClicked(QTreeWidgetItem *item, int column);
};

#endif //TEST_TLVPARSERWINDOW_H
