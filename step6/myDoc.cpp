#include"pch.h"
#include"myDoc.h"

IMPLEMENT_DYNCREATE(CMyDoc, CDocument);

//새문서 기능 구현 함수 
BOOL CMyDoc:: OnNewDocument() {
	return TRUE;
}
//파일에 읽기/쓰기를 담당하는 함수 
void CMyDoc::Serialize(CArchive& ar){

}
