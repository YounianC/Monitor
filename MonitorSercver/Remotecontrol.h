#if !defined(AFX_REMOTECONTROL_H__68D64463_38A9_435B_B41D_6C85EFCEC2FB__INCLUDED_)
#define AFX_REMOTECONTROL_H__68D64463_38A9_435B_B41D_6C85EFCEC2FB__INCLUDED_
#include "winsock2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Remotecontrol.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRemotecontrol dialog

class CRemotecontrol : public CDialog
{
// Construction
public:
	CRemotecontrol(CWnd* pParent = NULL);   // standard constructor
	SOCKET m_client;
// Dialog Data
	//{{AFX_DATA(CRemotecontrol)
	enum { IDD = IDD_REMOTECONTROL };
	CString	m_clientname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemotecontrol)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRemotecontrol)
	afx_msg void OnButtonhidedesk();
	afx_msg void OnButtonshowdesk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnLogoff();
	afx_msg void OnBtnShutdown();
	afx_msg void OnBtnReboot();
	afx_msg void OnBtnturnoffscr();
	afx_msg void OnBtnturnonscr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CRemotecontrol)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTECONTROL_H__68D64463_38A9_435B_B41D_6C85EFCEC2FB__INCLUDED_)
