#ifndef DEFINITIONS_H
#define DEFINITIONS_H

struct Interval
{
    int m_nBeg;
    int m_nEnd;
};

enum ErrCode {READ_OK, READ_FAILED, FILE_NOT_EXIST, FILE_NO_ACCESS, WRITE_OK, WRITE_FAILED, BAD_ALLOC, NO_DATA_TO_SAVE};

#endif // DEFINITIONS_H

