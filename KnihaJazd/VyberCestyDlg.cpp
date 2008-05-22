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
	m_VybratyDatum.SetDateTime(0,0,0,0,0,0);
}

CVyberCestyDlg::~CVyberCestyDlg()
{
}

void CVyberCestyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CESTA, CVyberCestyDlg::m_ZoznamCiest);
    DDX_Control(pDX, IDOK, m_TlacidloOk);
}

BEGIN_MESSAGE_MAP(CVyberCestyDlg, CDialog)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CESTA, &CVyberCestyDlg::OnLvnItemChangedListCesty)
    ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST_CESTA, &CVyberCestyDlg::OnLvnItemActivateListCesty)
	ON_BN_CLICKED(IDC_BTNPRIDAJ, &CVyberCestyDlg::OnBnClickedBtnpridaj)
END_MESSAGE_MAP()

BOOL CVyberCestyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString transf;
	int den, mesiac, rok;
	COleDateTime datum;

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
    rs.Open();

    while (!rs.IsEOF())
    {
//		if (rs.m_AId == m_IdAuta)
		{	
//			str.Format("%0d.%0d.%4d", datum.GetDay(), datum.GetMonth(), datum.GetYear());
//			transf = datum.Format(_T("%d.%m. %Y"));
			datum = rs.m_CDatum;
			den = datum.GetDay();
			mesiac = datum.GetMonth();
			rok = datum.GetYear();
//			transf.Construct();
			int iItem = m_ZoznamCiest.InsertItem(m_ZoznamCiest.GetItemCount(), transf);
			m_ZoznamCiest.SetItemData(iItem, rs.m_AId);
			m_ZoznamCiest.SetItem(iItem, 1, LVIF_TEXT, rs.m_CCiel, 0, 0, 0, NULL);
			transf.Format(_T("%d"), rs.m_CPocStav);
			m_ZoznamCiest.SetItem(iItem, 2, LVIF_TEXT, transf, 0, 0, 0, NULL);
			transf.Format(_T("%d"), rs.m_CKonStav);
			m_ZoznamCiest.SetItem(iItem, 3, LVIF_TEXT, transf, 0, 0, 0, NULL);
			transf.Format(_T("%d"), rs.m_CPocetKm);
			m_ZoznamCiest.SetItem(iItem, 4, LVIF_TEXT, transf, 0, 0, 0, NULL);
			transf.Format(_T("%d"), rs.m_CTankovane);
			m_ZoznamCiest.SetItem(iItem, 5, LVIF_TEXT, transf, 0, 0, 0, NULL);
			m_Spolu = rs.m_COstatne + rs.m_CStravne + m_KmSadzba;	
			transf.Format(_T("%d"), m_Spolu);
			m_ZoznamCiest.SetItem(iItem, 6, LVIF_TEXT, transf, 0, 0, 0, NULL);
		}
        rs.MoveNext();
	}
    rs.Close();

    AktualizujOkno();
    return TRUE;
}

void CVyberCestyDlg::SetKmSadzba(double KmSadzba)
{
	m_KmSadzba = KmSadzba;
}

void CVyberCestyDlg::OnOK()	//dorobit
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
    int item = m_ZoznamCiest.GetSelectionMark();
    m_TlacidloOk.EnableWindow(item != -1);
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
