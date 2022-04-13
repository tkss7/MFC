
// ImageOverDoc.cpp : CImageOverDoc 클래스의 구현
//

#include "stdafx.h"
#include "ImageOver.h"

#include "ImageOverDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageOverDoc

IMPLEMENT_DYNCREATE(CImageOverDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageOverDoc, CDocument)
END_MESSAGE_MAP()


// CImageOverDoc 생성/소멸

CImageOverDoc::CImageOverDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageOverDoc::~CImageOverDoc()
{
}

BOOL CImageOverDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CImageOverDoc serialization

void CImageOverDoc::Serialize(CArchive& ar)
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


// CImageOverDoc 진단

#ifdef _DEBUG
void CImageOverDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageOverDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageOverDoc 명령
