#include "stdafx.h"
#include "KnihaJazd.h"
#include "CestaDlg.h"
#include "CestaRecordset.h"

IMPLEMENT_DYNAMIC(CCestaDlg, CDialog)

CCestaDlg::CCestaDlg(CWnd* pParent)
	: CDialog(CCestaDlg::IDD, pParent)
{
}

CCestaDlg::~CCestaDlg()
{
}

void CCestaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCestaDlg, CDialog)
END_MESSAGE_MAP()

BOOL CCestaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    return TRUE;
}
