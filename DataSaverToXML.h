#ifndef DATASAVERTOXML_H
#define DATASAVERTOXML_H
#include "BaseDataSaver.h"

class DataSaverToXML : public BaseDataSaver
{
    std::string m_fileName;

public:

    virtual ErrCodeWrite saveData(const std::string& data)const override;
    void setFileName(std::string fileName);
};

#endif // DATASAVERTOXML_H
