
// TextRgnDoc.cpp : CTextRgnDoc 클래스의 구현
//

#include "stdafx.h"
#include "TextRgn.h"

#include "TextRgnDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextRgnDoc

IMPLEMENT_DYNCREATE(CTextRgnDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextRgnDoc, CDocument)
END_MESSAGE_MAP()


// CTextRgnDoc 생성/소멸

CTextRgnDoc::CTextRgnDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CTextRgnDoc::~CTextRgnDoc()
{
}

BOOL CTextRgnDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CTextRgnDoc serialization

void CTextRgnDoc::Serialize(CArchive& ar)
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


// CTextRgnDoc 진단

#ifdef _DEBUG
void CTextRgnDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextRgnDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTextRgnDoc 명령
