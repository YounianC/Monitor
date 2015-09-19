#if !defined(AFX_CHAT_H__332EC9A3_11A3_4B99_BF48_0E5EB6340441__INCLUDED_)
#define AFX_CHAT_H__332EC9A3_11A3_4B99_BF48_0E5EB6340441__INCLUDED_
#include "winsock2.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Chat.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CChat dialog

class CChat : public CDialog
{
// Construction
public:
	CChat(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChat)
	enum { IDD = IDD_CHAT };
	CString	m_chatrecord;
	CString	m_chatsend;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChat)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChat)
	afx_msg void OnBtnsend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CChat)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAT_H__332EC9A3_11A3_4B99_BF48_0E5EB6340441__INCLUDED_)
