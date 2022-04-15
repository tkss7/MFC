
// UserMsgDemoDoc.cpp : CUserMsgDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "UserMsgDemo.h"

#include "UserMsgDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserMsgDemoDoc

IMPLEMENT_DYNCREATE(CUserMsgDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CUserMsgDemoDoc, CDocument)
END_MESSAGE_MAP()


// CUserMsgDemoDoc 생성/소멸

CUserMsgDemoDoc::CUserMsgDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CUserMsgDemoDoc::~CUserMsgDemoDoc()
{
}

BOOL CUserMsgDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CUserMsgDemoDoc serialization

void CUserMsgDemoDoc::Serialize(CArchive& ar)
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


// CUserMsgDemoDoc 진단

#ifdef _DEBUG
void CUserMsgDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUserMsgDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CUserMsgDemoDoc 명령
