#include "stdafx.h"
#include "KnihaJazd.h"
#include "VyberAutaDlg.h"
#include "AutoRecordset.h"

IMPLEMENT_DYNAMIC(CVyberAutaDlg, CDialog)

CVyberAutaDlg::CVyberAutaDlg(CWnd* pParent)
	: CDialog(CVyberAutaDlg::IDD, pParent)
{
}

CVyberAutaDlg::~CVyberAutaDlg()
{
}

void CVyberAutaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_AUTA, CVyberAutaDlg::m_ZoznamAut);
}


BEGIN_MESSAGE_MAP(CVyberAutaDlg, CDialog)
END_MESSAGE_MAP()

BOOL CVyberAutaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    // Zoznam aut
    m_ZoznamAut.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamAut.InsertColumn(0, _T("Typ"), LVCFMT_LEFT, 300);
    m_ZoznamAut.InsertColumn(1, _T("SPZ"), LVCFMT_LEFT, 150);


    // Data
 /*   CAutoRecordset rs(theApp.GetDB());
    rs.Open();
    while (!rs.IsEOF())
    {
        int iItem = m_ZoznamAut.InsertItem(m_ZoznamAut.GetItemCount(), rs.m_ATyp);
        m_ZoznamFiriem.SetItemData(iItem, rs.m_AId);
        m_ZoznamFiriem.SetItem(iItem, 1, LVIF_TEXT, rs.mASpz, 0, 0, 0, NULL);

        rs.MoveNext();
    }
    rs.Close();*/

    return TRUE;
}