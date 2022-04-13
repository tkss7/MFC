
// SerializeDemoDoc.cpp : CSerializeDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "SerializeDemo.h"

#include "SerializeDemoDoc.h"
#include "SerializeDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSerializeDemoDoc

IMPLEMENT_DYNCREATE(CSerializeDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CSerializeDemoDoc, CDocument)
END_MESSAGE_MAP()


// CSerializeDemoDoc 생성/소멸

CSerializeDemoDoc::CSerializeDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSerializeDemoDoc::~CSerializeDemoDoc()
{
}

BOOL CSerializeDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CSerializeDemoDoc serialization

void CSerializeDemoDoc::Serialize(CArchive& ar)
{
//	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);

	CSerializeDemoView* pEditView = (CSerializeDemoView*)m_viewList.GetHead();
	pEditView->Serialize(ar);
}


// CSerializeDemoDoc 진단

#ifdef _DEBUG
void CSerializeDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSerializeDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSerializeDemoDoc 명령
