// TaoPao.cpp : 实现文件
//

#include "stdafx.h"
#include "4-7-7.h"
#include "TaoPao.h"
#include "afxdialogex.h"
#include "WeiXinBtn1.h"

// CTaoPao 对话框

IMPLEMENT_DYNAMIC(CTaoPao, CDialogEx)

CTaoPao::CTaoPao(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{

}

CTaoPao::~CTaoPao()
{
}

void CTaoPao::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	//  DDX_Control(pDX, IDC_BUTTON2, m_btn2);
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
}


BEGIN_MESSAGE_MAP(CTaoPao, CDialogEx)
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CTaoPao 消息处理程序


//void CTaoPao::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	ShowWindow(SW_HIDE);
//	m_pBtn->ShowWindow(SW_SHOW);
//	CDialogEx::OnMouseMove(nFlags, point);
//}


//BOOL CTaoPao::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	// TODO:  在此添加额外的初始化
//	m_btn1.m_pBtn = &m_btn2;
//	m_btn2.m_pBtn = &m_btn1;
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // 异常: OCX 属性页应返回 FALSE
//}


BOOL CTaoPao::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
		m_btn1.m_pBtn = &m_btn2;
		m_btn2.m_pBtn = &m_btn1;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
