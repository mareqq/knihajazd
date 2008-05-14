#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "Resource.h"

class CKnihaJazdApp : public CWinApp
{
public:
	CKnihaJazdApp();

public:
    CDatabase *GetDB() { return &m_DB; }

	virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()

protected:
    CDatabase m_DB;
};

extern CKnihaJazdApp theApp;
