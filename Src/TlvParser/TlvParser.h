//
// Created by marti on 19.12.21 г..
//

#ifndef TEST_TLVPARSER_H
#define TEST_TLVPARSER_H

#include <QString>
#include <QTreeWidget>

class TlvParser {

private:
    const QByteArray data;

public:
    TlvParser(const QByteArray& data);
    ~TlvParser();

    unsigned int parseToQtTree(QTreeWidget* root, QTreeWidgetItem* child);
};

#endif //TEST_TLVPARSER_H
