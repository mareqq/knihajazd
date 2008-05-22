#include "stdafx.h"
#include "KnihaJazd.h"
#include "AutoDlg.h"
#include "AutoRecordset.h"

IMPLEMENT_DYNAMIC(CAutoDlg, CDialog)

CAutoDlg::CAutoDlg(CWnd* pParent)
	: CDialog(CAutoDlg::IDD, pParent)
	, m_rsAuto(theApp.GetDB())
	, m_Spz(_T(""))
	, m_Typ(_T(""))
	, m_KmSadzba(0)
	, m_PriemernaSpotreba(0)
	, m_Rok(0)
{
	m_IdAuta = 0;
}

CAutoDlg::~CAutoDlg()
{
    m_rsAuto.Close();
}

void CAutoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

    DDX_Text(pDX, IDC_EDIT_SPZ, m_Spz);
    DDX_Text(pDX, IDC_EDIT_TYP, m_Typ);
    DDX_Text(pDX, IDC_EDIT_KMSADZBA, m_KmSadzba);
    DDX_Text(pDX, IDC_EDIT_PS, m_PriemernaSpotreba);
    DDX_Text(pDX, IDC_EDIT_ROK, m_Rok);
}


BEGIN_MESSAGE_MAP(CAutoDlg, CDialog)
END_MESSAGE_MAP()

BOOL CAutoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    m_rsAuto.SetSQLNacitanieKonkretnehoAuta(m_IdAuta);
    m_rsAuto.Open();

    if (m_IdAuta != 0)
    {
        // Ak editujeme auto
        m_Spz = m_rsAuto.m_ASpz;
        m_Typ = m_rsAuto.m_ATyp;
        m_KmSadzba = m_rsAuto.m_AKmSadzba;
        m_PriemernaSpotreba = m_rsAuto.m_APriemernaSpotreba;
        m_Rok = m_rsAuto.m_ARok;
    }

    UpdateData(FALSE);
    return TRUE;
}

void CAutoDlg::SetParamsF(int idFirmy)
{
    m_IdFirmy = idFirmy;
}

void CAutoDlg::SetParamsA(int idAuta)
{
    m_IdAuta = idAuta;
}

void CAutoDlg::OnOK()
{
    UpdateData(TRUE);

    if (m_IdAuta == 0)
    {
        // Zistime maximalne id auta a nastavime id noveho auta
        CAutoRecordset rs(theApp.GetDB());
        rs.SetSQLNacitanieMaximalnehoId();
        rs.Open();
        m_IdAuta = rs.m_AId + 1;
        rs.Close();

        // Pridavame auto
        m_rsAuto.AddNew();
        m_rsAuto.m_AId = m_IdAuta;
		m_rsAuto.m_FId = m_IdFirmy;

    }
    else
    {
        // Menime povodne auto
        m_rsAuto.Edit();
    }

	m_rsAuto.m_ASpz = m_Spz;
    m_rsAuto.m_ATyp = m_Typ;
    m_rsAuto.m_AKmSadzba = m_KmSadzba;
    m_rsAuto.m_APriemernaSpotreba = m_PriemernaSpotreba;
    m_rsAuto.m_ARok = m_Rok;

	m_rsAuto.Update();

	CDialog::OnOK();
}
