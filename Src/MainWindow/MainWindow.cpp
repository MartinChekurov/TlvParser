#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow* parent) :
        QMainWindow(parent),
        parserWindow(new TlvParserWindow(this))
{
    setCentralWidget(parserWindow);
}

MainWindow::~MainWindow()
{

}