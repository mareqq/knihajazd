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

    m_nFields = 6;
    m_nDefaultType = dynaset;
}

CString CFirmaRecordset::GetDefaultSQL()
{
	return _T("[firma]");
}

void CFirmaRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

    // Macros such as RFX_Text() and RFX_Int() are dependent on the
    // type of the member variable, not the type of the field in the database.
    // ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[f_id]"), m_FId);
	RFX_Text(pFX, _T("[f_nazov]"), m_FNazov);
	RFX_Text(pFX, _T("[f_ulica]"), m_FUlica);
	RFX_Text(pFX, _T("[f_cislo]"), m_FCislo);
	RFX_Text(pFX, _T("[f_mesto]"), m_FMesto);
	RFX_Text(pFX, _T("[f_psc]"), m_FPsc);
}
