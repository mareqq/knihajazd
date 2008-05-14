#include "stdafx.h"
#include "KnihaJazd.h"
#include "VyberFirmyDlg.h"
#include "FirmaRecordset.h"

IMPLEMENT_DYNAMIC(CVyberFirmyDlg, CDialog)

CVyberFirmyDlg::CVyberFirmyDlg(CWnd* pParent)
	: CDialog(CVyberFirmyDlg::IDD, pParent)
{
}

CVyberFirmyDlg::~CVyberFirmyDlg()
{
}

void CVyberFirmyDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_FIRMY, CVyberFirmyDlg::m_ZoznamFiriem);
}

BEGIN_MESSAGE_MAP(CVyberFirmyDlg, CDialog)
END_MESSAGE_MAP()

BOOL CVyberFirmyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    // Zoznam firiem
    m_ZoznamFiriem.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamFiriem.InsertColumn(0, _T("Názov"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(1, _T("Ulica"), LVCFMT_LEFT, 200);
    m_ZoznamFiriem.InsertColumn(1, _T("Cislo"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(1, _T("Mesto"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(1, _T("PSÈ"), LVCFMT_LEFT, 100);

    // Data
    CFirmaRecordset rs(theApp.GetDB());
    rs.Open();
    while (!rs.IsEOF())
    {
        int iItem = m_ZoznamFiriem.InsertItem(m_ZoznamFiriem.GetItemCount(), rs.m_FNazov);
        m_ZoznamFiriem.SetItemData(iItem, rs.m_FId);
        m_ZoznamFiriem.SetItem(iItem, 1, LVIF_TEXT, rs.m_FUlica, 0, 0, 0, NULL);
        m_ZoznamFiriem.SetItem(iItem, 2, LVIF_TEXT, rs.m_FCislo, 0, 0, 0, NULL);
        m_ZoznamFiriem.SetItem(iItem, 3, LVIF_TEXT, rs.m_FMesto, 0, 0, 0, NULL);
        m_ZoznamFiriem.SetItem(iItem, 4, LVIF_TEXT, rs.m_FPsc, 0, 0, 0, NULL);

        rs.MoveNext();
    }
    rs.Close();

    return TRUE;  // return TRUE  unless you set the focus to a control
}
