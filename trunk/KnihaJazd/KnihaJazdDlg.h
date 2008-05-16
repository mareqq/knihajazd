#pragma once

#include "afxcmn.h"

class CKnihaJazdDlg : public CDialog
{
public:
    CMenu m_Menu; // Menu

    CListCtrl m_ZoznamAut; // Control so zoznamom aut
    CString m_Firma; // Text s nadpisom firmy
    int m_idFirma; // ID firmy, s ktorou pracujeme
    CString m_NazovFirmy; // Nazov firmy, s ktorou pracujeme

    CKnihaJazdDlg(CWnd* pParent = NULL);

	enum { IDD = IDD_KNIHAJAZDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	virtual BOOL OnInitDialog();
    virtual void OnOK();
    virtual void OnCancel();

    afx_msg void OnFirmaVyber();
    afx_msg void OnFirmaPridaj();
	afx_msg void OnFirmaUprav();
	afx_msg void OnFirmaZmaz();
	afx_msg void OnKoniec();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBtnvyberauta();
public:
	afx_msg void OnBnClickedBtnvybercesty();
};
