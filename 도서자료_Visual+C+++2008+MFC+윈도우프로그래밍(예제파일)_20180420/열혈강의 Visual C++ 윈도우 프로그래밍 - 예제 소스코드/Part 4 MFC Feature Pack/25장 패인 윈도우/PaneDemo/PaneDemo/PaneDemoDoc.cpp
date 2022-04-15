
// PaneDemoDoc.cpp : CPaneDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "PaneDemo.h"

#include "PaneDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaneDemoDoc

IMPLEMENT_DYNCREATE(CPaneDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaneDemoDoc, CDocument)
END_MESSAGE_MAP()


// CPaneDemoDoc 생성/소멸

CPaneDemoDoc::CPaneDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPaneDemoDoc::~CPaneDemoDoc()
{
}

BOOL CPaneDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPaneDemoDoc serialization

void CPaneDemoDoc::Serialize(CArchive& ar)
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


// CPaneDemoDoc 진단

#ifdef _DEBUG
void CPaneDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaneDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPaneDemoDoc 명령
