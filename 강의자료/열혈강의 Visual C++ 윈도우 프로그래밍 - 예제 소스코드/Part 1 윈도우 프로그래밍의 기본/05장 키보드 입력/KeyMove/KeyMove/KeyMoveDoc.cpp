
// KeyMoveDoc.cpp : CKeyMoveDoc 클래스의 구현
//

#include "stdafx.h"
#include "KeyMove.h"

#include "KeyMoveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyMoveDoc

IMPLEMENT_DYNCREATE(CKeyMoveDoc, CDocument)

BEGIN_MESSAGE_MAP(CKeyMoveDoc, CDocument)
END_MESSAGE_MAP()


// CKeyMoveDoc 생성/소멸

CKeyMoveDoc::CKeyMoveDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CKeyMoveDoc::~CKeyMoveDoc()
{
}

BOOL CKeyMoveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CKeyMoveDoc serialization

void CKeyMoveDoc::Serialize(CArchive& ar)
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


// CKeyMoveDoc 진단

#ifdef _DEBUG
void CKeyMoveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKeyMoveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKeyMoveDoc 명령
