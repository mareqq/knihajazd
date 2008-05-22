#pragma once

#include "CestaRecordset.h"

class CCestaDlg : public CDialog
{
	DECLARE_DYNAMIC(CCestaDlg)

public:
	CDateTimeCtrl m_DatumCtrl; // Control s datumom
	CEdit m_SpoluCtrl; // Control s m_Spolu

	COleDateTime m_Datum;
	CString m_Ciel;
	CString m_Ucel;
	double m_PocetKm;
	double m_PocStav;
	double m_KonStav;
	double m_Tankovane;
	double m_Stravne;
	double m_Ostatne;

	double m_Spolu;
	float m_KmSadzba;

	CCestaDlg(CWnd* pParent = NULL);  
	virtual ~CCestaDlg();

	enum { IDD = IDD_CESTADLG };

	void SetParamsA(long idAuta);
	void SetParamsD(COleDateTime Datum);
	void SetParamsKS(float KmSadzba);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  
	virtual BOOL OnInitDialog();
    virtual void OnOK();

	DECLARE_MESSAGE_MAP()

    CCestaRecordset m_rsCesta;
    long m_IdAuta; // Id firmy, s ktorou pracujeme.
                   // Ak je 0, tak sa bude pridavat nova firma.
};
