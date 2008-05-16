#include "stdafx.h"
#include "CestaRecordset.h"

IMPLEMENT_DYNAMIC(CCestaRecordset, CRecordset)

CCestaRecordset::CCestaRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_AId = 0;
	m_SRok = 0;
	m_CCiel = L"";
	m_CUcel = L"";
	m_CPocetKm = 0.0;
	m_CPocStav = 0.0;
	m_CKonStav = 0.0;
	m_CTankovane = 0.0;
	m_CStravne = 0.0;
	m_COstatne = 0.0;

	m_nFields = 11;
	m_nDefaultType = dynaset;
}

CString CCestaRecordset::GetDefaultSQL()
{
	return _T("[cesta]");
}

void CCestaRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

    // Macros such as RFX_Text() and RFX_Int() are dependent on the
    // type of the member variable, not the type of the field in the database.
    // ODBC will try to automatically convert the column value to the requested type
    RFX_Long(pFX, _T("[a_id]"), m_AId);
	RFX_Long(pFX, _T("[s_rok]"), m_SRok);
	RFX_Text(pFX, _T("[c_ciel]"), m_CCiel);
	RFX_Text(pFX, _T("[c_ucel]"), m_CUcel);
	RFX_Double(pFX, _T("[c_pocet_km]"), m_CPocetKm);
	RFX_Double(pFX, _T("[c_poc_stav]"), m_CPocStav);
	RFX_Double(pFX, _T("[c_kon_stav]"), m_CKonStav);
	RFX_Double(pFX, _T("[c_tankovane]"), m_CTankovane);
	RFX_Double(pFX, _T("[c_stravne]"), m_CStravne);
	RFX_Double(pFX, _T("[c_ostatne]"), m_COstatne);

}
