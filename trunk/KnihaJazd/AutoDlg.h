#pragma once

#include "afxcmn.h"

class CAutoDlg : public CDialog
{
	DECLARE_DYNAMIC(CAutoDlg)

public:
	CAutoDlg(CWnd* pParent = NULL);  
	virtual ~CAutoDlg();

	enum { IDD = IDD_AUTODLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
