
// GdiplusPolygonDoc.cpp : CGdiplusPolygonDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusPolygon.h"

#include "GdiplusPolygonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusPolygonDoc

IMPLEMENT_DYNCREATE(CGdiplusPolygonDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusPolygonDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusPolygonDoc 생성/소멸

CGdiplusPolygonDoc::CGdiplusPolygonDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusPolygonDoc::~CGdiplusPolygonDoc()
{
}

BOOL CGdiplusPolygonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusPolygonDoc serialization

void CGdiplusPolygonDoc::Serialize(CArchive& ar)
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


// CGdiplusPolygonDoc 진단

#ifdef _DEBUG
void CGdiplusPolygonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusPolygonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusPolygonDoc 명령
