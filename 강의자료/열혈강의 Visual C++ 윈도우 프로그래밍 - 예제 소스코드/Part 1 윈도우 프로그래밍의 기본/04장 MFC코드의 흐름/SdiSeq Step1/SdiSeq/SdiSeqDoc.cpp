
// SdiSeqDoc.cpp : CSdiSeqDoc 클래스의 구현
//

#include "stdafx.h"
#include "SdiSeq.h"

#include "SdiSeqDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSeqDoc

IMPLEMENT_DYNCREATE(CSdiSeqDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiSeqDoc, CDocument)
END_MESSAGE_MAP()


// CSdiSeqDoc 생성/소멸

CSdiSeqDoc::CSdiSeqDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSdiSeqDoc::~CSdiSeqDoc()
{
}

BOOL CSdiSeqDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CSdiSeqDoc serialization

void CSdiSeqDoc::Serialize(CArchive& ar)
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


// CSdiSeqDoc 진단

#ifdef _DEBUG
void CSdiSeqDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiSeqDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiSeqDoc 명령
