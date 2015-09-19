// MonitorClientDlg.h : header file
//

#if !defined(AFX_MONITORCLIENTDLG_H__9ABE05CC_F5A7_493B_BA09_FDA2811F6CC5__INCLUDED_)
#define AFX_MONITORCLIENTDLG_H__9ABE05CC_F5A7_493B_BA09_FDA2811F6CC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMonitorClientDlg dialog

class CMonitorClientDlg : public CDialog
{
// Construction
public:
	CMonitorClientDlg(CWnd* pParent = NULL);	// standard constructor
	int SendMsg(CString msg);
	int Listen(CString& t);
	void ifconnected();

	void DealMsg(CString msg);
	void DealSet(CString msg);
	void DealChat(CString msg);
	void DealRemoteControl(CString msg);
	void DealOtherControl(CString msg);
	void DealScreenMonitor(CString msg);




	SOCKET sockCliBC;
	SOCKADDR_IN addrSrvInfo;
	unsigned short cliPortBC;//发出端口
	
	bool T1state;//Timer存在状态
	bool T2state;


	CString strLocalInfo;
// Dialog Data
	//{{AFX_DATA(CMonitorClientDlg)
	enum { IDD = IDD_MONITORCLIENT_DIALOG };
	CString	m_mymsg;
	CString	m_msgrecord;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMonitorClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnsend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORCLIENTDLG_H__9ABE05CC_F5A7_493B_BA09_FDA2811F6CC5__INCLUDED_)
