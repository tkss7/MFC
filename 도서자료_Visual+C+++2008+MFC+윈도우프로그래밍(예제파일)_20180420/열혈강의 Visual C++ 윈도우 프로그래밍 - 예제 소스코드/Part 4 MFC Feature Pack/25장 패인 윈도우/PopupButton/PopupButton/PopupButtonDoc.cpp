
// PopupButtonDoc.cpp : CPopupButtonDoc 클래스의 구현
//

#include "stdafx.h"
#include "PopupButton.h"

#include "PopupButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPopupButtonDoc

IMPLEMENT_DYNCREATE(CPopupButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CPopupButtonDoc, CDocument)
END_MESSAGE_MAP()


// CPopupButtonDoc 생성/소멸

CPopupButtonDoc::CPopupButtonDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPopupButtonDoc::~CPopupButtonDoc()
{
}

BOOL CPopupButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPopupButtonDoc serialization

void CPopupButtonDoc::Serialize(CArchive& ar)
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


// CPopupButtonDoc 진단

#ifdef _DEBUG
void CPopupButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPopupButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPopupButtonDoc 명령
