
// ExitWinDemoDoc.cpp : CExitWinDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "ExitWinDemo.h"

#include "ExitWinDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExitWinDemoDoc

IMPLEMENT_DYNCREATE(CExitWinDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CExitWinDemoDoc, CDocument)
END_MESSAGE_MAP()


// CExitWinDemoDoc 생성/소멸

CExitWinDemoDoc::CExitWinDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CExitWinDemoDoc::~CExitWinDemoDoc()
{
}

BOOL CExitWinDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CExitWinDemoDoc serialization

void CExitWinDemoDoc::Serialize(CArchive& ar)
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


// CExitWinDemoDoc 진단

#ifdef _DEBUG
void CExitWinDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExitWinDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExitWinDemoDoc 명령
