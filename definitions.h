#pragma once

struct Interval
{
	int m_nBeg;
	int m_nEnd;
};

enum ErrCode {WRITE_OK, WRITE_FAILED, READ_OK, READ_FILED, FILE_NOT_EXIST, FILE_IS_EMPTY, FILE_NO_ACCESS, MEM_BAD_ALLOC};
