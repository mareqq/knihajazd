#include "stdafx.h"
#include "KnihaJazd.h"
#include "CestaDlg.h"
#include "CestaRecordset.h"

IMPLEMENT_DYNAMIC(CCestaDlg, CDialog)

CCestaDlg::CCestaDlg(CWnd* pParent)
	: CDialog(CCestaDlg::IDD, pParent)
    , m_rsCesta(theApp.GetDB())
    , m_Datum(0,0,0,0,0,0)
	, m_Ciel("")
	, m_Ucel("")
	, m_PocetKm(0)
	, m_PocStav(0)
	, m_KonStav(0)
	, m_Tankovane(0)
	, m_Stravne(0)
	, m_Ostatne(0)
{
    m_IdAuta = 0;
	m_Spolu = 0;
	m_KmSadzba = 0;
}

CCestaDlg::~CCestaDlg()
{
    m_rsCesta.Close();
}

void CCestaDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER, m_Datum);
    DDX_Text(pDX, IDC_EDIT_CIEL, m_Ciel);
	DDX_Text(pDX, IDC_EDIT_UCEL, m_Ucel);
    DDX_Text(pDX, IDC_EDIT_POCETKM, m_PocetKm);
	DDX_Text(pDX, IDC_EDIT_POCSTAV, m_PocStav);
	DDX_Text(pDX, IDC_EDIT_KONSTAV, m_KonStav);
	DDX_Text(pDX, IDC_EDIT_TANKOVANE, m_Tankovane);
	DDX_Text(pDX, IDC_EDIT_STRAVNE, m_Stravne);
	DDX_Text(pDX, IDC_EDIT_OSTATNE, m_Ostatne);
	DDX_Control(pDX, IDC_EDIT_SPOLU, m_SpoluCtrl);
}

BEGIN_MESSAGE_MAP(CCestaDlg, CDialog)
END_MESSAGE_MAP()

BOOL CCestaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    m_rsCesta.SetSQLNacitanieKonkretnejCesty(m_IdAuta, m_Datum);
    m_rsCesta.Open();

    if (m_Datum != 0)
    {
        // Ak editujeme firmu
        m_Datum = m_rsCesta.m_CDatum;
        m_Ciel = m_rsCesta.m_CCiel;
        m_Ucel = m_rsCesta.m_CUcel;
        m_PocetKm = m_rsCesta.m_CPocetKm;
        m_PocStav = m_rsCesta.m_CPocStav;
		m_Tankovane = m_rsCesta.m_CTankovane;
		m_Stravne = m_rsCesta.m_CStravne;
		m_Ostatne = m_rsCesta.m_COstatne;
		m_Spolu = m_Stravne + m_Ostatne + m_PocetKm*m_KmSadzba;
    }

    UpdateData(FALSE);
    return TRUE;
}

void CCestaDlg::SetParamsA(int idAuta)
{
    m_IdAuta = idAuta;
}

void CCestaDlg::SetParamsD(COleDateTime Datum)
{
	m_Datum = Datum;
}

void CCestaDlg::SetParamsKS(float KmSadzba)
{
    m_KmSadzba = KmSadzba;
}

void CCestaDlg::OnOK()
{
	COleDateTime pomDatum;
	pomDatum.SetDate(0,0,1);

    UpdateData(TRUE);

    if (m_Datum == 0)
    {
        // Zistime maximalny datum u a nastavime o jeden viac
        CCestaRecordset rs(theApp.GetDB());
        rs.SetSQLNacitanieMaximalnehoDatumu(m_IdAuta, m_Datum);
        rs.Open();
//        m_Datum = rs.m_CDatum + 1;
        COleDateTimeSpan m_Datum = m_Datum + pomDatum;

		rs.Close();

        // Pridavame firmu
        m_rsCesta.AddNew();
        m_rsCesta.m_AId = m_IdAuta;

    }
    else
    {
        // Menime povodnu firmu
        m_rsCesta.Edit();
    }

    m_rsCesta.m_CDatum = m_Datum;
    m_rsCesta.m_CCiel = m_Ciel;
    m_rsCesta.m_CUcel = m_Ucel;
    m_rsCesta.m_CPocetKm = m_PocetKm;
    m_PocStav = m_rsCesta.m_CPocStav;
	m_rsCesta.m_CTankovane = m_Tankovane;
	m_rsCesta.m_CStravne = m_Stravne;
	m_rsCesta.m_COstatne = m_Ostatne;

    m_rsCesta.Update();

    CDialog::OnOK();
}
