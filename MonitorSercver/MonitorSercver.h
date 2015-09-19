// MonitorSercver.h : main header file for the MONITORSERCVER application
//

#if !defined(AFX_MONITORSERCVER_H__E2F02E96_EC1C_4493_B329_A3722F0C90FB__INCLUDED_)
#define AFX_MONITORSERCVER_H__E2F02E96_EC1C_4493_B329_A3722F0C90FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMonitorSercverApp:
// See MonitorSercver.cpp for the implementation of this class
//

class CMonitorSercverApp : public CWinApp
{
public:
	CMonitorSercverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorSercverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMonitorSercverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORSERCVER_H__E2F02E96_EC1C_4493_B329_A3722F0C90FB__INCLUDED_)
