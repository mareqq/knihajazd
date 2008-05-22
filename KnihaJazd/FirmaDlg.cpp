#include "stdafx.h"
#include "KnihaJazd.h"
#include "FirmaDlg.h"
#include "FirmaRecordset.h"

IMPLEMENT_DYNAMIC(CFirmaDlg, CDialog)

CFirmaDlg::CFirmaDlg(CWnd* pParent)
	: CDialog(CFirmaDlg::IDD, pParent)
    , m_rsFirma(theApp.GetDB())
    , m_Nazov(_T(""))
    , m_Ulica(_T(""))
    , m_Cislo(_T(""))
    , m_Psc(_T(""))
    , m_Mesto(_T(""))
{
    m_IdFirmy = 0;
}

CFirmaDlg::~CFirmaDlg()
{
    m_rsFirma.Close();
}

void CFirmaDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_NAZOV, m_Nazov);
    DDX_Text(pDX, IDC_EDIT_ULICA, m_Ulica);
    DDX_Text(pDX, IDC_EDIT_CISLO, m_Cislo);
    DDX_Text(pDX, IDC_EDIT_PSC, m_Psc);
    DDX_Text(pDX, IDC_EDIT_MESTO, m_Mesto);
}

BEGIN_MESSAGE_MAP(CFirmaDlg, CDialog)
END_MESSAGE_MAP()

BOOL CFirmaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    m_rsFirma.SetSQLNacitanieKonkretnejFirmy(m_IdFirmy);
    m_rsFirma.Open();

    if (m_IdFirmy != 0)
    {
        // Ak editujeme firmu
        m_Nazov = m_rsFirma.m_FNazov;
        m_Ulica = m_rsFirma.m_FUlica;
        m_Cislo = m_rsFirma.m_FCislo;
        m_Mesto = m_rsFirma.m_FMesto;
        m_Psc = m_rsFirma.m_FPsc;
    }

    UpdateData(FALSE);
    return TRUE;
}

void CFirmaDlg::SetParams(long idFirmy)
{
    m_IdFirmy = idFirmy;
}

void CFirmaDlg::OnOK()
{
    UpdateData(TRUE);

    if (m_IdFirmy == 0)
    {
        // Zistime maximalne id firmy a nastavime id novej firmy
        CFirmaRecordset rs(theApp.GetDB());
        rs.SetSQLNacitanieMaximalnehoId();
        rs.Open();
        m_IdFirmy = rs.m_FId + 1;
        rs.Close();

        // Pridavame firmu
        m_rsFirma.AddNew();
        m_rsFirma.m_FId = m_IdFirmy;

    }
    else
    {
        // Menime povodnu firmu
        m_rsFirma.Edit();
    }

    m_rsFirma.m_FNazov = m_Nazov;
    m_rsFirma.m_FUlica = m_Ulica;
    m_rsFirma.m_FCislo = m_Cislo;
    m_rsFirma.m_FMesto = m_Mesto;
    m_rsFirma.m_FPsc = m_Psc;
    m_rsFirma.Update();

    CDialog::OnOK();
}
