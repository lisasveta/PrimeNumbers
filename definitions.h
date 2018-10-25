#pragma once
struct Interval
{
	int m_nBeg;
	int m_nEnd;
};

enum FileError {WRITE_OK, READ_OK, FILE_NOT_EXIST, FILE_IS_EMPTY};