#include "stdafx.h"
#include "stdlib.h"
#include "KnihaJazd.h"
#include "VyberCestyDlg.h"
#include "CestaRecordset.h"

IMPLEMENT_DYNAMIC(CVyberCestyDlg, CDialog)

CVyberCestyDlg::CVyberCestyDlg(CWnd* pParent)
	: CDialog(CVyberCestyDlg::IDD, pParent)
{
}

CVyberCestyDlg::~CVyberCestyDlg()
{
}

void CVyberCestyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CESTA, CVyberCestyDlg::m_ZoznamCiest);
}

BEGIN_MESSAGE_MAP(CVyberCestyDlg, CDialog)
END_MESSAGE_MAP()

BOOL CVyberCestyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    // Zoznam ciest
    m_ZoznamCiest.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamCiest.InsertColumn(0, _T("Dátum"), LVCFMT_LEFT, 75);
    m_ZoznamCiest.InsertColumn(1, _T("Miesto jednania"), LVCFMT_LEFT, 150);
	m_ZoznamCiest.InsertColumn(2, _T("Poèiatok"), LVCFMT_LEFT, 100);
	m_ZoznamCiest.InsertColumn(3, _T("Koniec"), LVCFMT_LEFT, 100);
    m_ZoznamCiest.InsertColumn(4, _T("Km"), LVCFMT_LEFT, 50);
	m_ZoznamCiest.InsertColumn(5, _T("Tankované"), LVCFMT_LEFT, 75);
	m_ZoznamCiest.InsertColumn(6, _T("Suma (Sk)"), LVCFMT_LEFT, 75);

/*    // Data
    CCestaRecordset rs(theApp.GetDB());
    rs.Open();
    while (!rs.IsEOF())
    {
		if (rs.m_AId == )
        int iItem = m_ZoznamCiest.InsertItem(m_ZoznamCiest.GetItemCount(), rs.m_CCiel);
        m_ZoznamCiest.SetItemData(iItem, rs.m_AId);
		m_ZoznamCiest.SetItemData(iItem, rs.m_SRok);
		transf.Format(_T("%f"), rs.m_CPocStav);
        m_ZoznamCiest.SetItem(iItem, 1, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%f"), rs.m_CKonStav);
        m_ZoznamCiest.SetItem(iItem, 2, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%f"), rs.m_CPocetKm);
		m_ZoznamCiest.SetItem(iItem, 3, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%f"), rs.m_CTankovane);
		m_ZoznamCiest.SetItem(iItem, 4, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%f"), (rs.m_COstatne+rs.m_CStravne));//
		m_ZoznamCiest.SetItem(iItem, 5, LVIF_TEXT, transf, 0, 0, 0, NULL);
        
        rs.MoveNext();
    }
    rs.Close();*/

    return TRUE; 
}
