#ifndef DEFINITIONS_H
#define DEFINITIONS_H

struct Interval
{
    int m_nBeg;
    int m_nEnd;
};

enum DataSource {XML_FILE};
enum ErrCodeRead {READ_OK, READ_FAILED, FILE_NOT_EXIST, FILE_NO_ACCESS, BAD_ALLOC_READ};
enum ErrCodeWrite {WRITE_OK, WRITE_FAILED, NO_DATA_TO_SAVE};

#endif // DEFINITIONS_H

