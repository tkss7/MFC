
// HomeWorkDoc.h: CHomeWorkDoc 클래스의 인터페이스
//


#pragma once

#include <vector>
using namespace std;

//폭포수 개발 방법론(si) : 설계(구조)를 먼저한다 
//에자일 방법론(tdd -> bdd : 리펙토링)


class CDrawLine {
public:
	COLORREF m_penColor;
	int m_nWidth;
	vector<CPoint> m_array;
public:
	void clear() {
		m_array.clear();
	}

};

class CHomeWorkDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CHomeWorkDoc() noexcept;
	DECLARE_DYNCREATE(CHomeWorkDoc)

// 특성입니다.
public:
	//COLORREF m_penColor;
	//vector<CPoint> m_array;
	CDrawLine m_line;
	vector<CDrawLine> m_lines;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CHomeWorkDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
