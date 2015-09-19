// MonitorSercverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorSercver.h"
#include "MonitorSercverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;


/////////////////////////////////////////////////////////////////////////////
// CMonitorSercverDlg dialog

CMonitorSercverDlg::CMonitorSercverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMonitorSercverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonitorSercverDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMonitorSercverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorSercverDlg)
	DDX_Control(pDX, IDC_TAB, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMonitorSercverDlg, CDialog)
	//{{AFX_MSG_MAP(CMonitorSercverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_BTNSTART, OnBtnstart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTNSETVISABLE, OnBtnsetvisable)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorSercverDlg message handlers

BOOL CMonitorSercverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_tab.InsertItem(0,"����");
	m_tab.InsertItem(1,"��Ļ���");
	m_tab.InsertItem(2,"�������");
	m_tab.InsertItem(3,"Զ�̿���");
	
	
	chat=new CChat;
	screenmonitor=new CScreenMonitor;
	othermonitor=new COtherMonitor;
	remotrcomtrol=new CRemotecontrol;
	//�����Ի���,���ҽ�IDC_TABTEST�ؼ���Ϊ������ 
	chat->Create(IDD_CHAT,GetDlgItem(IDC_TAB)); 
	screenmonitor->Create(IDD_SCREENMONITOR,GetDlgItem(IDC_TAB)); 
	othermonitor->Create(IDD_OTHERMONITOR,GetDlgItem(IDC_TAB)); 
	remotrcomtrol->Create(IDD_REMOTECONTROL,GetDlgItem(IDC_TAB)); 
	
	
	//���IDC_TAB�ͻ�����С 
	CRect rs;
	this->GetWindowRect(&rs);
	
	//�����ӶԻ����ڸ������е�λ�� 
	rs.top += 20;
	//�����ӶԻ���ߴ粢�ƶ���ָ��λ�� 
	chat->MoveWindow(&rs);
	screenmonitor->MoveWindow(&rs);
	othermonitor->MoveWindow(&rs);
	remotrcomtrol->MoveWindow(&rs);
	//�ֱ��������غ���ʾ 
	chat->ShowWindow(true); 
	screenmonitor->ShowWindow(false); 
	othermonitor->ShowWindow(false); 
	remotrcomtrol->ShowWindow(false);
	
	//����Ĭ�ϵ�ѡ� 
 	m_tab.SetCurSel(0);


	SrvPortBC=5050;
	////////////////////////////////////////////////////
	///////�㲥�׽���
	sockSrv= ::socket(AF_INET, SOCK_DGRAM, 0);
	int iMode = 1; //0������
	ioctlsocket(sockSrv,FIONBIO, (u_long FAR*) &iMode);//����������
	
	
	addrCliInfo.sin_family = AF_INET;
	addrCliInfo.sin_addr.S_un.S_addr = INADDR_ANY;	
	addrCliInfo.sin_port = ::ntohs(SrvPortBC);
	if(::bind(sockSrv, (sockaddr*)&addrCliInfo, sizeof(addrCliInfo)) == SOCKET_ERROR)
	{MessageBox("�׽��ְ�ʧ�ܣ�");}

	chat->EnableWindow(false);
	remotrcomtrol->EnableWindow(false);
	othermonitor->EnableWindow(false);
	screenmonitor->EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMonitorSercverDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialog::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMonitorSercverDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMonitorSercverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
#endif

void CMonitorSercverDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel = m_tab.GetCurSel(); 
	switch(CurSel) 
	{ 
	case 0:
		chat->ShowWindow(true); 
		screenmonitor->ShowWindow(false); 
		othermonitor->ShowWindow(false);
		remotrcomtrol->ShowWindow(false);
		break; 
	case 1: 
		chat->ShowWindow(false); 
		screenmonitor->ShowWindow(true); 
		othermonitor->ShowWindow(false);
		remotrcomtrol->ShowWindow(false); 
		break; 
	case 2: 
		chat->ShowWindow(false); 
		screenmonitor->ShowWindow(false); 
		othermonitor->ShowWindow(true);
		remotrcomtrol->ShowWindow(false); 
		break; 
	case 3: 
		chat->ShowWindow(false); 
		screenmonitor->ShowWindow(false); 
		othermonitor->ShowWindow(false);
		remotrcomtrol->ShowWindow(true); 
		break; 
	default: 
		; 
	}     
 
	*pResult = 0;
}



void CMonitorSercverDlg::OnBtnstart() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,500,NULL);
	T1state=true;
	T2state=false;
	
	GetDlgItem(IDC_BTNSTART)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTNSTART)->SetWindowText("��ȴ�...");
}

void CMonitorSercverDlg::OnTimer(UINT nIDEvent) 
{
	CString temp;
	temp.Format("");
	switch(nIDEvent)
	{
	case 1:// ���չ㲥
		if(Listen(temp)>0)
		{
			////////////������յ���CLIENTINFO��ͷ�Ŀͻ�����Ϣ     CLIENTINFO:NAME;192.0.0.0
			if (temp.Left(10)=="CLIENTINFO")
			{ifconnected();}
		}
		break;
	case 2:
		if (Listen(temp)>0)
		{
			DealMsg(temp);			
		}
		break;
	}	
	CDialog::OnTimer(nIDEvent);
}
int CMonitorSercverDlg::Listen(CString& t)
{
	int len=sizeof(SOCKADDR);
	char recvbuf[100]={0};
	int n= recvfrom(sockSrv,recvbuf,100,0,(SOCKADDR*)&addrCliInfo,&len);
	if (n>0)
	{t=recvbuf;}
	return n;
}
int CMonitorSercverDlg::SendMsg(CString msg)
{
	char *sendbuf;
	sendbuf=msg.GetBuffer(msg.GetLength());	
	int n=sendto(sockSrv,sendbuf,strlen(sendbuf)+1,0,(SOCKADDR*)&addrCliInfo,sizeof(SOCKADDR));
	return n;
}
void CMonitorSercverDlg::ifconnected()
{
	for(int i=0;i<5;i++)
	{
		SendMsg("CONNECTED");
	}
	
	if (T1state==true)
	{
		KillTimer(1);
		T1state=false;
	}
	GetDlgItem(IDC_BTNSTART)->SetWindowText("������");

	
	chat->EnableWindow(true);
	remotrcomtrol->EnableWindow(true);
	othermonitor->EnableWindow(true);
	screenmonitor->EnableWindow(true);
	
	
	if (T2state==false)
	{
		SetTimer(2,500,NULL);
		T2state=true;
	}
}

bool CMonitorSercverDlg::DealMsg(CString msg)////remotecontrol(COMMAND)  chat(chat)   othercontrol(Other)   screen(SCREEN)
{
	if ("&DISCONNECTED&"==msg.Left(14))
	{
		if (T2state==true)
		{
			KillTimer(2);
			T2state=false;
		}
		GetDlgItem(IDC_BTNSTART)->SetWindowText("��ʼ");
		GetDlgItem(IDC_BTNSTART)->EnableWindow(TRUE);
		chat->EnableWindow(false);
		remotrcomtrol->EnableWindow(false);
		othermonitor->EnableWindow(false);
		screenmonitor->EnableWindow(false);


		return true;
	}
	else if ("&COMMAND"==msg.Left(8))
	{
		DealRemoteControl(msg);
		return true;
	}
	else if ("&CHAT"==msg.Left(5))
	{
		DealChat(msg);
		return true;
	}
	else if ("&OTHER"==msg.Left(6))
	{
		DealOtherControl(msg);
		return true;
	}
	else if ("&SCREEN"==msg.Left(7))
	{
		DealScreenMonitor(msg);
		return true;
	}
	return true;
}
void CMonitorSercverDlg::DealChat(CString msg)
{
	CString t;
	chat->GetDlgItem(IDC_EDITMSG)->GetWindowText(t);
	
	t+="--";
	t+=msg.Mid(6);
	t+="\r\n";
	chat->GetDlgItem(IDC_EDITMSG)->SetWindowText(t);
}
void CMonitorSercverDlg::DealRemoteControl(CString msg)
{
	;
}
void CMonitorSercverDlg::DealOtherControl(CString msg)
{
	if ("&OTHER_GETCLIPBOARD&"==msg.Left(20))
	{
		othermonitor->GetDlgItem(IDC_EDITCLIPBOARD)->SetWindowText(msg.Mid(20));
	}
	else if ("&OTHER_SETONSTART_SUCCESS&"==msg.Left(26))
	{
		MessageBox("����������ɹ���");
	}
	else if ("&OTHER_SETONSTART_ERROR&"==msg.Left(26))
	{
		MessageBox("����������ʧ�ܣ�");
	}

}
void CMonitorSercverDlg::DealScreenMonitor(CString msg)
{
	;
}


void CMonitorSercverDlg::OnBtnsetvisable() 
{
	// TODO: Add your control notification handler code here
	if ( BST_CHECKED == IsDlgButtonChecked(IDC_CHECKVISABLE))
	{
		// ��ѡ
		CString t="&SET_VISABLE&";
		SendMsg(t);
	}
	else
	{
		CString t="&SET_INVISABLE&";
		SendMsg(t);
	}

}

void CMonitorSercverDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	SendMsg("&DISCONNECTED&");
	CDialog::OnClose();
}
