
// GdiplusTransformDoc.cpp : CGdiplusTransformDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusTransform.h"

#include "GdiplusTransformDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTransformDoc

IMPLEMENT_DYNCREATE(CGdiplusTransformDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusTransformDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusTransformDoc 생성/소멸

CGdiplusTransformDoc::CGdiplusTransformDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusTransformDoc::~CGdiplusTransformDoc()
{
}

BOOL CGdiplusTransformDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusTransformDoc serialization

void CGdiplusTransformDoc::Serialize(CArchive& ar)
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


// CGdiplusTransformDoc 진단

#ifdef _DEBUG
void CGdiplusTransformDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusTransformDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusTransformDoc 명령
