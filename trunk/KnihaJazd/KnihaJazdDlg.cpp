#include "stdafx.h"
#include "KnihaJazd.h"
#include "KnihaJazdDlg.h"
#include "VyberFirmyDlg.h"
#include "VyberAutaDlg.h"
#include "VyberCestyDlg.h"
#include "FirmaRecordset.h"
#include "AutoRecordset.h"
#include "CestaRecordset.h"
#include "FirmaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CKnihaJazdDlg::CKnihaJazdDlg(CWnd* pParent)
	: CDialog(CKnihaJazdDlg::IDD, pParent)
    , m_Firma(_T(""))
{
}

void CKnihaJazdDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATIC_FIRMA, m_Firma);
    DDX_Control(pDX, IDC_LIST_AUTA, m_ZoznamAut);
}

BEGIN_MESSAGE_MAP(CKnihaJazdDlg, CDialog)
    ON_COMMAND(ID_FIRMA_VYBER, &CKnihaJazdDlg::OnFirmaVyber)
    ON_COMMAND(ID_FIRMA_PRIDAJ, &CKnihaJazdDlg::OnFirmaPridaj)
    ON_COMMAND(ID_FIRMA_UPRAV, &CKnihaJazdDlg::OnFirmaUprav)
    ON_COMMAND(ID_FIRMA_ZMAZ, &CKnihaJazdDlg::OnFirmaZmaz)
	ON_COMMAND(ID_SUBOR_KONIEC, &CKnihaJazdDlg::OnKoniec)
	ON_BN_CLICKED(IDC_BtnVyberAuta, &CKnihaJazdDlg::OnBnClickedBtnvyberauta)
	ON_BN_CLICKED(IDC_BtnVyberCesty, &CKnihaJazdDlg::OnBnClickedBtnvybercesty)
END_MESSAGE_MAP()

BOOL CKnihaJazdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Menu
    m_Menu.LoadMenu(MAKEINTRESOURCE(IDR_HLAVNEMENU));
    SetMenu(&m_Menu);

    // Otvorime spojenie do DB
    try
    {
        if (!theApp.GetDB()->Open(_T("KnihaJazd"), FALSE, FALSE, _T("ODBC;"), FALSE))
        {
            // Ak sa nepotvrdi dialog pre pripojenie do DB, ukoncime aplikaciu
            EndDialog(IDCANCEL);
            return TRUE;
        }
    }
    catch (CException *pEx)
    {
        // Ak nastane chyba pripojenia do DB, zobrazime chybu a ukoncime aplikaciu
        pEx->ReportError();
        EndDialog(IDCANCEL);
        return TRUE;
    }

    // Zoznam aut
    m_ZoznamAut.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamAut.InsertColumn(0, _T("ŠPZ"), LVCFMT_LEFT, 100);
    m_ZoznamAut.InsertColumn(1, _T("Typ"), LVCFMT_LEFT, 200);

/*
    // Praca s DB
    // ==========

    // 1. Sposob
    // ---------
    // Podporuje INSERT, UPDATE, DELETE (SELECT nam tento sposob neumozni,
    // pretoze nevracia ziadne hodnoty)

    theApp.GetDB()->ExecuteSQL("INSERT INTO firma(f_id, f_meno) VALUES(?, ?)");

    // 2. Sposob
    // ---------
    // Podporuje iba SELECT

    CRecordset recordSet(theApp.GetDB());
    recordSet.Open(CRecordset::dynaset, _T("SELECT f_id, f_meno FROM firma"));
    while (!recordSet.IsEOF())
    {
        CDBVariant varId, varMeno;
        recordSet.GetFieldValue((short) 0, varId);
        recordSet.GetFieldValue((short) 1, varMeno);
        recordSet.MoveNext();
    }
    recordSet.Close();

    // 3. Sposob
    // ---------
    // Podporuje SELECT, INSERT, UPDATE, DELETE

    // Praca s tabulkou firma
    CFirmaRecordset rs(theApp.GetDB());
    // Zacatie prace s tabulkou
    rs.Open();

    // Nacitanie vsetkych riadkov
    while (!rs.IsEOF())
    {
        int iItem = m_ZoznamAut.InsertItem(m_ZoznamAut.GetItemCount(), rs.GetFIdStr());
        m_ZoznamAut.SetItemData(iItem, rs.m_f_id);
        m_ZoznamAut.SetItem(iItem, 1, LVIF_TEXT, rs.m_f_meno, 0, 0, 0, NULL);

        rs.MoveNext();
    }

    // Zmena prveho zaznamu
    rs.MoveFirst();
    rs.Edit();
    rs.m_f_meno = _T("Lenkay");
    rs.Update();

    // Pridanie zaznamu
    rs.AddNew();
    rs.m_f_id = 6;
    rs.m_f_meno = _T("Petka");
    rs.Update();

    // Zmazanie zaznamu
    rs.MoveLast();
    rs.Delete();

    // Ukoncim pracu s tabulkou
    rs.Close();




	NAPRIKLAD

	CFirmaRecordset rs(theApp.GetDB());

    rs.Open();
    rs.AddNew();
    rs.m_FId = 1;
    rs.m_FNazov = _T("Autoplyn, s.r.o");
	rs.m_FUlica = _T("Zádubnie");
	rs.m_FCislo = _T("91");
	rs.m_FMesto = _T("Žilina");
	rs.m_FPsc = _T("01003");
    rs.Update();

    rs.AddNew();
    rs.m_FId = 2;
    rs.m_FNazov = _T("Lenka Paverová");
	rs.m_FUlica = _T("Športovcov");
	rs.m_FCislo = _T("342/3");
	rs.m_FMesto = _T("Považská Bystrica");
	rs.m_FPsc = _T("01701");
    rs.Update();

    rs.Close();
*/

    // Nadpis firmy
    m_Firma = _T("Firma: ") + m_NazovFirmy;

    UpdateData(FALSE);
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKnihaJazdDlg::OnFirmaVyber()
{
    CVyberFirmyDlg dlg(this);
    dlg.DoModal();
}

void CKnihaJazdDlg::OnFirmaPridaj()
{
    CFirmaDlg dlg(this);
    dlg.DoModal();
}

void CKnihaJazdDlg::OnFirmaUprav()
{
   
}

void CKnihaJazdDlg::OnFirmaZmaz()
{
    
}

void CKnihaJazdDlg::OnKoniec()
{
   // Otazka
    if (AfxMessageBox(_T("Naozaj chcete ukonèi aplikáciu?"), MB_YESNO) != IDYES)
        return;

    // Uzavrieme spojenie do DB
    theApp.GetDB()->Close();

    // Spracovanie prenechame rodicovskej triede - ukonci dialog
    CDialog::OnCancel();
}

void CKnihaJazdDlg::OnOK()
{
    // Ziadny kod - zablokujeme tym stlacenie Enter
}

void CKnihaJazdDlg::OnCancel()
{
    // Otazka
    if (AfxMessageBox(_T("Naozaj chcete ukonèi aplikáciu?"), MB_YESNO) != IDYES)
        return;

    // Uzavrieme spojenie do DB
    theApp.GetDB()->Close();

    // Spracovanie prenechame rodicovskej triede - ukonci dialog
    CDialog::OnCancel();
}

void CKnihaJazdDlg::OnBnClickedBtnvyberauta()
{
	CVyberAutaDlg dlg(this);
	dlg.DoModal();
}

void CKnihaJazdDlg::OnBnClickedBtnvybercesty()
{
	CVyberCestyDlg dlg(this);
	dlg.DoModal();
}
