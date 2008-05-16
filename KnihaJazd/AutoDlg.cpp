#include "stdafx.h"
#include "KnihaJazd.h"
#include "AutoDlg.h"
#include "AutoRecordset.h"

IMPLEMENT_DYNAMIC(CAutoDlg, CDialog)

CAutoDlg::CAutoDlg(CWnd* pParent)
	: CDialog(CAutoDlg::IDD, pParent)
{
}

CAutoDlg::~CAutoDlg()
{
}

void CAutoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAutoDlg, CDialog)
END_MESSAGE_MAP()

BOOL CAutoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    return TRUE;
}