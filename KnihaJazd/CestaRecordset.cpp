#include "stdafx.h"
#include "CestaRecordset.h"

IMPLEMENT_DYNAMIC(CCestaRecordset, CRecordset)

CCestaRecordset::CCestaRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CDatum = COleDateTime(0, 0 ,0 ,0, 0, 0);
	m_AId = 0;
	m_CCiel = "";
	m_CUcel = "";
	m_CPocetKm = 0.0;
	m_CPocStav = 0.0;
	m_CKonStav = 0.0;
	m_CTankovane = 0.0;
	m_CStravne = 0.0;
	m_COstatne = 0.0;

	m_nDefaultType = dynaset;
}

CString CCestaRecordset::GetDefaultSQL()
{
	return m_strSQL;
}

void CCestaRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Date(pFX, _T("[c_datum]"), m_CDatum);
	if (m_TypSQL != ETS_NACITANIE_MAXIMALNEHO_DATUMU)
    {
		RFX_Long(pFX, _T("[a_id]"), m_AId);
		RFX_Text(pFX, _T("[c_ciel]"), m_CCiel);
		RFX_Text(pFX, _T("[c_ucel]"), m_CUcel);
		RFX_Double(pFX, _T("[c_pocet_km]"), m_CPocetKm);
		RFX_Double(pFX, _T("[c_poc_stav]"), m_CPocStav);
		RFX_Double(pFX, _T("[c_kon_stav]"), m_CKonStav);
		RFX_Double(pFX, _T("[c_tankovane]"), m_CTankovane);
		RFX_Double(pFX, _T("[c_stravne]"), m_CStravne);
		RFX_Double(pFX, _T("[c_ostatne]"), m_COstatne);
    }

	if (m_TypSQL != ETS_NACITANIE_MAXIMALNEHO_DATUMU)
    {
        pFX->SetFieldType(CFieldExchange::inputParam);
        RFX_Long(pFX, _T("[a_id]"), m_AIdParam);
		if (m_TypSQL == ETS_NACITANIE_KONKRETNEJ_CESTY)
		{
			RFX_Date(pFX, _T("[c_datum]"), m_CDatumParam);
		}
    }
}

void CCestaRecordset::SetSQLNacitanieZoznamuCiest(long aIdParam)
{
	m_TypSQL = ETS_NACITANIE_ZOZNAMU_CIES;

    m_strSQL = _T("SELECT * FROM [cesta]");
    m_strFilter = _T("[a_id] = ?");
	m_strSort = _T("[c_datum]");

	m_AIdParam = aIdParam;

    m_nFields = 10;
    m_nParams = 1;
}

void CCestaRecordset::SetSQLNacitanieKonkretnejCesty(long aIdParam, COleDateTime cDatumParam)
{
	m_TypSQL = ETS_NACITANIE_KONKRETNEJ_CESTY;
    
	m_strSQL = _T("SELECT * FROM [cesta]");
    m_strFilter = _T("[a_id] = ? AND [c_datum] = ?");
    m_strSort = _T("");
							
    m_AIdParam = aIdParam;
	m_CDatumParam = cDatumParam;

    m_nFields = 10;
    m_nParams = 2;
}

void CCestaRecordset::SetSQLNacitanieMaximalnehoDatumu(long aIdParam)
{
	m_TypSQL = ETS_NACITANIE_MAXIMALNEHO_DATUMU;
    
	m_strSQL = _T("SELECT MAX([c_datum]) FROM [cesta]");
    m_strFilter = _T("[a_id] = ?");
    m_strSort = _T("");

	m_AIdParam = aIdParam;

    m_nFields = 1;
    m_nParams = 1;
}
