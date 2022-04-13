
// BmpOutDemoDoc.cpp : CBmpOutDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "BmpOutDemo.h"

#include "BmpOutDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpOutDemoDoc

IMPLEMENT_DYNCREATE(CBmpOutDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpOutDemoDoc, CDocument)
END_MESSAGE_MAP()


// CBmpOutDemoDoc 생성/소멸

CBmpOutDemoDoc::CBmpOutDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CBmpOutDemoDoc::~CBmpOutDemoDoc()
{
}

BOOL CBmpOutDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CBmpOutDemoDoc serialization

void CBmpOutDemoDoc::Serialize(CArchive& ar)
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


// CBmpOutDemoDoc 진단

#ifdef _DEBUG
void CBmpOutDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpOutDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBmpOutDemoDoc 명령
