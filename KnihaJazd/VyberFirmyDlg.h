#pragma once

#include "afxcmn.h"

class CVyberFirmyDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberFirmyDlg)

public:
    CListCtrl m_ZoznamFiriem;

	CVyberFirmyDlg(CWnd* pParent = NULL);
	virtual ~CVyberFirmyDlg();

	enum { IDD = IDD_VYBERFIRMYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()
};
