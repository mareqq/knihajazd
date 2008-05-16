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
	ON_BN_CLICKED(IDOK, &CVyberFirmyDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CVyberFirmyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    // Zoznam firiem
    m_ZoznamFiriem.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamFiriem.InsertColumn(0, _T("N·zov"), LVCFMT_LEFT, 110);
    m_ZoznamFiriem.InsertColumn(1, _T("Ulica"), LVCFMT_LEFT, 110);
    m_ZoznamFiriem.InsertColumn(2, _T("»Ìslo"), LVCFMT_LEFT, 65);
    m_ZoznamFiriem.InsertColumn(3, _T("Mesto"), LVCFMT_LEFT, 110);
    m_ZoznamFiriem.InsertColumn(4, _T("PS»"), LVCFMT_LEFT, 50);

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

void CVyberFirmyDlg::OnBnClickedOk()
{
	vyber = m_ZoznamFiriem.GetSelectionMark(); // ide od nuly
	id = (int)m_ZoznamFiriem.GetItemData(vyber);

	CFirmaRecordset rs(theApp.GetDB());
    rs.Open();
    while (!rs.IsEOF())
    {
		if (rs.m_FId == id)
			nazov = rs.m_FNazov;

        rs.MoveNext();
    }
    rs.Close();

//treba zmenit nazov firmy v knihajazddlg

	OnOK();
}
