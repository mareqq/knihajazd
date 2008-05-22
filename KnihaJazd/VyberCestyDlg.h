#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class CVyberCestyDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberCestyDlg)

public:
    CListCtrl m_ZoznamCiest;
	CString transf;
    CButton m_TlacidloOk;

	CVyberCestyDlg(CWnd* pParent = NULL);
	virtual ~CVyberCestyDlg();

	enum { IDD = IDD_VYBERCESTYDLG };

    COleDateTime GetVybratyDatum() { return m_VybratyDatum; }
	void SetKmSadzba(double KmSadzba);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
    virtual void OnOK();

    afx_msg void OnLvnItemChangedListCesty(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLvnItemActivateListCesty(NMHDR *pNMHDR, LRESULT *pResult);
    DECLARE_MESSAGE_MAP()

    void AktualizujOkno();

protected:
	COleDateTime m_VybratyDatum;
    long m_IdAuta; // ID auta, s ktorym pracujeme
	double m_Spolu;
	double m_KmSadzba;
public:
	afx_msg void OnBnClickedBtnpridaj();
};
