//
// Created by marti on 30.12.21 г..
//
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "TlvInfo.h"
#include "QFile"
#include "QDebug"

TlvInfo::TlvInfo()
{

}

TlvInfo::TlvInfo(QString* tag, QString* name, QString *length, QString *description, QString *source, QString *format)
{
    if (tag) {
        this->tag = *tag;
    }
    if (name) {
        this->name = *name;
    }
    if (length) {
        this->length = *length;
    }
    if (description) {
        this->description = *description;
    }
    if (source) {
        this->source = *source;
    }
    if (format) {
        this->format = *format;
    }
}

QString *TlvInfo::getTag()
{
    return &tag;
}

QString *TlvInfo::getLength()
{
    return &length;
}

QString *TlvInfo::getDescription()
{
    return &description;
}

QString *TlvInfo::getSource()
{
    return &source;
}

QString *TlvInfo::getFormat()
{
    return &format;
}

QString *TlvInfo::getName()
{
    return &name;
}

static unsigned int tlvInfoReadFile(QByteArray* tlv)
{
    QFile file("tags.json");

    if (!tlv) {
        return 1;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 1;
    }
    *tlv = file.readAll();
    file.close();
    return 0;
}

unsigned int tlvInfoGetFromFile(uint searchTag, TlvInfo* tlv)
{
    QByteArray jsonBytes;
    QString fileTag, fileTagName, fileTagLength, fileTagDescription, fileTagSource, fileTagFormat;

    QJsonDocument jsonFile;
    QJsonObject rootObject;
    QJsonArray tagsArray;

    bool ok = false;
    unsigned int status = 0;
    unsigned int searchTagNum = 0, fileTagNum = 0;

    if (!tlv) {
        return 1;
    }
    status = tlvInfoReadFile(&jsonBytes);
    if (status) {
        return status;
    }
    jsonFile = QJsonDocument::fromJson(jsonBytes);
    if (jsonFile.isNull()) {
        return 1;
    }
    if (!jsonFile.isObject()) {
        return 1;
    }
    rootObject = jsonFile.object();
    if (rootObject.isEmpty()) {
        return 1;
    }
    tagsArray = rootObject["Tags"].toArray();
    foreach (const QJsonValue& value, tagsArray) {
        QJsonObject obj = value.toObject();
        fileTag = obj["Tag"].toString();
        if ((searchTagNum = fileTag.toUInt(&ok, 16)) && ok) {
            if (searchTagNum == searchTag) {
                fileTagLength = obj["Length (min)"].toString() + "-" + obj["Length (max)"].toString();
                fileTagDescription = obj["Description"].toString();
                fileTagSource = obj["Source"].toString();
                fileTagFormat = obj["Format"].toString();
                fileTagName = obj["Name"].toString();
                TlvInfo tlvInfo(&fileTag, &fileTagName, &fileTagLength, &fileTagDescription, &fileTagSource, &fileTagFormat);
                *tlv = tlvInfo;
                return 0;
            }
        }
    }
    return 1;
}
