
// VirtualButtonDoc.h : CVirtualButtonDoc 클래스의 인터페이스
//


#pragma once


class CVirtualButtonDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CVirtualButtonDoc();
	DECLARE_DYNCREATE(CVirtualButtonDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 구현입니다.
public:
	virtual ~CVirtualButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};


