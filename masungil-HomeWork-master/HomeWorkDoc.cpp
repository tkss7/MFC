﻿
// HomeWorkDoc.cpp: CHomeWorkDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HomeWork.h"
#endif

#include "HomeWorkDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHomeWorkDoc

IMPLEMENT_DYNCREATE(CHomeWorkDoc, CDocument)

BEGIN_MESSAGE_MAP(CHomeWorkDoc, CDocument)
END_MESSAGE_MAP()


// CHomeWorkDoc 생성/소멸

CHomeWorkDoc::CHomeWorkDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHomeWorkDoc::~CHomeWorkDoc()
{
}

BOOL CHomeWorkDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	m_line.m_nWidth = 10;
	m_line.m_penColor = RGB(255, 0, 0);

	return TRUE;
}




// CHomeWorkDoc serialization

void CHomeWorkDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_lines.size();
		for (const CDrawLine& line : m_lines) {
			ar << line.m_nWidth;
			ar << line.m_penColor;
			ar << line.m_array.size();
			for (const CPoint pt : line.m_array) {
				ar << pt.x;
				ar << pt.y;
			}
		}
	}
	else
	{
		int lines_size;
		int array_size;
		CPoint pt;

		ar >> lines_size;
		for (int i = 0; i < lines_size;i++) {
			ar >> m_line.m_nWidth;
			ar >> m_line.m_penColor;
			ar >> array_size;
			m_line.clear();
			for (int j = 0; j < array_size;j++) {
				ar >> pt.x;
				ar >> pt.y;
				m_line.m_array.push_back(pt);
			}
			m_lines.push_back(m_line);
		}
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHomeWorkDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CHomeWorkDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHomeWorkDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHomeWorkDoc 진단

#ifdef _DEBUG
void CHomeWorkDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHomeWorkDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHomeWorkDoc 명령


void CHomeWorkDoc::DeleteContents()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_line.clear();
	m_lines.clear();

	CDocument::DeleteContents();
}
