
// TextOutDemoDoc.cpp : CTextOutDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "TextOutDemo.h"

#include "TextOutDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextOutDemoDoc

IMPLEMENT_DYNCREATE(CTextOutDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextOutDemoDoc, CDocument)
END_MESSAGE_MAP()


// CTextOutDemoDoc 생성/소멸

CTextOutDemoDoc::CTextOutDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CTextOutDemoDoc::~CTextOutDemoDoc()
{
}

BOOL CTextOutDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CTextOutDemoDoc serialization

void CTextOutDemoDoc::Serialize(CArchive& ar)
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


// CTextOutDemoDoc 진단

#ifdef _DEBUG
void CTextOutDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextOutDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTextOutDemoDoc 명령
