#pragma once
struct Interval
{
	int m_nBeg;
	int m_nEnd;
};

enum ErrCode {m_eWRITE_OK, m_eWRITE_FAILED, m_eREAD_OK, m_eREAD_FILED, m_eFILE_NOT_EXIST, m_eFILE_IS_EMPTY, m_eFILE_NO_ACCESS, m_eMEM_BAD_ALLOC};
