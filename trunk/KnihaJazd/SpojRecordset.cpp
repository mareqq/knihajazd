#include "stdafx.h"
#include "SpojRecordset.h"

IMPLEMENT_DYNAMIC(CSpojRecordset, CRecordset)

CSpojRecordset::CSpojRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_AId = 0;
	m_SRok = 0;
	m_FId = 0;
	m_SKmSadzba = 0.0;
	m_SPriemernaSpotreba = 0.0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

CString CSpojRecordset::GetDefaultSQL()
{
	return _T("[spoj]");
}

void CSpojRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[a_id]"), m_AId);
	RFX_Long(pFX, _T("[s_rok]"), m_SRok);
	RFX_Long(pFX, _T("[f_id]"), m_FId);
	RFX_Double(pFX, _T("[s_km_sadzba]"), m_SKmSadzba);
	RFX_Double(pFX, _T("[s_priemerna_spotreba]"), m_SPriemernaSpotreba);

}