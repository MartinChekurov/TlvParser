//
// Created by marti on 17.12.21 г..
//

#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include "QMainWindow"
#include "TlvParserWindow.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

private:
    TlvParserWindow* parserWindow;

public:
    MainWindow(QMainWindow* parent = nullptr);
    ~MainWindow();
};

#endif //TEST_MAINWINDOW_H
