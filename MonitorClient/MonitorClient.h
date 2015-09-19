// MonitorClient.h : main header file for the MONITORCLIENT application
//

#if !defined(AFX_MONITORCLIENT_H__08782D77_7092_4AA6_B6FD_D5492DBCB718__INCLUDED_)
#define AFX_MONITORCLIENT_H__08782D77_7092_4AA6_B6FD_D5492DBCB718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMonitorClientApp:
// See MonitorClient.cpp for the implementation of this class
//

class CMonitorClientApp : public CWinApp
{
public:
	CMonitorClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMonitorClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORCLIENT_H__08782D77_7092_4AA6_B6FD_D5492DBCB718__INCLUDED_)
