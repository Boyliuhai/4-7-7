#pragma once
#include "afxwin.h"
#include"WeiXinBtn1.h"

// CTaoPao �Ի���

class CTaoPao : public CDialogEx
{
	DECLARE_DYNAMIC(CTaoPao)

public:
	CTaoPao(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTaoPao();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CWeiXinBtn1 m_btn1;
	CWeiXinBtn1 m_btn2;
	virtual BOOL OnInitDialog();
};
