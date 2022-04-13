 

class CMyView : public CView {
public:
	DECLARE_DYNCREATE(CMyView);
	//화면 출력에 대한 함수
	virtual void OnDraw(CDC* pDC) override;
};
