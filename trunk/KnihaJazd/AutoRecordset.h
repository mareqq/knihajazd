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
	long m_IdFirmy;

public:
	CAutoRecordset(CDatabase* pDatabase = NULL);

	virtual void DoFieldExchange(CFieldExchange* pFX);
	virtual CString GetDefaultSQL();
	
    void SetSQLNacitanieZoznamuAut();
    void SetSQLNacitanieKonkretnehoAuta(long aIdParam);
    void SetSQLNacitanieMaximalnehoId();

protected:
    CString m_strSQL;
};


