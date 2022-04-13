// FormOne.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "FormOne.h"


// CFormOne dialog

IMPLEMENT_DYNAMIC(CFormOne, CDialog)

CFormOne::CFormOne(CWnd* pParent /*=NULL*/)
	: CDialog(CFormOne::IDD, pParent)
{

}

CFormOne::~CFormOne()
{
}

void CFormOne::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFormOne, CDialog)
END_MESSAGE_MAP()


// CFormOne message handlers
