
// TimerDemoDoc.cpp : CTimerDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "TimerDemo.h"

#include "TimerDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimerDemoDoc

IMPLEMENT_DYNCREATE(CTimerDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTimerDemoDoc, CDocument)
END_MESSAGE_MAP()


// CTimerDemoDoc 생성/소멸

CTimerDemoDoc::CTimerDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CTimerDemoDoc::~CTimerDemoDoc()
{
}

BOOL CTimerDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CTimerDemoDoc serialization

void CTimerDemoDoc::Serialize(CArchive& ar)
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


// CTimerDemoDoc 진단

#ifdef _DEBUG
void CTimerDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTimerDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTimerDemoDoc 명령
