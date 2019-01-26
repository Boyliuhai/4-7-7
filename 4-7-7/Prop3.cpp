// Prop3.cpp : 实现文件
//

#include "stdafx.h"
#include "4-7-7.h"
#include "Prop3.h"
#include "afxdialogex.h"


// CProp3 对话框

IMPLEMENT_DYNAMIC(CProp3, CPropertyPage)

CProp3::CProp3()
	: CPropertyPage(IDD_PROPPAGE_LARGE1)
{

	m_strSalary = _T("");
}

CProp3::~CProp3()
{
}

void CProp3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProp3, CPropertyPage)
	
END_MESSAGE_MAP()


// CProp3 消息处理程序


BOOL CProp3::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}


BOOL CProp3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("1000元以下");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("1000元-2000元");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("2000元-3000元");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("3000元以上");

	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL CProp3::OnWizardFinish()
{
	// TODO: 在此添加专用代码和/或调用基类
	int index;
	index = ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetCurSel();
	//在MFC的不同控件中，都可以见到GetCurSel函数。从函数名角度看，适用于获取当前光标的位置。
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetLBText(index, m_strSalary);
	return CPropertyPage::OnWizardFinish();
}
