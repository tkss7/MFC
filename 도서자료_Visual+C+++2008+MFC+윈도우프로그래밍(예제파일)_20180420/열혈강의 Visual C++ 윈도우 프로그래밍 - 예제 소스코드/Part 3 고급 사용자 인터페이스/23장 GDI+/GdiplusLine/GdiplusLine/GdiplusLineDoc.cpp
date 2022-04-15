
// GdiplusLineDoc.cpp : CGdiplusLineDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusLine.h"

#include "GdiplusLineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusLineDoc

IMPLEMENT_DYNCREATE(CGdiplusLineDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusLineDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusLineDoc 생성/소멸

CGdiplusLineDoc::CGdiplusLineDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiplusLineDoc::~CGdiplusLineDoc()
{
}

BOOL CGdiplusLineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiplusLineDoc serialization

void CGdiplusLineDoc::Serialize(CArchive& ar)
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


// CGdiplusLineDoc 진단

#ifdef _DEBUG
void CGdiplusLineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusLineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusLineDoc 명령
