// ScreenMonitor.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorSercver.h"
#include "ScreenMonitor.h"
#include "MonitorSercverDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreenMonitor dialog


CScreenMonitor::CScreenMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CScreenMonitor::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CScreenMonitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScreenMonitor::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CScreenMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScreenMonitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScreenMonitor, CDialog)
	//{{AFX_MSG_MAP(CScreenMonitor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CScreenMonitor, CDialog)
	//{{AFX_DISPATCH_MAP(CScreenMonitor)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IScreenMonitor to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D0F69516-8A6D-4FA7-AB35-67F785BDB7A2}
static const IID IID_IScreenMonitor =
{ 0xd0f69516, 0x8a6d, 0x4fa7, { 0xab, 0x35, 0x67, 0xf7, 0x85, 0xbd, 0xb7, 0xa2 } };

BEGIN_INTERFACE_MAP(CScreenMonitor, CDialog)
	INTERFACE_PART(CScreenMonitor, IID_IScreenMonitor, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenMonitor message handlers
