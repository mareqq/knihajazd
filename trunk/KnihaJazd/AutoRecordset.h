#pragma once

class CAutoRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CAutoRecordset)

public:
	long		m_AId;
	CStringA	m_ATyp;
	CStringA	m_ASpz;

public:
	CAutoRecordset(CDatabase* pDatabase);

	virtual CString GetDefaultSQL(); 
	virtual void DoFieldExchange(CFieldExchange* pFX);	
};
