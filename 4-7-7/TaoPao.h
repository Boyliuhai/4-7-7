#pragma once
#include "afxwin.h"
#include"WeiXinBtn1.h"

// CTaoPao 对话框

class CTaoPao : public CDialogEx
{
	DECLARE_DYNAMIC(CTaoPao)

public:
	CTaoPao(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTaoPao();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CWeiXinBtn1 m_btn1;
	CWeiXinBtn1 m_btn2;
	virtual BOOL OnInitDialog();
};
