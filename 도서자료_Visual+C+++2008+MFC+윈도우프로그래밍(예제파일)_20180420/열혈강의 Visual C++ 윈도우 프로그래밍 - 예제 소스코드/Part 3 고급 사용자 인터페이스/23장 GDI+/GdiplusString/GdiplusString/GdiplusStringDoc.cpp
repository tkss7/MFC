
// GdiplusStringDoc.cpp : CGdiplusStringDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusString.h"

#include "GdiplusStringDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusStringDoc

IMPLEMENT_DYNCREATE(CGdiplusStringDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusStringDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusStringDoc 생성/소멸

CGdiplusStringDoc::CGdiplusStringDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusStringDoc::~CGdiplusStringDoc()
{
}

BOOL CGdiplusStringDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusStringDoc serialization

void CGdiplusStringDoc::Serialize(CArchive& ar)
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


// CGdiplusStringDoc 진단

#ifdef _DEBUG
void CGdiplusStringDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusStringDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusStringDoc 명령
