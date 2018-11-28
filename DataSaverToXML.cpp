#include "DataSaverToXML.h"

ErrCodeWrite DataSaverToXML::saveData(const std::string& data)const
{
    ErrCodeWrite err = WRITE_OK;
    size_t nDataSize = data.size();
    if(nDataSize > 0)
    {
        FILE *pFile = fopen(m_fileName.data(), "w");
        if(nullptr != pFile)
        {
            const char* pDataToWrite = &data[0];
            size_t wSize = fwrite(pDataToWrite, sizeof(char), nDataSize, pFile);
            //writing data by portions
            while(wSize < nDataSize)
            {
                wSize += fwrite(pDataToWrite + wSize, sizeof(char), nDataSize - wSize, pFile);
            }
            fclose(pFile);
        }
        else
        {
            err = WRITE_FAILED;
        }
    }
    else
    {
        err = NO_DATA_TO_SAVE;
    }
    return err;
}

 void DataSaverToXML::setFileName(std::string fileName)
 {
     m_fileName = std::move(fileName);
 }
