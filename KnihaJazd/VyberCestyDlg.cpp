#include "stdafx.h"
#include "stdlib.h"
#include "KnihaJazd.h"
#include "VyberCestyDlg.h"
#include "CestaRecordset.h"
#include "CestaDlg.h"

IMPLEMENT_DYNAMIC(CVyberCestyDlg, CDialog)

CVyberCestyDlg::CVyberCestyDlg(CWnd* pParent)
	: CDialog(CVyberCestyDlg::IDD, pParent)
{
	m_VybratyDatum.SetDateTime(0, 0, 0, 0, 0, 0);
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
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CESTA, &CVyberCestyDlg::OnLvnItemChangedListCesty)
    ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST_CESTA, &CVyberCestyDlg::OnLvnItemActivateListCesty)
	ON_BN_CLICKED(IDC_BTNPRIDAJ, &CVyberCestyDlg::OnBnClickedBtnpridaj)
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

    // Data
    CCestaRecordset rs(theApp.GetDB());
	rs.SetSQLNacitanieZoznamuCiest(m_IdAuta);
    rs.Open();
    while (!rs.IsEOF())
    {
		CString transf;

		COleDateTime datum = rs.m_CDatum;
		transf = datum.Format(_T("%d.%m.%Y"));
		int iItem = m_ZoznamCiest.InsertItem(m_ZoznamCiest.GetItemCount(), transf);

		SYSTEMTIME systmDatum;
		datum.GetAsSystemTime(systmDatum);
		time_t tmDatum = CTime(systmDatum).GetTime();
		m_ZoznamCiest.SetItemData(iItem, (long)tmDatum);

		//
		long lDatum = (long)m_ZoznamCiest.GetItemData(iItem);
		COleDateTime oleDatum(lDatum);
		//

		m_ZoznamCiest.SetItem(iItem, 1, LVIF_TEXT, rs.m_CCiel, 0, 0, 0, NULL);
		transf.Format(_T("%.0f"), rs.m_CPocStav);
		m_ZoznamCiest.SetItem(iItem, 2, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%.0f"), rs.m_CKonStav);
		m_ZoznamCiest.SetItem(iItem, 3, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%.0f"), rs.m_CPocetKm);
		m_ZoznamCiest.SetItem(iItem, 4, LVIF_TEXT, transf, 0, 0, 0, NULL);
		transf.Format(_T("%.0f"), rs.m_CTankovane);
		m_ZoznamCiest.SetItem(iItem, 5, LVIF_TEXT, transf, 0, 0, 0, NULL);
		m_Spolu = rs.m_COstatne + rs.m_CStravne + m_KmSadzba;	
		transf.Format(_T("%.2f"), m_Spolu);
		m_ZoznamCiest.SetItem(iItem, 6, LVIF_TEXT, transf, 0, 0, 0, NULL);

		rs.MoveNext();
	}
    rs.Close();

    AktualizujOkno();
    return TRUE;
}

void CVyberCestyDlg::SetParams(long idAuto, double kmSadzba)
{
	m_IdAuta = idAuto;
	m_KmSadzba = kmSadzba;
}

void CVyberCestyDlg::OnZobraz()	//dorobit
{
	CString pomStr;

    int item = m_ZoznamCiest.GetSelectionMark();
    if (item != -1)
    {
		pomStr = m_ZoznamCiest.GetItemText(item,0);
//		pomStr.Format("%0d.%0d. %4d", m_VybratyDatum.GetDay(), m_VybratyDatum.GetMonth(), m_VybratyDatum.GetYear());
	    CDialog::OnOK();
    }
}

void CVyberCestyDlg::AktualizujOkno()
{
}

void CVyberCestyDlg::OnLvnItemChangedListCesty(NMHDR *pNMHDR, LRESULT *pResult)
{
    AktualizujOkno();
    *pResult = 0;
}

void CVyberCestyDlg::OnLvnItemActivateListCesty(NMHDR *pNMHDR, LRESULT *pResult)
{
    OnOK();
    *pResult = 0;
}

void CVyberCestyDlg::OnBnClickedBtnpridaj()
{
	CCestaDlg dlg(this);
    dlg.DoModal();
}
