#pragma once

class CFirmaRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CFirmaRecordset)

public:
	long m_FId;
	CString m_FNazov;
	CString m_FUlica;
	CString m_FCislo;
	CString m_FMesto;
	CString m_FPsc;

    long m_FIdParam;

public:
	CFirmaRecordset(CDatabase* pDatabase);

    virtual CString GetDefaultSQL();
	virtual void DoFieldExchange(CFieldExchange* pFX);

    void SetSQLNacitanieZoznamuFiriem();
    void SetSQLNacitanieKonkretnejFirmy(long fIdParam);
    void SetSQLNacitanieMaximalnehoId();

protected:
    CString m_strSQL;

	enum ETypSQL
	{
		ETS_NACITANIE_ZOZNAMU_FIRIEM,
		ETS_NACITANIE_KONKRETNEJ_FIRMY,
		ETS_NACITANIE_MAXIMALNEHO_ID
	} m_TypSQL;
};
