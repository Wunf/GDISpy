
// GDISpy.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGDISpyApp:
// See GDISpy.cpp for the implementation of this class
//

class CGDISpyApp : public CWinApp
{
public:
	CGDISpyApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

DWORD FindProcessId(const std::wstring& processName, int index);

extern CGDISpyApp theApp;