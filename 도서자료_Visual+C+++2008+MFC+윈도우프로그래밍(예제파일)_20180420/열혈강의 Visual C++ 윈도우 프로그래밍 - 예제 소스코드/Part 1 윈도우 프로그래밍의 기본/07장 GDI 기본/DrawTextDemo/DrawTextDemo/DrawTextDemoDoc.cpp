
// DrawTextDemoDoc.cpp : CDrawTextDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "DrawTextDemo.h"

#include "DrawTextDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawTextDemoDoc

IMPLEMENT_DYNCREATE(CDrawTextDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawTextDemoDoc, CDocument)
END_MESSAGE_MAP()


// CDrawTextDemoDoc 생성/소멸

CDrawTextDemoDoc::CDrawTextDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDrawTextDemoDoc::~CDrawTextDemoDoc()
{
}

BOOL CDrawTextDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDrawTextDemoDoc serialization

void CDrawTextDemoDoc::Serialize(CArchive& ar)
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


// CDrawTextDemoDoc 진단

#ifdef _DEBUG
void CDrawTextDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawTextDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawTextDemoDoc 명령
