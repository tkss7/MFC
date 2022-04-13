// FormThird.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "FormThird.h"


// CFormThird dialog

IMPLEMENT_DYNAMIC(CFormThird, CDialog)

CFormThird::CFormThird(CWnd* pParent /*=NULL*/)
	: CDialog(CFormThird::IDD, pParent)
{

}

CFormThird::~CFormThird()
{
}

void CFormThird::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormThird, CDialog)
END_MESSAGE_MAP()


// CFormThird message handlers
