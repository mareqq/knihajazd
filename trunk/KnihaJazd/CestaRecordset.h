#pragma once

class CCestaRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CCestaRecordset)

public:
	COleDateTime m_CDatum;
	long m_AId;
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

    void SetSQLNacitanieZoznamuCiest(long aIdParam);
    void SetSQLNacitanieKonkretnejCesty(long aIdParam, COleDateTime cDatumParam);
    void SetSQLNacitanieMaximalnehoDatumu(long aIdParam);

protected:
    CString m_strSQL;

	enum ETypSQL
	{
		ETS_NACITANIE_ZOZNAMU_CIES,
		ETS_NACITANIE_KONKRETNEJ_CESTY,
		ETS_NACITANIE_MAXIMALNEHO_DATUMU
	} m_TypSQL;
};
