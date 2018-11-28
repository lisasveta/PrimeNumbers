#ifndef DATAREADERFROMXML_H
#define DATAREADERFROMXML_H
#include "definitions.h"
#include "BaseDataReader.h"
#include <string>

class DataReaderFromXML: public BaseDataReader
{
    std::string m_fileName;
    std::string m_DataFromFile;

public:
    virtual ErrCodeRead readData() override;
    virtual void parseData() override;
    void setFileName(std::string fileName);
};

#endif // DATAREADERFROMXML_H
