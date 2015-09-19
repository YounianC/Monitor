// OtherMonitor.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorSercver.h"
#include "OtherMonitor.h"
#include "MonitorSercverDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COtherMonitor dialog


COtherMonitor::COtherMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(COtherMonitor::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(COtherMonitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COtherMonitor::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void COtherMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COtherMonitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COtherMonitor, CDialog)
	//{{AFX_MSG_MAP(COtherMonitor)
	ON_BN_CLICKED(IDC_BUTTONGET, OngetClipboard)
	ON_BN_CLICKED(IDC_BUTTONSET, OnButtonset)
	ON_BN_CLICKED(IDC_BUTTONCOPY, OnButtoncopy)
	ON_BN_CLICKED(IDC_BTNSENDFILE, OnBtnsendfile)
	ON_BN_CLICKED(IDC_BTNSELFCOPY, OnBtnselfcopy)
	ON_BN_CLICKED(IDC_BTNONSTART, OnBtnonstart)
	ON_BN_CLICKED(IDC_BATCONTROL, OnBatcontrol)
	ON_BN_CLICKED(IDC_BTNMOREFILE, OnBtnmorefile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COtherMonitor, CDialog)
	//{{AFX_DISPATCH_MAP(COtherMonitor)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOtherMonitor to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {B5090C4C-6CAB-4401-9932-02E830170372}
static const IID IID_IOtherMonitor =
{ 0xb5090c4c, 0x6cab, 0x4401, { 0x99, 0x32, 0x2, 0xe8, 0x30, 0x17, 0x3, 0x72 } };

BEGIN_INTERFACE_MAP(COtherMonitor, CDialog)
	INTERFACE_PART(COtherMonitor, IID_IOtherMonitor, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COtherMonitor message handlers

void COtherMonitor::OngetClipboard() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	int a=pDlg->SendMsg("&OTHER_GETCLIPBOARD&");
}

void COtherMonitor::OnButtonset() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	int a=pDlg->SendMsg("&OTHER_SETCLIPBOARD&");
}

void COtherMonitor::OnButtoncopy() 
{
	// TODO: Add your control notification handler code here
	/////将本机剪切板内容置为复制内容
	CString   source;
	GetDlgItemText(IDC_EDITCLIPBOARD,source);
	if(OpenClipboard())
	{ 
		HGLOBAL clipbuffer; 
		char *buffer; 
		EmptyClipboard(); 
		clipbuffer=GlobalAlloc(GMEM_DDESHARE,   source.GetLength()+1); 
		buffer=(char*)GlobalLock(clipbuffer); 
		strcpy(buffer,   LPCSTR(source)); 
		GlobalUnlock(clipbuffer); 
		SetClipboardData(CF_TEXT,clipbuffer); 
		CloseClipboard(); 
	}
}

void COtherMonitor::OnBtnsendfile() 
{
	// TODO: Add your control notification handler code here

	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	CString pathoffile,pathtosave;
	GetDlgItem(IDC_EPATHOFFILE)->GetWindowText(pathoffile);
	GetDlgItem(IDC_EPATHTOSAVE)->GetWindowText(pathtosave);




	CFile myFile;
	myFile.Open(pathoffile.GetBuffer(pathoffile.GetLength()), CFile::modeRead | CFile::typeBinary); 
	int myFileLength = myFile.GetLength(); // Going to send the correct File Size
	CString t="&OTHER_SENDFILE&";
	CString temp;
	temp.Empty();
	temp.Format("%d<%s>",myFileLength,pathtosave.GetBuffer(pathtosave.GetLength()));

	byte* data = new byte[myFileLength]; 
	myFile.Read(data,myFileLength);
	
	temp+=data;

	t+=temp;

	CString q=data;
	MessageBox(q);

	int a=pDlg->SendMsg(t);
	myFile.Close();
	delete data;

}

void COtherMonitor::OnBtnselfcopy() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	CString t;
	GetDlgItemText(IDC_EDITPATHTOCOPY,t);
	t="&OTHER_COPYYOUSELF&:"+t;//////t="c:\\test.exe"
	int a=pDlg->SendMsg(t);
}

void COtherMonitor::OnBtnonstart() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	CString t;
	GetDlgItemText(IDC_EDITPATHTOCOPY,t);
	t="&OTHER_SETONSTART&:"+t;
	int a=pDlg->SendMsg(t);
}

void COtherMonitor::OnBatcontrol() 
{
	// TODO: Add your control notification handler code here
	CMonitorSercverDlg *pDlg = (CMonitorSercverDlg *)AfxGetMainWnd();
	CString t;
	GetDlgItemText(IDC_EDITBATCONTROL,t);
	t="&OTHER_BATCONTROL&:"+t;
	int a=pDlg->SendMsg(t);
}

void COtherMonitor::OnBtnmorefile() 
{
	CString path;
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="打开：";
	fileDlg.m_ofn.lpstrFilter="ALL Files(*.*)\0*.*\0\0";
	if (IDOK==fileDlg.DoModal())
	{
		path=fileDlg.GetPathName();
		GetDlgItem(IDC_EPATHOFFILE)->SetWindowText(path);	
	}
}
