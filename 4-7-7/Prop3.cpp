// Prop3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4-7-7.h"
#include "Prop3.h"
#include "afxdialogex.h"


// CProp3 �Ի���

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


// CProp3 ��Ϣ�������


BOOL CProp3::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}


BOOL CProp3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("1000Ԫ����");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("1000Ԫ-2000Ԫ");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("2000Ԫ-3000Ԫ");
	((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString("3000Ԫ����");

	((CComboBox*)GetDlgItem(IDC_COMBO3))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CProp3::OnWizardFinish()
{
	// TODO: �ڴ����ר�ô����/����û���
	int index;
	index = ((CComboBox*)GetDlgItem(IDC_COMBO3))->GetCurSel();
	//��MFC�Ĳ�ͬ�ؼ��У������Լ���GetCurSel�������Ӻ������Ƕȿ��������ڻ�ȡ��ǰ����λ�á�
	((CComboBox*)GetDlgItem(IDC_COMBO3))->GetLBText(index, m_strSalary);
	return CPropertyPage::OnWizardFinish();
}
