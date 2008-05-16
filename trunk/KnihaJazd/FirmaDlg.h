#pragma once

#include "afxcmn.h"

class CFirmaDlg : public CDialog
{
	DECLARE_DYNAMIC(CFirmaDlg)

public:
	int ID[100], pocet, findID;
	int i, j;
	bool ok;
	
	CFirmaDlg(CWnd* pParent = NULL);  

//musime nastavit automaticke ID, ale zatial:
	int m_IdFirmy;

    CString m_Nazov; // Text s názvom firmy
// Adresa firmy:
    CString m_Ulica;
	CString m_Cislo;
	CString m_Mesto;
	CString m_Psc;

	virtual ~CFirmaDlg();

	enum { IDD = IDD_FIRMADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX); 

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
