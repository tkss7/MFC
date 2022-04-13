

class CMyDoc : public CDocument {
public:
	DECLARE_DYNCREATE(CMyDoc);
	//새문서 기능 구현 함수 
	virtual BOOL OnNewDocument() override;
	//파일에 읽기/쓰기를 담당하는 함수 
	virtual void Serialize(CArchive& ar) override;
};
