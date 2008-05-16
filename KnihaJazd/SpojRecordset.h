#pragma once

class CSpojRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CSpojRecordset)

public:
	long	m_AId;
	long	m_SRok;
	long	m_FId;
	double	m_SKmSadzba;
	double	m_SPriemernaSpotreba;

public:
	CSpojRecordset(CDatabase* pDatabase = NULL);

	virtual CString GetDefaultSQL();
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
};


