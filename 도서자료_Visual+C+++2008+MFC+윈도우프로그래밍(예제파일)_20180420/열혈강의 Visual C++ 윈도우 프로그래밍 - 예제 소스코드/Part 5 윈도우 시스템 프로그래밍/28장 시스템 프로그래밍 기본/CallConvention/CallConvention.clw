; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCallConventionDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CallConvention.h"

ClassCount=4
Class1=CCallConventionApp
Class2=CCallConventionDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CALLCONVENTION_DIALOG

[CLS:CCallConventionApp]
Type=0
HeaderFile=CallConvention.h
ImplementationFile=CallConvention.cpp
Filter=N

[CLS:CCallConventionDlg]
Type=0
HeaderFile=CallConventionDlg.h
ImplementationFile=CallConventionDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CallConventionDlg.h
ImplementationFile=CallConventionDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CALLCONVENTION_DIALOG]
Type=1
Class=CCallConventionDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Button_cdecl,button,1342242816
Control4=IDC_Button_stdcall,button,1342242816
Control5=IDC_Button_fastcall,button,1342242816

