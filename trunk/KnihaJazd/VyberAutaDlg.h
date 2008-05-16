#pragma once

#include "afxcmn.h"

class CVyberAutaDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberAutaDlg)

public:
	CListCtrl m_ZoznamAut;

	CVyberAutaDlg(CWnd* pParent = NULL);
	virtual ~CVyberAutaDlg();

	enum { IDD = IDD_VYBERAUTADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX); 
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};