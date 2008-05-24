#pragma once

class CAutoRecordset : public CRecordset
{
	DECLARE_DYNAMIC(CAutoRecordset)

public:
	long	m_AId;
	long	m_ARok;
	long	m_FId;
	CString	m_ATyp;
	CString	m_ASpz;
	double	m_AKmSadzba;
	double	m_APriemernaSpotreba;

	long m_AIdParam;
	long m_FIdParam;

public:
	CAutoRecordset(CDatabase* pDatabase = NULL);

	virtual void DoFieldExchange(CFieldExchange* pFX);
	virtual CString GetDefaultSQL();
	
    void SetSQLNacitanieZoznamuAut(long fIdParam);
    void SetSQLNacitanieKonkretnehoAuta(long aIdParam);
    void SetSQLNacitanieMaximalnehoId();

protected:
    CString m_strSQL;

	enum ETypSQL
	{
		ETS_NACITANIE_ZOZNAMU_AUT,
		ETS_NACITANIE_KONKRETNETHO_AUTA,
		ETS_NACITANIE_MAXIMALNEHO_ID
	} m_TypSQL;
};


