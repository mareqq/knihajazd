#include "stdafx.h"
#include "AutoRecordset.h"

IMPLEMENT_DYNAMIC(CAutoRecordset, CRecordset)

CAutoRecordset::CAutoRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_AId = 0;
	m_ATyp = L"";
	m_ASpz = L"";

	m_nFields = 3;
	m_nDefaultType = dynaset;
}

CString CAutoRecordset::GetDefaultSQL()
{
	return _T("[auto]");
}

void CAutoRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[a_id]"), m_AId);
	RFX_Text(pFX, _T("[a_typ]"), m_ATyp);
	RFX_Text(pFX, _T("[a_spz]"), m_ASpz);
}
