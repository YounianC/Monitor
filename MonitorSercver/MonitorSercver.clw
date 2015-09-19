; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRemotecontrol
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MonitorSercver.h"

ClassCount=6
Class1=CMonitorSercverApp
Class2=CMonitorSercverDlg
Class3=CChat

ResourceCount=6
Resource1=IDD_CHAT
Resource2=IDR_MAINFRAME
Resource3=IDD_OTHERMONITOR
Resource4=IDD_MONITORSERCVER_DIALOG
Resource5=IDD_SCREENMONITOR
Class4=COtherMonitor
Class5=CRemotecontrol
Class6=CScreenMonitor
Resource6=IDD_REMOTECONTROL

[CLS:CMonitorSercverApp]
Type=0
HeaderFile=MonitorSercver.h
ImplementationFile=MonitorSercver.cpp
Filter=N

[CLS:CMonitorSercverDlg]
Type=0
HeaderFile=MonitorSercverDlg.h
ImplementationFile=MonitorSercverDlg.cpp
Filter=D
LastObject=IDC_BUTTON1
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_MONITORSERCVER_DIALOG]
Type=1
Class=CMonitorSercverDlg
ControlCount=4
Control1=IDC_CHECKVISABLE,button,1342242819
Control2=IDC_TAB,SysTabControl32,1342177280
Control3=IDC_BTNSTART,button,1342242816
Control4=IDC_BTNSETVISABLE,button,1342242816

[DLG:IDD_CHAT]
Type=1
Class=CChat
ControlCount=3
Control1=IDC_EDITMSG,edit,1352732868
Control2=IDC_EDITSEND,edit,1350635652
Control3=IDC_BTNSEND,button,1342242816

[DLG:IDD_SCREENMONITOR]
Type=1
Class=CScreenMonitor
ControlCount=3
Control1=IDC_STATICSCREEN,static,1342177294
Control2=IDC_BUTTONSTART,button,1342242816
Control3=IDC_BUTTONSTOP,button,1342242816

[DLG:IDD_OTHERMONITOR]
Type=1
Class=COtherMonitor
ControlCount=17
Control1=IDC_EDITCLIPBOARD,edit,1350631556
Control2=IDC_BUTTONGET,button,1342242816
Control3=IDC_BUTTONSET,button,1342242816
Control4=IDC_BUTTONCOPY,button,1342242816
Control5=IDC_EPATHTOSAVE,edit,1350631552
Control6=IDC_BTNSENDFILE,button,1342242816
Control7=IDC_EPATHOFFILE,edit,1350631552
Control8=IDC_BTNMOREFILE,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342177287
Control13=IDC_EDITPATHTOCOPY,edit,1350631556
Control14=IDC_BTNSELFCOPY,button,1342242816
Control15=IDC_BTNONSTART,button,1342242816
Control16=IDC_EDITBATCONTROL,edit,1352732740
Control17=IDC_BATCONTROL,button,1342242816

[DLG:IDD_REMOTECONTROL]
Type=1
Class=CRemotecontrol
ControlCount=8
Control1=IDC_EDITNAME,edit,1350631552
Control2=IDC_BTN_LOGOFF,button,1342242816
Control3=IDC_BTN_SHUTDOWN,button,1342243584
Control4=IDC_BUTTONHIDEDESK,button,1342243584
Control5=IDC_BUTTONSHOWDESK,button,1342242816
Control6=IDC_BTN_REBOOT,button,1342242816
Control7=IDC_BTNTURNOFFSCR,button,1342242816
Control8=IDC_BTNTURNONSCR,button,1342242816

[CLS:CChat]
Type=0
HeaderFile=Chat.h
ImplementationFile=Chat.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDITMSG
VirtualFilter=dWC

[CLS:COtherMonitor]
Type=0
HeaderFile=OtherMonitor.h
ImplementationFile=OtherMonitor.cpp
BaseClass=CDialog
Filter=D
LastObject=COtherMonitor
VirtualFilter=dWC

[CLS:CRemotecontrol]
Type=0
HeaderFile=Remotecontrol.h
ImplementationFile=Remotecontrol.cpp
BaseClass=CDialog
Filter=D
LastObject=CRemotecontrol
VirtualFilter=dWC

[CLS:CScreenMonitor]
Type=0
HeaderFile=ScreenMonitor.h
ImplementationFile=ScreenMonitor.cpp
BaseClass=CDialog
Filter=D
LastObject=CScreenMonitor

