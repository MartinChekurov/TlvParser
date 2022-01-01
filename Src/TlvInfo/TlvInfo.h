//
// Created by marti on 30.12.21 г..
//

#ifndef ASD_TLVINFO_H
#define ASD_TLVINFO_H

#include "QString"

class TlvInfo {

    QString tag;
    QString name;
    QString length;
    QString description;
    QString source;
    QString format;

public:
    TlvInfo();
    TlvInfo(QString* tag, QString* name, QString* length, QString* description, QString*  source, QString* format);

    QString* getTag();
    QString* getName();
    QString* getLength();
    QString* getDescription();
    QString* getSource();
    QString* getFormat();
};

unsigned int tlvInfoGetFromFile(uint tag, TlvInfo* tlv);

#endif //ASD_TLVINFO_H
