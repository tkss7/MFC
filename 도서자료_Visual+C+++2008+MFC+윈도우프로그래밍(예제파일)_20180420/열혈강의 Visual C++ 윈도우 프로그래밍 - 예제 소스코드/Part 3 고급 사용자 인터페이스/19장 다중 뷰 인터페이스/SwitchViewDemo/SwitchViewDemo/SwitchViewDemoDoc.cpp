
// SwitchViewDemoDoc.cpp : CSwitchViewDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "SwitchViewDemo.h"

#include "SwitchViewDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSwitchViewDemoDoc

IMPLEMENT_DYNCREATE(CSwitchViewDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CSwitchViewDemoDoc, CDocument)
END_MESSAGE_MAP()


// CSwitchViewDemoDoc 생성/소멸

CSwitchViewDemoDoc::CSwitchViewDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSwitchViewDemoDoc::~CSwitchViewDemoDoc()
{
}

BOOL CSwitchViewDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CSwitchViewDemoDoc serialization

void CSwitchViewDemoDoc::Serialize(CArchive& ar)
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


// CSwitchViewDemoDoc 진단

#ifdef _DEBUG
void CSwitchViewDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSwitchViewDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSwitchViewDemoDoc 명령
