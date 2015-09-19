// MonitorSercverDlg.h : header file
//

#if !defined(AFX_MONITORSERCVERDLG_H__5A0CF55B_B885_4F1C_AAE1_C785CF2F277E__INCLUDED_)
#define AFX_MONITORSERCVERDLG_H__5A0CF55B_B885_4F1C_AAE1_C785CF2F277E__INCLUDED_
#include "winsock2.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Chat.h"
#include "OtherMonitor.h"
#include "Remotecontrol.h"
#include "ScreenMonitor.h"




/////////////////////////////////////////////////////////////////////////////
// CMonitorSercverDlg dialog

class CMonitorSercverDlg : public CDialog
{
// Construction
public:
	CMonitorSercverDlg(CWnd* pParent = NULL);	// standard constructor
	int SendMsg(CString msg);
	int Listen(CString& t);
	void ifconnected();

	bool DealMsg(CString msg);
	void DealChat(CString msg);
	void DealRemoteControl(CString msg);
	void DealOtherControl(CString msg);
	void DealScreenMonitor(CString msg);





	CChat *chat;
	CScreenMonitor *screenmonitor;
	COtherMonitor *othermonitor;
	CRemotecontrol *remotrcomtrol;

	SOCKET sockSrv;
	SOCKADDR_IN addrCliInfo;


	bool T1state;//Timer´æÔÚ×´Ì¬
	bool T2state;

	unsigned short SrvPortBC;

// Dialog Data
	//{{AFX_DATA(CMonitorSercverDlg)
	enum { IDD = IDD_MONITORSERCVER_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitorSercverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMonitorSercverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnstart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnsetvisable();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORSERCVERDLG_H__5A0CF55B_B885_4F1C_AAE1_C785CF2F277E__INCLUDED_)
