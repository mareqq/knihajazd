#pragma once

#include "afxcmn.h"
#include "afxwin.h"

class CVyberCestyDlg : public CDialog
{
	DECLARE_DYNAMIC(CVyberCestyDlg)

public:
    CListCtrl m_ZoznamCiest;

	CVyberCestyDlg(CWnd* pParent = NULL);
	virtual ~CVyberCestyDlg();

	enum { IDD = IDD_VYBERCESTYDLG };

    COleDateTime GetVybratyDatum() { return m_VybratyDatum; }
	void SetParams(long idAuto, double kmSadzba);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

    afx_msg void OnLvnItemChangedListCesty(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLvnItemActivateListCesty(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnpridaj();
	afx_msg void OnZobraz();
    DECLARE_MESSAGE_MAP()

    void AktualizujOkno();

protected:
	COleDateTime m_VybratyDatum;

    long m_IdAuta; // ID auta, s ktorym pracujeme
	double m_Spolu;
	double m_KmSadzba;
};
