
// FrameRgnDoc.cpp : CFrameRgnDoc 클래스의 구현
//

#include "stdafx.h"
#include "FrameRgn.h"

#include "FrameRgnDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFrameRgnDoc

IMPLEMENT_DYNCREATE(CFrameRgnDoc, CDocument)

BEGIN_MESSAGE_MAP(CFrameRgnDoc, CDocument)
END_MESSAGE_MAP()


// CFrameRgnDoc 생성/소멸

CFrameRgnDoc::CFrameRgnDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CFrameRgnDoc::~CFrameRgnDoc()
{
}

BOOL CFrameRgnDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CFrameRgnDoc serialization

void CFrameRgnDoc::Serialize(CArchive& ar)
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


// CFrameRgnDoc 진단

#ifdef _DEBUG
void CFrameRgnDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFrameRgnDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFrameRgnDoc 명령
