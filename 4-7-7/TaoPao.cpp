// TaoPao.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4-7-7.h"
#include "TaoPao.h"
#include "afxdialogex.h"
#include "WeiXinBtn1.h"

// CTaoPao �Ի���

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


// CTaoPao ��Ϣ�������


//void CTaoPao::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	ShowWindow(SW_HIDE);
//	m_pBtn->ShowWindow(SW_SHOW);
//	CDialogEx::OnMouseMove(nFlags, point);
//}


//BOOL CTaoPao::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//	m_btn1.m_pBtn = &m_btn2;
//	m_btn2.m_pBtn = &m_btn1;
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // �쳣: OCX ����ҳӦ���� FALSE
//}


BOOL CTaoPao::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
		m_btn1.m_pBtn = &m_btn2;
		m_btn2.m_pBtn = &m_btn1;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
