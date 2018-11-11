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
    DataReaderFromXML(std::string fileName);
    virtual ~DataReaderFromXML() override;

    virtual ErrCode readData() override;
    virtual void parseData() override;

};

#endif // DATAREADERFROMXML_H
