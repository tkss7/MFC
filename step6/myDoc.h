

class CMyDoc : public CDocument {
public:
	DECLARE_DYNCREATE(CMyDoc);
	//������ ��� ���� �Լ� 
	virtual BOOL OnNewDocument() override;
	//���Ͽ� �б�/���⸦ ����ϴ� �Լ� 
	virtual void Serialize(CArchive& ar) override;
};
