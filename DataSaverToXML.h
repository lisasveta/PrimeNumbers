#ifndef DATASAVERTOXML_H
#define DATASAVERTOXML_H
#include "DataSaver.h"

class DataSaverToXML : public DataSaver
{
    std::string m_fileName;

public:
    DataSaverToXML(std::string fileName);
    virtual ~DataSaverToXML() override;
    virtual ErrCode saveData(const std::string data)const override;
};

#endif // DATASAVERTOXML_H
