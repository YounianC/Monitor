// Remotecontrol.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorSercver.h"
#include "Remotecontrol.h"
#include "MonitorSercverDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRemotecontrol dialog


CRemotecontrol::CRemotecontrol(CWnd* pParent /*=NULL*/)
	: CDialog(CRemotecontrol::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CRemotecontrol)
	m_clientname = _T("");
	//}}AFX_DATA_INIT
}


void CRemotecontrol::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CRemotecontrol::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemotecontrol)
	DDX_Text(pDX, IDC_EDITNAME, m_clientname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRemotecontrol, CDialog)
	//{{AFX_MSG_MAP(CRemotecontrol)
	ON_BN_CLICKED(IDC_BUTTONHIDEDESK, OnButtonhidedesk)
	ON_BN_CLICKED(IDC_BUTTONSHOWDESK, OnButtonshowdesk)
	ON_BN_CLICKED(IDC_BTN_LOGOFF, OnBtnLogoff)
	ON_BN_CLICKED(IDC_BTN_SHUTDOWN, OnBtnShutdown)
	ON_BN_CLICKED(IDC_BTN_REBOOT, OnBtnReboot)
	ON_BN_CLICKED(IDC_BTNTURNOFFSCR, OnBtnturnoffscr)
	ON_BN_CLICKED(IDC_BTNTURNONSCR, OnBtnturnonscr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CRemotecontrol, CDialog)
	//{{AFX_DISPATCH_MAP(CRemotecontrol)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IRemotecontrol to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {C47FECFB-7D60-41FD-ACAA-EFBB351F1FA0}
static const IID IID_IRemotecontrol =
{ 0xc47fecfb, 0x7d60, 0x41fd, { 0xac, 0xaa, 0xef, 0xbb, 0x35, 0x1f, 0x1f, 0xa0 } };

BEGIN_INTERFACE_MAP(CRemotecontrol, CDialog)
	INTERFACE_PART(CRemotecontrol, IID_IRemotecontrol, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemotecontrol message handlers



void CRemotecontrol::OnButtonhidedesk() 
{
	// TODO: Add your control notification handler code here

	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();

//	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	
	CString temp;
	temp="&COMMAND_HIDEDESK&";
	int a=pDlg->SendMsg(temp);
}

void CRemotecontrol::OnButtonshowdesk() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
//	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	
	CString temp;
	temp="&COMMAND_SHOWDESK&";
	int a=pDlg->SendMsg(temp);
}

BOOL CRemotecontrol::OnInitDialog() 
{

	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_client = socket(AF_INET,SOCK_STREAM,0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRemotecontrol::OnBtnLogoff() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
	
	//	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	
	CString temp;
	temp="&COMMAND_LOGOFF&";
	int a=pDlg->SendMsg(temp);
}

void CRemotecontrol::OnBtnShutdown() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
	
	//	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	
	CString temp;
	temp="&COMMAND_SHUTDOWN&";
	int a=pDlg->SendMsg(temp);
}

void CRemotecontrol::OnBtnReboot() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
	
	//	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	
	CString temp;
	temp="&COMMAND_REBOOT&";
	int a=pDlg->SendMsg(temp);
}

void CRemotecontrol::OnBtnturnoffscr() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
	CString temp;
	temp="&COMMAND_TURNOFFSCR&";
	int a=pDlg->SendMsg(temp);
}

void CRemotecontrol::OnBtnturnonscr() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)GetParent()->GetParent();
	CString temp;
	temp="&COMMAND_TURNONSCR&";
	int a=pDlg->SendMsg(temp);
}
