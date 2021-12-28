//
// Created by marti on 18.12.21 г..
//

#ifndef TEST_TLVPARSERWINDOW_H
#define TEST_TLVPARSERWINDOW_H

#include "QWidget"
#include "QPushButton"
#include "QLineEdit"
#include "QTreeWidget"

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

private slots:
    void parseTlv();
};

#endif //TEST_TLVPARSERWINDOW_H
