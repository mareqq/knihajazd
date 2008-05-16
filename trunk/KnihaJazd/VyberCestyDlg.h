#pragma once

#include "afxcmn.h"

class CVyberCestyDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberCestyDlg)

public:
	CListCtrl m_ZoznamCiest;
	CString transf;
	
	CVyberCestyDlg(CWnd* pParent = NULL);
	virtual ~CVyberCestyDlg();

	enum { IDD = IDD_VYBERCESTYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
