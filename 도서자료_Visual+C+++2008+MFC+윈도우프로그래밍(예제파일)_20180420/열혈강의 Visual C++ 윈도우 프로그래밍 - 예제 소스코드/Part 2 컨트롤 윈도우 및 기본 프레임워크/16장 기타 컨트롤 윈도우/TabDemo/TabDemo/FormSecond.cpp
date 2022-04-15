// FormSecond.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "FormSecond.h"


// CFormSecond dialog

IMPLEMENT_DYNAMIC(CFormSecond, CDialog)

CFormSecond::CFormSecond(CWnd* pParent /*=NULL*/)
	: CDialog(CFormSecond::IDD, pParent)
{

}

CFormSecond::~CFormSecond()
{
}

void CFormSecond::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormSecond, CDialog)
END_MESSAGE_MAP()


// CFormSecond message handlers
