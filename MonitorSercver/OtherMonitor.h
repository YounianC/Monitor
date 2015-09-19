#if !defined(AFX_OTHERMONITOR_H__17CF261E_1076_41D5_A6DE_376C986C0C0A__INCLUDED_)
#define AFX_OTHERMONITOR_H__17CF261E_1076_41D5_A6DE_376C986C0C0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OtherMonitor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COtherMonitor dialog

class COtherMonitor : public CDialog
{
// Construction
public:
	COtherMonitor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COtherMonitor)
	enum { IDD = IDD_OTHERMONITOR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COtherMonitor)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COtherMonitor)
	afx_msg void OngetClipboard();
	afx_msg void OnButtonset();
	afx_msg void OnButtoncopy();
	afx_msg void OnBtnsendfile();
	afx_msg void OnBtnselfcopy();
	afx_msg void OnBtnonstart();
	afx_msg void OnBatcontrol();
	afx_msg void OnBtnmorefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COtherMonitor)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHERMONITOR_H__17CF261E_1076_41D5_A6DE_376C986C0C0A__INCLUDED_)
