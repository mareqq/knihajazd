#pragma once

class CCestaRecordset : public CRecordset
{
public:
	CCestaRecordset(CDatabase* pDatabase = NULL);

	DECLARE_DYNAMIC(CCestaRecordset)

    // unsupported	m_c_datum;
	long m_AId;
	long m_SRok;
	COleDateTime m_CDatum;
	CString m_CCiel;
	CString m_CUcel;
	double m_CPocetKm;
	double m_CPocStav;
	double m_CKonStav;
	double m_CTankovane;
	double m_CStravne;
	double m_COstatne;

public:
	virtual CString GetDefaultSQL();
	virtual void DoFieldExchange(CFieldExchange* pFX);
};
