#pragma once
#include "afxwin.h"


// CTestDlg �Ի���

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnAppCommand(CWnd* pWnd, UINT nCmd, UINT nDevice, UINT nKey);
	afx_msg void OnClickedBtnAdd();
private:
	CButton m_btn;
	BOOL m_bIsCreate;
public:
	afx_msg void OnStnClickedNumber1();
	int m_num1;
	int m_num2;
	int m_num3;
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnStnClickedSeparator();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};