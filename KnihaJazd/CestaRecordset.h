#pragma once

class CCestaRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CCestaRecordset)

public:
	long m_AId;
	COleDateTime m_CDatum;
	CString m_CCiel;
	CString m_CUcel;
	double m_CPocetKm;
	double m_CPocStav;
	double m_CKonStav;
	double m_CTankovane;
	double m_CStravne;
	double m_COstatne;

	long m_AIdParam;
	COleDateTime m_CDatumParam;

public:
	CCestaRecordset(CDatabase* pDatabase = NULL);

	virtual CString GetDefaultSQL();
	virtual void DoFieldExchange(CFieldExchange* pFX);

    void SetSQLNacitanieZoznamuCiest();
    void SetSQLNacitanieKonkretnejCesty(long aIdParam, COleDateTime Datum);
    void SetSQLNacitanieMaximalnehoDatumu(long aIdParam, COleDateTime Datum);

protected:
    CString m_strSQL;
};
