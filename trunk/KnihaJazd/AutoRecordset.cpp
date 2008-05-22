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
	m_nFields = 7;

	m_nDefaultType = dynaset;

	SetSQLNacitanieZoznamuAut();
}

CString CAutoRecordset::GetDefaultSQL()
{
	return m_strSQL;
}

void CAutoRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[a_id]"), m_AId);
    if (m_nFields > 1)
    {
	    RFX_Long(pFX, _T("[a_rok]"), m_ARok);
	    RFX_Long(pFX, _T("[f_id]"), m_FId);
	    RFX_Double(pFX, _T("[a_km_sadzba]"), m_AKmSadzba);
		RFX_Double(pFX, _T("[a_priemerna_spotreba]"), m_APriemernaSpotreba);
	    RFX_Text(pFX, _T("[a_spz]"), m_ASpz);
		RFX_Text(pFX, _T("[a_typ]"), m_ATyp);
	}

    if (m_nParams > 0)
    {
        pFX->SetFieldType(CFieldExchange::inputParam);
        RFX_Long(pFX, _T("[a_id]"), m_AIdParam);
    }
}

void CAutoRecordset::SetSQLNacitanieZoznamuAut()
{
    m_strSQL = _T("SELECT * FROM [auto]");
	m_strFilter = _T("");
    m_strSort = _T("[a_spz], [a_typ], [a_km_sadzba], [a_priemerna_spotreba], [a_rok]");

    m_nFields = 7;
    m_nParams = 0;
}

void CAutoRecordset::SetSQLNacitanieKonkretnehoAuta(long aIdParam)
{
    m_strSQL = _T("SELECT * FROM [auto]");
	m_strFilter = _T("[a_id] = ?");
    m_strSort = _T("");
							
 	m_AIdParam = aIdParam;

    m_nFields = 7;
    m_nParams = 1;
}

void CAutoRecordset::SetSQLNacitanieMaximalnehoId()
{
    m_strSQL = _T("SELECT MAX([a_id]) FROM [auto]");
    m_strFilter = _T("");
    m_strSort = _T("");

    m_nFields = 1;
    m_nParams = 0;
}
