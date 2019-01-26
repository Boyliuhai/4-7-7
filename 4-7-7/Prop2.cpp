// Prop2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4-7-7.h"
#include "Prop2.h"
#include "afxdialogex.h"


// CProp2 �Ի���

IMPLEMENT_DYNAMIC(CProp2, CPropertyPage)

CProp2::CProp2()
	: CPropertyPage(IDD_PROPPAGE_LARGE2)
	, m_football(FALSE)
	, m_basketball(FALSE)
	, m_volleyball(FALSE)
	, m_swim(FALSE)
{

}

CProp2::~CProp2()
{
}

void CProp2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK2, m_football);
	DDX_Check(pDX, IDC_CHECK4, m_basketball);
	DDX_Check(pDX, IDC_CHECK3, m_volleyball);
	DDX_Check(pDX, IDC_CHECK5, m_swim);
}


BEGIN_MESSAGE_MAP(CProp2, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 ��Ϣ��������


BOOL CProp2::OnSetActive()
{
	// TODO: �ڴ�����ר�ô����/����û���
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}


LRESULT CProp2::OnWizardNext()
{
	// TODO: �ڴ�����ר�ô����/����û���
	UpdateData();//��ס����������������
	if (m_football || m_basketball || m_volleyball || m_swim)
	{
		return CPropertyPage::OnWizardNext();
	}
	else
	{
		MessageBox("��ѡ�������Ȥ����");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}