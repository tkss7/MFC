#pragma once


// CMySliderCtrl

class CMySliderCtrl : public CSliderCtrl
{
	DECLARE_DYNAMIC(CMySliderCtrl)

public:
	CMySliderCtrl();
	virtual ~CMySliderCtrl();

	CProgressCtrl*		m_pProgress;
	BOOL				m_bSelected;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void SetProgress(CProgressCtrl* pProgress);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


