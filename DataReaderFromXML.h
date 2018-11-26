#ifndef DATAREADERFROMXML_H
#define DATAREADERFROMXML_H
#include "definitions.h"
#include "DataReader.h"
#include <string>

class DataReaderFromXML: public DataReader
{
    std::string m_fileName;
    std::string m_DataFromFile;

public:
    virtual ErrCode readData() override;
    virtual void parseData() override;
    void setFileName(std::string fileName);
};

#endif // DATAREADERFROMXML_H
