// Chat.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorSercver.h"
#include "Chat.h"
#include "MonitorSercverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChat dialog


CChat::CChat(CWnd* pParent /*=NULL*/)
	: CDialog(CChat::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CChat)
	m_chatrecord = _T("");
	m_chatsend = _T("");
	//}}AFX_DATA_INIT
}


void CChat::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CChat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChat)
	DDX_Text(pDX, IDC_EDITMSG, m_chatrecord);
	DDX_Text(pDX, IDC_EDITSEND, m_chatsend);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChat, CDialog)
	//{{AFX_MSG_MAP(CChat)
	ON_BN_CLICKED(IDC_BTNSEND, OnBtnsend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CChat, CDialog)
	//{{AFX_DISPATCH_MAP(CChat)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IChat to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {62F18E84-F127-4157-BDA6-75E4B81E8D22}
static const IID IID_IChat =
{ 0x62f18e84, 0xf127, 0x4157, { 0xbd, 0xa6, 0x75, 0xe4, 0xb8, 0x1e, 0x8d, 0x22 } };

BEGIN_INTERFACE_MAP(CChat, CDialog)
	INTERFACE_PART(CChat, IID_IChat, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChat message handlers

void CChat::OnBtnsend() 
{
	// TODO: Add your control notification handler code here
	//·¢ËÍÏûÏ¢
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	UpdateData(TRUE);
	
	CString t="--"+m_chatsend;
	m_chatrecord+=t;
	m_chatrecord+="\r\n";

	m_chatsend="&CHAT&"+m_chatsend;
	int a=pDlg->SendMsg(m_chatsend);
	
	m_chatsend="";
	
	UpdateData(FALSE);
}
