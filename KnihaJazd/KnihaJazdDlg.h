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

    afx_msg void OnFirmaOtvor();
    afx_msg void OnFirmaZmaz();
    afx_msg void OnFirmaNova();
    afx_msg void OnFirmaVlastnosti();
    afx_msg void OnFirmaKoniec();
    afx_msg void OnUpdateFirmaVlastnosti(CCmdUI *pCmdUI);
    afx_msg void OnUpdateFirmaZmaz(CCmdUI *pCmdUI);
	afx_msg void OnBnClickedBtnvyberauta();
	afx_msg void OnBnClickedBtnvybercesty();
	DECLARE_MESSAGE_MAP()

    void AktualizujPopisFirmy();

protected:
    int m_IdFirmy; // ID firmy, s ktorou pracujeme
    CFont m_FontFirma; // Font nadpisu firmy;
};
