
// GdiplusBrushDoc.cpp : CGdiplusBrushDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusBrush.h"

#include "GdiplusBrushDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusBrushDoc

IMPLEMENT_DYNCREATE(CGdiplusBrushDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusBrushDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusBrushDoc 생성/소멸

CGdiplusBrushDoc::CGdiplusBrushDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusBrushDoc::~CGdiplusBrushDoc()
{
}

BOOL CGdiplusBrushDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusBrushDoc serialization

void CGdiplusBrushDoc::Serialize(CArchive& ar)
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


// CGdiplusBrushDoc 진단

#ifdef _DEBUG
void CGdiplusBrushDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusBrushDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusBrushDoc 명령
