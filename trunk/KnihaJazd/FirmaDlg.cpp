#include "stdafx.h"
#include "KnihaJazd.h"
#include "FirmaDlg.h"
#include "FirmaRecordset.h"

IMPLEMENT_DYNAMIC(CFirmaDlg, CDialog)

CFirmaDlg::CFirmaDlg(CWnd* pParent)
	: CDialog(CFirmaDlg::IDD, pParent)
    , m_Nazov(_T(""))
    , m_Ulica(_T(""))
    , m_Cislo(_T(""))
    , m_Mesto(_T(""))
    , m_Psc(_T(""))
{
}

CFirmaDlg::~CFirmaDlg()
{
}

void CFirmaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_NAZOV, m_Nazov);
	DDX_Text(pDX, IDC_ULICA, m_Ulica);
	DDX_Text(pDX, IDC_CISLO, m_Cislo);
	DDX_Text(pDX, IDC_MESTO, m_Mesto);
	DDX_Text(pDX, IDC_PSC, m_Psc);
}

BEGIN_MESSAGE_MAP(CFirmaDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CFirmaDlg::OnBnClickedOk)
END_MESSAGE_MAP()


void CFirmaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);

	CFirmaRecordset rs(theApp.GetDB());
	
    rs.Open();

// Testovanie volneho ID
	pocet = 0;

	while (!rs.IsEOF())
    {
		ID[pocet] = rs.m_FId;
		pocet++;

        rs.MoveNext();
    }

	rs.AddNew();

	ok = true;

	for (i=1; i<pocet+2; i++)
	{
		for (j=0; j<pocet; j++)
		{
			if (ID[j] == i)
			{
				ok = false;
				j = pocet;
			}
			else
				if (ok == true)
					findID = i;
		}
		if (ok == true)
			i = pocet+2;
		else
			ok = true;
	}
// Koniec testovania ID - volne ID ulozene v "findID"

	rs.m_FId = findID;
	rs.m_FNazov = m_Nazov;
	rs.m_FUlica = m_Ulica;
	rs.m_FCislo = m_Cislo;
	rs.m_FMesto = m_Mesto;
	rs.m_FPsc = m_Psc;
    rs.Update();

	rs.Close();

	MessageBoxW(_T("Firma bola úspešne uložená"), _T("Ukladanie"));

	OnOK();
}
