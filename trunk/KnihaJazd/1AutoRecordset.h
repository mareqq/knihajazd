#pragma once

class CAuto1Recordset : public CRecordset
{
	DECLARE_DYNAMIC(CAuto1Recordset)

public:
	long		m_AId;
	CStringA	m_ATyp;
	CStringA	m_ASpz;

public:
	CAuto1Recordset(CDatabase* pDatabase);

	virtual CString GetDefaultSQL(); 
	virtual void DoFieldExchange(CFieldExchange* pFX);	
};
