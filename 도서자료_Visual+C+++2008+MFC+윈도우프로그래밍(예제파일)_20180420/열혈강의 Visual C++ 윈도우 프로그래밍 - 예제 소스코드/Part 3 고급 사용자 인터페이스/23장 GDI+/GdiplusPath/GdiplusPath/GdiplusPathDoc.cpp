
// GdiplusPathDoc.cpp : CGdiplusPathDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusPath.h"

#include "GdiplusPathDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusPathDoc

IMPLEMENT_DYNCREATE(CGdiplusPathDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusPathDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusPathDoc 생성/소멸

CGdiplusPathDoc::CGdiplusPathDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusPathDoc::~CGdiplusPathDoc()
{
}

BOOL CGdiplusPathDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusPathDoc serialization

void CGdiplusPathDoc::Serialize(CArchive& ar)
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


// CGdiplusPathDoc 진단

#ifdef _DEBUG
void CGdiplusPathDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusPathDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusPathDoc 명령
