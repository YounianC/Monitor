; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMonitorClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MonitorClient.h"

ClassCount=3
Class1=CMonitorClientApp
Class2=CMonitorClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MONITORCLIENT_DIALOG

[CLS:CMonitorClientApp]
Type=0
HeaderFile=MonitorClient.h
ImplementationFile=MonitorClient.cpp
Filter=N

[CLS:CMonitorClientDlg]
Type=0
HeaderFile=MonitorClientDlg.h
ImplementationFile=MonitorClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ChatSend

[CLS:CAboutDlg]
Type=0
HeaderFile=MonitorClientDlg.h
ImplementationFile=MonitorClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MONITORCLIENT_DIALOG]
Type=1
Class=CMonitorClientDlg
ControlCount=4
Control1=IDC_ChatRecord,edit,1352732868
Control2=IDC_BTNSTART,button,1476460544
Control3=IDC_ChatSend,edit,1350635652
Control4=IDC_BTNSEND,button,1342242816

