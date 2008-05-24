#include "stdafx.h"
#include "AutoRecordset.h"

IMPLEMENT_DYNAMIC(CAutoRecordset, CRecordset)

CAutoRecordset::CAutoRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_AId = 0;
	m_ARok = 0;
	m_FId = 0;
	m_ATyp = "";
	m_ASpz = "";
	m_AKmSadzba = 0.0;
	m_APriemernaSpotreba = 0.0;

	m_nDefaultType = dynaset;
}

CString CAutoRecordset::GetDefaultSQL()
{
	return m_strSQL;
}

void CAutoRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	// Stlpce
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[a_id]"), m_AId);
	if (m_TypSQL != ETS_NACITANIE_MAXIMALNEHO_ID)
    {
	    RFX_Long(pFX, _T("[a_rok]"), m_ARok);
	    RFX_Long(pFX, _T("[f_id]"), m_FId);
	    RFX_Double(pFX, _T("[a_km_sadzba]"), m_AKmSadzba);
		RFX_Double(pFX, _T("[a_priemerna_spotreba]"), m_APriemernaSpotreba);
	    RFX_Text(pFX, _T("[a_spz]"), m_ASpz);
		RFX_Text(pFX, _T("[a_typ]"), m_ATyp);
	}

	// Parametre
	if (m_TypSQL == ETS_NACITANIE_ZOZNAMU_AUT)
	{
        pFX->SetFieldType(CFieldExchange::inputParam);
        RFX_Long(pFX, _T("[f_id]"), m_FIdParam);
	}
	else if (m_TypSQL == ETS_NACITANIE_KONKRETNETHO_AUTA)
    {
        pFX->SetFieldType(CFieldExchange::inputParam);
        RFX_Long(pFX, _T("[a_id]"), m_AIdParam);
    }
}

void CAutoRecordset::SetSQLNacitanieZoznamuAut(long fIdParam)
{
	m_TypSQL = ETS_NACITANIE_ZOZNAMU_AUT;

    m_strSQL = _T("SELECT * FROM [auto]");
	m_strFilter = _T("[f_id] = ?");
    m_strSort = _T("[a_spz]");

	m_FIdParam = fIdParam;

    m_nFields = 7;
    m_nParams = 1;
}

void CAutoRecordset::SetSQLNacitanieKonkretnehoAuta(long aIdParam)
{
	m_TypSQL = ETS_NACITANIE_KONKRETNETHO_AUTA;

    m_strSQL = _T("SELECT * FROM [auto]");
	m_strFilter = _T("[a_id] = ?");
    m_strSort = _T("");
							
 	m_AIdParam = aIdParam;

    m_nFields = 7;
    m_nParams = 1;
}

void CAutoRecordset::SetSQLNacitanieMaximalnehoId()
{
	m_TypSQL = ETS_NACITANIE_MAXIMALNEHO_ID;

    m_strSQL = _T("SELECT MAX([a_id]) FROM [auto]");
    m_strFilter = _T("");
    m_strSort = _T("");

    m_nFields = 1;
    m_nParams = 0;
}
