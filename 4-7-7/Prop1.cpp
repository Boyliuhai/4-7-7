// Prop1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4-7-7.h"
#include "Prop1.h"
#include "afxdialogex.h"


// CProp1 �Ի���

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


// CProp1 ��Ϣ��������


BOOL CProp1::OnSetActive()//�������Ա�����ť��ҳ���û�ѡ�񲢳�Ϊ�ҳʱ���˳�Ա�����ɿ�ܵ��á�
{
	// TODO: �ڴ�����ר�ô����/����û���
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}


LRESULT CProp1::OnWizardNext()
{
	// TODO: �ڴ�����ר�ô����/����û���
	UpdateData();
	//��˵����:���UpdateData(TRUE) == ���ؼ���ֵ��ֵ����Ա����;
	//UpdateData(FALSE) == ����Ա������ֵ��ֵ���ؼ���
	if (m_occupation ==-1)
	{
		MessageBox("��ѡ�����ְҵ");
		return -1;
	}
	if (m_workAddr == "")
	{
		MessageBox("��ѡ����Ĺ����ص�");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}


BOOL CProp1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	//����
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("����");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("�人");
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString("�Ϻ�");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}