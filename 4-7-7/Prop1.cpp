// Prop1.cpp : 实现文件
//

#include "stdafx.h"
#include "4-7-7.h"
#include "Prop1.h"
#include "afxdialogex.h"


// CProp1 对话框

IMPLEMENT_DYNAMIC(CProp1, CPropertyPage)

CProp1::CProp1()
	: CPropertyPage(IDD_PROPPAGE_LARGE)
	, m_occupation(-1)
	, m_workAddr(_T(""))
{

}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_occupation);
	DDX_LBString(pDX, IDC_LIST1, m_workAddr);
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
END_MESSAGE_MAP()


// CProp1 消息处理程序


BOOL CProp1::OnSetActive()//设置属性表单按钮当页由用户选择并成为活动页时，此成员函数由框架调用。
{
	// TODO: 在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}


LRESULT CProp1::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类
	UpdateData();
	//单说就是:如果UpdateData(TRUE) == 将控件的值赋值给成员变量;
	//UpdateData(FALSE) == 将成员变量的值赋值给控件。
	if (m_occupation ==-1)
	{
		MessageBox("请选择你的职业");
		return -1;
	}
	if (m_workAddr == "")
	{
		MessageBox("请选择你的工作地点");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}


BOOL CProp1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//表单
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("北京");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("武汉");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("上海");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
