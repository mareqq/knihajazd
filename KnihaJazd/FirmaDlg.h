#pragma once

#include "FirmaRecordset.h"

class CFirmaDlg : public CDialog
{
	DECLARE_DYNAMIC(CFirmaDlg)

public:
    CString m_Nazov;
    CString m_Ulica;
    CString m_Cislo;
    CString m_Psc;
    CString m_Mesto;

    CFirmaDlg(CWnd* pParent = NULL);
	virtual ~CFirmaDlg();

	enum { IDD = IDD_FIRMADLG };

    void SetParams(long idFirmy);
    long GetIdFirmy() { return m_IdFirmy; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    virtual void OnOK();

	DECLARE_MESSAGE_MAP()

    CFirmaRecordset m_rsFirma;
    long m_IdFirmy; // Id firmy, s ktorou pracujeme.
                   // Ak je 0, tak sa bude pridavat nova firma.
};
