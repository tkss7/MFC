#include"pch.h"
#include"myDoc.h"

IMPLEMENT_DYNCREATE(CMyDoc, CDocument);

//������ ��� ���� �Լ� 
BOOL CMyDoc:: OnNewDocument() {
	return TRUE;
}
//���Ͽ� �б�/���⸦ ����ϴ� �Լ� 
void CMyDoc::Serialize(CArchive& ar){

}
