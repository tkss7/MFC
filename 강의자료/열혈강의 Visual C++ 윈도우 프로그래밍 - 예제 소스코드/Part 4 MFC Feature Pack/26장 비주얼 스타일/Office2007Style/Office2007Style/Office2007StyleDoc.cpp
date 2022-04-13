// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// Office2007StyleDoc.cpp : COffice2007StyleDoc 클래스의 구현
//

#include "stdafx.h"
#include "Office2007Style.h"

#include "Office2007StyleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COffice2007StyleDoc

IMPLEMENT_DYNCREATE(COffice2007StyleDoc, CDocument)

BEGIN_MESSAGE_MAP(COffice2007StyleDoc, CDocument)
END_MESSAGE_MAP()


// COffice2007StyleDoc 생성/소멸

COffice2007StyleDoc::COffice2007StyleDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

COffice2007StyleDoc::~COffice2007StyleDoc()
{
}

BOOL COffice2007StyleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// COffice2007StyleDoc serialization

void COffice2007StyleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// COffice2007StyleDoc 진단

#ifdef _DEBUG
void COffice2007StyleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COffice2007StyleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COffice2007StyleDoc 명령
