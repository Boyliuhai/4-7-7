#pragma once
#include "afxwin.h"
class CWeiXinBtn1 :
	public CButton
{
public:
	CWeiXinBtn1();
	~CWeiXinBtn1();
	CWeiXinBtn1* m_pBtn;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

