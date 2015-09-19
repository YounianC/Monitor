#if !defined(AFX_SCREENMONITOR_H__0951A5DF_555E_4278_9E00_2EEC2834A572__INCLUDED_)
#define AFX_SCREENMONITOR_H__0951A5DF_555E_4278_9E00_2EEC2834A572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScreenMonitor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScreenMonitor dialog

class CScreenMonitor : public CDialog
{
// Construction
public:
	CScreenMonitor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScreenMonitor)
	enum { IDD = IDD_SCREENMONITOR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenMonitor)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScreenMonitor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CScreenMonitor)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREENMONITOR_H__0951A5DF_555E_4278_9E00_2EEC2834A572__INCLUDED_)
