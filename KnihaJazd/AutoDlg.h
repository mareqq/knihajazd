#pragma once

#include "FirmaRecordset.h"
#include "AutoRecordset.h"

class CAutoDlg : public CDialog
{
	DECLARE_DYNAMIC(CAutoDlg)

public:
	CString m_Spz;
	CString m_Typ;
	double m_KmSadzba;
	double m_PriemernaSpotreba;
	long m_Rok;

	CAutoDlg(CWnd* pParent = NULL);  
	virtual ~CAutoDlg();

	enum { IDD = IDD_AUTODLG };

	void SetParamsA(int idAuta);
	void SetParamsF(int idFirmy);
	int GetIdAuta() { return m_IdAuta; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	DECLARE_MESSAGE_MAP()

	CAutoRecordset m_rsAuto;
	
	int m_IdFirmy; //Id firmy, s ktorou pracujeme a v ktorej sa auto nachadza
    int m_IdAuta; // Id auta, s ktorym pracujeme.
                  // Ak je 0, tak sa bude pridavat nove auto.
};
