// TextProgressCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TextProgressDemo.h"
#include "TextProgressCtrl.h"


// CTextProgressCtrl

IMPLEMENT_DYNAMIC(CTextProgressCtrl, CProgressCtrl)

CTextProgressCtrl::CTextProgressCtrl()
{
	m_nData = 0;
}

CTextProgressCtrl::~CTextProgressCtrl()
{
}


BEGIN_MESSAGE_MAP(CTextProgressCtrl, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CTextProgressCtrl message handlers



void CTextProgressCtrl::OnPaint()
{
	CPaintDC dc(this);

	CString strTmp = _T("");
	strTmp.Format(_T("%d%%"), m_nData);

	//프로그래스 컨트롤을 둘로 나누기 위해서 윈도우 크기를 계산한다.
	CRect LeftRect, RightRect, ClientRect;
	GetClientRect(ClientRect);
	LeftRect = ClientRect;
	RightRect = ClientRect;

	//1%에 해당하는 윈도우 크기를 계산한다.
	//그리고, 둘로 나누어진 왼쪽과 오른쪽 각각에 대해서 다른 색으로 칠한다.
	LeftRect.right = (ClientRect.right * m_nData) / 100;
	RightRect.left = (ClientRect.right * m_nData) / 100;
	dc.FillSolidRect(LeftRect, RGB(0, 0, 128));
	dc.FillSolidRect(RightRect, RGB(255, 255, 255));

	//왼쪽과 오른쪽을 두 영역으로 구분한다.
	CRgn LeftRgn, RightRgn;
	LeftRgn.CreateRectRgnIndirect(LeftRect);
	RightRgn.CreateRectRgnIndirect(RightRect);
	
	//왼쪽영역에 비율 표시 텍스트를 중앙 정렬하여 출력한다.
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 255, 255));
	dc.SelectClipRgn(&LeftRgn);
	dc.DrawText(strTmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//오른쪽 영역에 비율 표시 텍스트를 중앙 정렬하여 출력한다.
	dc.SetTextColor(RGB(0, 0, 128));
	dc.SelectClipRgn(&RightRgn);
	dc.DrawText(strTmp, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CTextProgressCtrl::SetValue(int nPos)
{
	m_nData = nPos;
	RedrawWindow();
}
