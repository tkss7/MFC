
// CommandDemoDoc.cpp : CCommandDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "CommandDemo.h"

#include "CommandDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandDemoDoc

IMPLEMENT_DYNCREATE(CCommandDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCommandDemoDoc, CDocument)
//	ON_COMMAND(ID_Menu_Start, &CCommandDemoDoc::OnMenuStart)
END_MESSAGE_MAP()


// CCommandDemoDoc 생성/소멸

CCommandDemoDoc::CCommandDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CCommandDemoDoc::~CCommandDemoDoc()
{
}

BOOL CCommandDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CCommandDemoDoc serialization

void CCommandDemoDoc::Serialize(CArchive& ar)
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


// CCommandDemoDoc 진단

#ifdef _DEBUG
void CCommandDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCommandDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCommandDemoDoc 명령

void CCommandDemoDoc::OnMenuStart()
{
	AfxMessageBox(_T("시작 메뉴를 선택하였습니다. - CCommandDemoDoc"));
}
