#include "stdafx.h"
#include "afxpriv.h"
#include "KnihaJazd.h"
#include "KnihaJazdDlg.h"
#include "FirmaRecordset.h"
#include "FirmaDlg.h"
#include "VyberFirmyDlg.h"
#include "VyberAutaDlg.h"
#include "VyberCestyDlg.h"
#include "AutoRecordset.h"
#include "CestaRecordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CKnihaJazdDlg::CKnihaJazdDlg(CWnd* pParent)
	: CDialog(CKnihaJazdDlg::IDD, pParent)
    , m_Firma(_T(""))
{
    m_IdFirmy = 0;
}

void CKnihaJazdDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATIC_FIRMA, m_Firma);
    DDX_Control(pDX, IDC_LIST_AUTA, m_ZoznamAut);
    DDX_Control(pDX, IDC_STATIC_FIRMA, m_FirmaCtrl);
}

BEGIN_MESSAGE_MAP(CKnihaJazdDlg, CDialog)
    ON_COMMAND(ID_FIRMA_OTVOR, &CKnihaJazdDlg::OnFirmaOtvor)
    ON_COMMAND(ID_FIRMA_ZMAZ, &CKnihaJazdDlg::OnFirmaZmaz)
    ON_COMMAND(ID_FIRMA_NOVA, &CKnihaJazdDlg::OnFirmaNova)
    ON_COMMAND(ID_FIRMA_VLASTNOSTI, &CKnihaJazdDlg::OnFirmaVlastnosti)
    ON_COMMAND(ID_FIRMA_KONIEC, &CKnihaJazdDlg::OnFirmaKoniec)
    ON_UPDATE_COMMAND_UI(ID_FIRMA_VLASTNOSTI, &CKnihaJazdDlg::OnUpdateFirmaVlastnosti)
    ON_UPDATE_COMMAND_UI(ID_FIRMA_ZMAZ, &CKnihaJazdDlg::OnUpdateFirmaZmaz)
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
*/

    // Firma
    LOGFONT lf = {0};
    // Nacitam si specifikaciu povodneho fontu.
    CFont *pFont = m_FirmaCtrl.GetFont();
    pFont->GetLogFont(&lf);
    // Upravim specifikaciu fontu.
    lf.lfWeight = FW_BOLD;
    // Vytvorim novy font podla upravenej specifikacie.
    m_FontFirma.CreateFontIndirect(&lf);
    // Nastavim font popisu firmy.
    m_FirmaCtrl.SetFont(&m_FontFirma);
    // Aktualizujem text popisu firmy.
    AktualizujPopisFirmy();

    // Zoznam aut
    m_ZoznamAut.SetExtendedStyle(LVS_EX_FULLROWSELECT);
    m_ZoznamAut.InsertColumn(0, _T("Znaèka"), LVCFMT_LEFT, 100);
    m_ZoznamAut.InsertColumn(1, _T("Typ"), LVCFMT_LEFT, 200);

    UpdateData(FALSE);
    return TRUE;
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

void CKnihaJazdDlg::OnFirmaOtvor()
{
    CVyberFirmyDlg dlg(this);
    if (dlg.DoModal() == IDOK)
    {
        // Firma bola vybrana
        m_IdFirmy = dlg.GetIdVybratejFirmy();
        AktualizujPopisFirmy();
    }
}

void CKnihaJazdDlg::OnFirmaZmaz()
{
    CString str;
    str.Format(_T("Naozaj chcete vymaza firmu %s a všetky jej autá a cesty?"), m_Firma);

    if (AfxMessageBox(str, MB_YESNO) == IDYES)
    {
        // Zmazanie firmy
        CFirmaRecordset rs(theApp.GetDB());
        rs.SetSQLNacitanieKonkretnejFirmy(m_IdFirmy);
        rs.Open();
        rs.Delete();
        rs.Close();

        m_IdFirmy = 0;
        AktualizujPopisFirmy();

        // Vyber dalsej firmy, s ktorou budeme pracovat
        OnFirmaOtvor();
    }
}

void CKnihaJazdDlg::OnFirmaNova()
{
    CFirmaDlg dlg;
    if (dlg.DoModal() == IDOK)
    {
        m_IdFirmy = dlg.GetIdFirmy();
        AktualizujPopisFirmy();
    }
}

void CKnihaJazdDlg::OnFirmaVlastnosti()
{
    CFirmaDlg dlg;
    dlg.SetParams(m_IdFirmy);
    if (dlg.DoModal() == IDOK)
    {
        AktualizujPopisFirmy();
    }
}

void CKnihaJazdDlg::OnFirmaKoniec()
{
    OnCancel();
}

void CKnihaJazdDlg::AktualizujPopisFirmy()
{
    if (m_IdFirmy == 0)
    {
        m_Firma = _T("Žiadna firma nebola vybraná.")
            _T("  Vyberte firmu vo¾bou Firma > Vyber alebo priadjte novú vo¾bou Firma > Nová.");
    }
    else
    {
        CFirmaRecordset rs(theApp.GetDB());
        rs.SetSQLNacitanieKonkretnejFirmy(m_IdFirmy);
        rs.Open();
        m_Firma.Format(_T("%s, %s %s, %s %s"), rs.m_FNazov, rs.m_FUlica, rs.m_FCislo,
            rs.m_FPsc, rs.m_FMesto);
        rs.Close();
    }

    UpdateData(FALSE);
}

void CKnihaJazdDlg::OnUpdateFirmaVlastnosti(CCmdUI *pCmdUI)
{
    pCmdUI->Enable(m_IdFirmy != 0);
}

void CKnihaJazdDlg::OnUpdateFirmaZmaz(CCmdUI *pCmdUI)
{
    pCmdUI->Enable(m_IdFirmy != 0);
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
