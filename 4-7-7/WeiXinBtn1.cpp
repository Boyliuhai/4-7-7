#include "stdafx.h"
#include "WeiXinBtn1.h"


CWeiXinBtn1::CWeiXinBtn1()
{
}


CWeiXinBtn1::~CWeiXinBtn1()
{
}
BEGIN_MESSAGE_MAP(CWeiXinBtn1, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CWeiXinBtn1::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	ShowWindow(SW_HIDE);
	m_pBtn->ShowWindow(SW_SHOW);
	CButton::OnMouseMove(nFlags, point);
}
