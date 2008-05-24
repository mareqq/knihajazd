#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class CKnihaJazdDlg : public CDialog
{
public:
    CMenu m_Menu; // Menu

    CListCtrl m_ZoznamAut; // Control so zoznamom aut
    CString m_Firma; // Text s nadpisom firmy
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

	// Firma
    afx_msg void OnFirmaOtvor();
    afx_msg void OnFirmaZmaz();
    afx_msg void OnFirmaNova();
    afx_msg void OnFirmaVlastnosti();
    afx_msg void OnFirmaKoniec();
    afx_msg void OnUpdateFirmaVlastnosti(CCmdUI *pCmdUI);
    afx_msg void OnUpdateFirmaZmaz(CCmdUI *pCmdUI);
	// Auto
	afx_msg void OnAutoOtvor();
	afx_msg void OnAutoZmaz();
	afx_msg void OnAutoNove();
	afx_msg void OnAutoVlastnosti();
    afx_msg void OnUpdateAutoVlastnosti(CCmdUI *pCmdUI);
    afx_msg void OnUpdateAutoZmaz(CCmdUI *pCmdUI);
    afx_msg void OnLvnItemActivateListAuta(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnUpdateAutoOtvor(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAutoNove(CCmdUI *pCmdUI);
	DECLARE_MESSAGE_MAP()

    void AktualizujPopisFirmy();

protected:
    long m_IdFirmy; // ID firmy, s ktorou pracujeme
    CFont m_FontFirma; // Font nadpisu firmy;
	double m_KmSadzba;
};
