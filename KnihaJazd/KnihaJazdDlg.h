#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class CKnihaJazdDlg : public CDialog
{
public:
    CMenu m_Menu; // Menu

    CListCtrl m_ZoznamAut; // Control so zoznamom aut
    CString m_Firma; // Text s nadpisom firmy
    CString m_Auto; // Text s SPZ auta
    CStatic m_FirmaCtrl; // Control s nadpisom firmy

    CKnihaJazdDlg(CWnd* pParent = NULL);

	enum { IDD = IDD_KNIHAJAZDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	virtual BOOL OnInitDialog();
    virtual void OnOK();
    virtual void OnCancel();

	void AktualizujOkno();
	void NacitanieAut();

	//Firma
    afx_msg void OnFirmaOtvor();
    afx_msg void OnFirmaZmaz();
    afx_msg void OnFirmaNova();
    afx_msg void OnFirmaVlastnosti();
    afx_msg void OnFirmaKoniec();

    afx_msg void OnUpdateFirmaVlastnosti(CCmdUI *pCmdUI);
    afx_msg void OnUpdateFirmaZmaz(CCmdUI *pCmdUI);

	//Auto
	afx_msg void OnAutoOtvor();
	afx_msg void OnAutoZmaz();
	afx_msg void OnAutoNove();
//	afx_msg void OnAutoVlastnosti();

    afx_msg void OnUpdateAutoVlastnosti(CCmdUI *pCmdUI);
//    afx_msg void OnUpdateFirmaZmaz(CCmdUI *pCmdUI);

	afx_msg void OnLvnItemChangedListAuta(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLvnItemActivateListAuta(NMHDR *pNMHDR, LRESULT *pResult);

	DECLARE_MESSAGE_MAP()

    void AktualizujPopisFirmy();

protected:
    int m_IdFirmy; // ID firmy, s ktorou pracujeme
    int m_IdAuta; // ID auta, s ktorym pracujeme
    CFont m_FontFirma; // Font nadpisu firmy;
};
