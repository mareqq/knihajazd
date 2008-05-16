#pragma once

class CFirmaRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CFirmaRecordset)

public:
	long	m_FId;
	CString m_FNazov;
	CString m_FUlica;
	CString m_FCislo;
	CString m_FMesto;
	CString m_FPsc;

public:
	CFirmaRecordset(CDatabase* pDatabase);

    virtual CString GetDefaultSQL();
	virtual void DoFieldExchange(CFieldExchange* pFX);
};
