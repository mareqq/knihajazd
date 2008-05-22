#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class CVyberFirmyDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberFirmyDlg)

public:
    CListCtrl m_ZoznamFiriem;
    CButton m_TlacidloOk;

	CVyberFirmyDlg(CWnd* pParent = NULL);
	virtual ~CVyberFirmyDlg();

	enum { IDD = IDD_VYBERFIRMYDLG };

    long GetIdVybratejFirmy() { return m_IdVybratejFirmy; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
    virtual void OnOK();

    afx_msg void OnLvnItemChangedListFirmy(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLvnItemActivateListFirmy(NMHDR *pNMHDR, LRESULT *pResult);
    DECLARE_MESSAGE_MAP()

    void AktualizujOkno();

protected:
    long m_IdVybratejFirmy;
};
