#include "stdafx.h"
#include "FirmaRecordset.h"

IMPLEMENT_DYNAMIC(CFirmaRecordset, CRecordset)

CFirmaRecordset::CFirmaRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_FId = 0;
	m_FNazov = L"";
	m_FUlica = L"";
	m_FCislo = L"";
	m_FMesto = L"";
	m_FPsc = L"";

    m_nDefaultType = dynaset;

    SetSQLNacitanieZoznamuFiriem();
}

CString CFirmaRecordset::GetDefaultSQL()
{
	return m_strSQL;
}

void CFirmaRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[f_id]"), m_FId);
    if (m_nFields > 1)
    {
	    RFX_Text(pFX, _T("[f_nazov]"), m_FNazov);
	    RFX_Text(pFX, _T("[f_ulica]"), m_FUlica);
	    RFX_Text(pFX, _T("[f_cislo]"), m_FCislo);
	    RFX_Text(pFX, _T("[f_mesto]"), m_FMesto);
	    RFX_Text(pFX, _T("[f_psc]"), m_FPsc);
    }

    if (m_nParams > 0)
    {
        pFX->SetFieldType(CFieldExchange::inputParam);
        RFX_Long(pFX, _T("[f_id]"), m_FIdParam);
    }
}

void CFirmaRecordset::SetSQLNacitanieZoznamuFiriem()
{
    m_strSQL = _T("SELECT * FROM [firma]");
    m_strFilter = _T("");
    m_strSort = _T("[f_nazov], [f_mesto], [f_psc], [f_ulica], [f_cislo]");

    m_nFields = 6;
    m_nParams = 0;
}

void CFirmaRecordset::SetSQLNacitanieKonkretnejFirmy(long fIdParam)
{
    m_strSQL = _T("SELECT * FROM [firma]");
    m_strFilter = _T("[f_id] = ?");
    m_strSort = _T("");

    m_FIdParam = fIdParam;

    m_nFields = 6;
    m_nParams = 1;
}

void CFirmaRecordset::SetSQLNacitanieMaximalnehoId()
{
    m_strSQL = _T("SELECT MAX([f_id]) FROM [firma]");
    m_strFilter = _T("");
    m_strSort = _T("");

    m_nFields = 1;
    m_nParams = 0;
}
