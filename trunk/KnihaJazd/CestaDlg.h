#pragma once

#include "afxcmn.h"

class CCestaDlg : public CDialog
{
	DECLARE_DYNAMIC(CCestaDlg)

public:
	CCestaDlg(CWnd* pParent = NULL);  
	virtual ~CCestaDlg();

	enum { IDD = IDD_CESTADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
