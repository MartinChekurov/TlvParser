#include "QHBoxLayout"
#include "QVBoxLayout"
#include "TlvParserWindow.h"
#include "TlvParser.h"
#include "QMessageBox"
#include "QHeaderView"

TlvParserWindow::TlvParserWindow(QWidget* parent) :
        QWidget(parent),
        parseButton(new QPushButton( this)),
        parseField(new QLineEdit(this)),
        parsedField(new QTreeWidget(this))
{
    initUi();
}

TlvParserWindow::~TlvParserWindow()
{

}

void TlvParserWindow::initUi()
{
    QHBoxLayout* hBoxLayout = nullptr;
    QVBoxLayout* vboxLayout = nullptr;

    if (parsedField) {
        parsedField->setColumnCount(1);
        parsedField->setHeaderHidden(true);
    }
    if (parseButton) {
        parseButton->setText("Parse");
        connect(parseButton, SIGNAL(clicked()), this, SLOT(parseTlv()));
    }

    hBoxLayout = new QHBoxLayout();
    if (hBoxLayout) {
        hBoxLayout->addWidget(parseField);
        hBoxLayout->addWidget(parseButton);
    }
    vboxLayout = new QVBoxLayout();
    if (vboxLayout) {
        vboxLayout->addLayout(hBoxLayout);
        vboxLayout->addWidget(parsedField);
        setLayout(vboxLayout);
    }
}

//qstring --> toutf8--> fromhex --> bytearray of hex
//bytearray of hex --> tohex --> qstring

//E0 39 DF 23 02 47 31 9F 1A 02 03 80 5F 2A 02 09 78 9F 15 02 70 11 DF 28 05 01 02 25 71 00 DF 29 04 30 30 30 30 9F 35 01 22 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 5F 36 01 02 E1 81 9B 9F 06 06 A0 00 00 00 25 01 DF 33 08 80 00 20 00 00 00 00 00 DF 6A 02 00 02 DF 49 10 41 4D 45 58 20 20 20 20 20 20 20 20 20 20 20 20 9F 09 02 00 01 DF 41 06 00 00 00 00 00 00 DF 81 21 05 00 00 00 00 00 DF 81 22 05 C4 00 00 00 00 DF 81 20 05 DC 50 84 00 00 DF C3 0D 04 00 00 00 00 DF C3 0E 04 00 00 13 88 DF C3 0C 04 05 F5 E0 FF DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 04 9F 66 04 34 20 40 00 9F 6D 01 C0 9F 6E 04 D8 E0 00 03 E1 76 9F 06 07 A0 00 00 03 33 01 01 DF 33 08 80 00 00 00 00 00 00 00 DF 6A 02 00 29 DF 49 10 55 4E 49 4F 4E 20 50 41 59 20 20 20 20 20 20 20 9F 09 02 00 20 DF 41 06 00 00 00 00 00 00 DF 42 14 00 10 00 00 00 D8 40 04 F8 00 D8 40 00 A8 00 00 10 40 00 00 DF 74 06 00 00 00 00 00 00 DF 75 06 00 00 00 00 50 00 DF 76 06 99 99 99 99 99 99 DF 77 06 00 00 00 00 25 00 E1 81 C8 9F 06 07 A0 00 00 00 04 30 60 DF 33 08 80 00 00 00 00 00 00 00 DF 6A 02 00 07 DF 49 10 4D 41 45 53 54 52 4F 20 20 20 20 20 20 20 20 20 9F 09 02 00 02 DF 41 06 00 00 00 00 00 00 DF 81 21 05 00 00 80 00 00 DF 81 22 05 F4 50 04 80 0C DF 81 20 05 F4 50 04 80 0C DF 81 23 06 00 00 00 00 00 00 DF 81 26 06 00 00 00 00 50 00 DF 81 24 06 99 99 99 99 99 99 DF 81 25 06 99 99 99 99 99 99 DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 02 9F 66 04 34 20 40 00 9F 7E 01 01 DF 81 17 01 E0 DF 81 18 01 60 DF 81 19 01 08 DF 81 1E 01 10 DF 81 2C 01 00 DF 81 1B 01 20 DF 81 1F 01 08 E1 81 C8 9F 06 07 A0 00 00 00 04 10 10 DF 33 08 80 00 20 00 00 00 00 00 DF 6A 02 00 05 DF 49 10 4D 41 53 54 45 52 43 41 52 44 20 20 20 20 20 20 9F 09 02 00 02 DF 41 06 00 00 00 00 00 00 DF 81 21 05 00 00 00 00 00 DF 81 22 05 F4 50 04 80 0C DF 81 20 05 F4 50 84 80 0C DF 81 23 06 00 00 00 00 00 00 DF 81 26 06 00 00 00 00 50 00 DF 81 24 06 99 99 99 99 99 99 DF 81 25 06 99 99 99 99 99 99 DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 02 9F 66 04 34 20 40 00 9F 7E 01 01 DF 81 17 01 E0 DF 81 18 01 60 DF 81 19 01 08 DF 81 1E 01 10 DF 81 2C 01 00 DF 81 1B 01 20 DF 81 1F 01 08 E1 81 9B 9F 06 07 A0 00 00 00 03 10 10 DF 33 08 80 00 20 00 00 00 20 00 DF 6A 02 00 11 DF 49 10 56 49 53 41 20 20 20 20 20 20 20 20 20 20 20 20 9F 09 02 00 8C 9F 09 02 00 8D 9F 09 02 00 96 DF 41 06 00 00 00 00 00 00 DF 81 21 05 00 10 00 00 00 DF 81 22 05 DC 40 04 F8 00 DF 81 20 05 DC 40 00 A8 00 DF C3 0D 04 00 00 00 00 DF C3 0E 04 00 00 13 89 DF C3 0C 04 05 F5 E0 FF DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 03 9F 66 04 34 20 40 00 E1 81 9B 9F 06 07 A0 00 00 00 03 20 10 DF 33 08 80 00 20 00 00 00 00 00 DF 6A 02 00 09 DF 49 10 56 49 53 41 20 45 4C 45 43 54 52 4F 4E 20 20 20 9F 09 02 00 8C 9F 09 02 00 8D 9F 09 02 00 96 DF 41 06 00 00 00 00 00 00 DF 81 21 05 00 10 00 00 00 DF 81 22 05 DC 40 04 F8 00 DF 81 20 05 DC 40 00 A8 00 DF C3 0D 04 00 00 00 00 DF C3 0E 04 00 00 13 89 DF C3 0C 04 05 F5 E0 FF DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 03 9F 66 04 34 20 40 00 E1 81 97 9F 06 07 A0 00 00 01 52 30 10 DF 33 08 80 00 00 00 00 FE 00 00 DF 6A 02 00 13 DF 49 10 44 49 4E 45 52 53 20 43 4C 45 53 53 20 20 20 20 9F 09 02 00 01 9F 09 02 00 02 9F 09 02 00 03 DF 41 06 00 00 00 00 00 00 DF 42 14 A4 00 18 00 00 10 60 04 18 00 10 60 04 08 00 00 10 40 00 00 DF C6 02 04 00 00 00 00 DF C6 03 04 00 00 13 88 DF C6 01 04 05 F5 E0 FF DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 06 9F 66 04 34 20 40 00 E1 81 99 9F 06 07 A0 00 00 01 41 00 01 DF 33 08 80 00 00 00 00 00 00 10 DF 6A 02 02 20 DF 49 10 50 41 47 4F 42 41 4E 43 4F 4D 41 54 20 20 20 20 9F 09 02 00 0B D9 01 00 DB 03 00 00 00 DF C0 01 05 A0 00 18 00 00 DF C0 02 05 10 60 04 18 00 DF C0 03 05 10 60 04 08 00 DF C3 01 05 00 10 40 00 00 DF C3 0D 04 00 00 00 00 DF C3 0E 04 00 00 13 88 DF C3 0C 04 05 F5 E0 FF DF 77 06 00 00 00 00 25 00 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 DF 81 0C 01 0C 9F 66 04 34 20 40 00 E1 81 E4 9F 06 07 A0 00 00 01 41 00 01 DF 33 08 80 00 00 00 00 00 00 00 DF 6A 02 02 20 DF 49 10 50 41 47 4F 42 41 4E 43 4F 4D 41 54 20 20 20 20 9F 09 02 00 0C DF 41 06 00 00 00 00 00 00 DF 81 21 05 20 00 00 00 00 DF 81 22 05 DE F8 FC F8 00 DF 81 20 05 DE F8 DC A8 00 DF 81 23 06 00 00 00 00 00 00 DF 81 26 06 00 00 00 00 50 00 DF 81 24 06 99 99 99 99 99 99 DF 81 25 06 99 99 99 99 99 99 DF 77 06 00 00 00 00 25 00 DF 81 0C 01 0A DF 81 01 01 00 DF CA 01 05 34 00 40 02 99 DF 81 03 01 99 DF CA 0B 01 00 DF 81 05 07 9F 78 9F 07 C7 42 D1 DF CA 0A 15 5F 28 9F 42 9F 0D 9F 0E 9F 0F 5A 5F 34 5F 24 9F 07 9F 08 9F 78 9F 33 03 E0 F8 C8 9F 40 05 F0 00 B0 A0 01 C7 05 34 00 40 02 99 9F 66 04 34 20 40 00
void TlvParserWindow::parseTlv()
{
    QString hexWithSpaces = "^(\\s*[0-9a-fA-F]{2}+)(\\s*[0-9a-fA-F]{2}\\s*)*$";
    QRegularExpression re;
    QRegularExpressionMatch match;
    QString tlvData;

    tlvData = parseField->text();

    re.setPattern(hexWithSpaces);
    match = re.match(tlvData);
    if (match.hasMatch()) {
        tlvData = match.captured(0).replace(QRegularExpression("\\s"), "");
    } else {
        QMessageBox::information(this, "Wrong input data.", "Allowed formats:\nC1 01 01\nC10101\nNo spaces allowed at start/end");
        return;
    }
    TlvParser parser(QByteArray::fromHex(tlvData.toUtf8()));
    parsedField->clear();
    if (parser.parseToQtTree(parsedField, nullptr)) {
        QMessageBox::information(this, "Error", "Parse failed!");
    }
}