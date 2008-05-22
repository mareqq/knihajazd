#include "stdafx.h"
#include "KnihaJazd.h"
#include "VyberFirmyDlg.h"
#include "FirmaRecordset.h"

IMPLEMENT_DYNAMIC(CVyberFirmyDlg, CDialog)

CVyberFirmyDlg::CVyberFirmyDlg(CWnd* pParent)
	: CDialog(CVyberFirmyDlg::IDD, pParent)
{
    m_IdVybratejFirmy = 0;
}

CVyberFirmyDlg::~CVyberFirmyDlg()
{
}

void CVyberFirmyDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_FIRMY, CVyberFirmyDlg::m_ZoznamFiriem);
    DDX_Control(pDX, IDOK, m_TlacidloOk);
}

BEGIN_MESSAGE_MAP(CVyberFirmyDlg, CDialog)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_FIRMY, &CVyberFirmyDlg::OnLvnItemChangedListFirmy)
    ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST_FIRMY, &CVyberFirmyDlg::OnLvnItemActivateListFirmy)
END_MESSAGE_MAP()

BOOL CVyberFirmyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    // Zoznam firiem
    m_ZoznamFiriem.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamFiriem.InsertColumn(0, _T("N·zov"), LVCFMT_LEFT, 200);
    m_ZoznamFiriem.InsertColumn(1, _T("Ulica"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(2, _T("»Ìslo"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(3, _T("Mesto"), LVCFMT_LEFT, 100);
    m_ZoznamFiriem.InsertColumn(4, _T("PS»"), LVCFMT_LEFT, 100);

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

    AktualizujOkno();
    return TRUE;
}

void CVyberFirmyDlg::OnOK()
{
    int item = m_ZoznamFiriem.GetSelectionMark();
    if (item != -1)
    {
        m_IdVybratejFirmy = (int)m_ZoznamFiriem.GetItemData(item);
        CDialog::OnOK();
    }
}

void CVyberFirmyDlg::AktualizujOkno()
{
    int item = m_ZoznamFiriem.GetSelectionMark();
    m_TlacidloOk.EnableWindow(item != -1);
}

void CVyberFirmyDlg::OnLvnItemChangedListFirmy(NMHDR *pNMHDR, LRESULT *pResult)
{
    AktualizujOkno();
    *pResult = 0;
}

void CVyberFirmyDlg::OnLvnItemActivateListFirmy(NMHDR *pNMHDR, LRESULT *pResult)
{
    OnOK();
    *pResult = 0;
}
