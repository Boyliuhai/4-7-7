// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "4-7-7.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg �Ի���

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
{
	m_bIsCreate = FALSE;
}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_num1);
	//  DDX_Control(pDX, IDC_EDIT2, m_num2);
	//  DDX_Control(pDX, IDC_EDIT3, m_num3);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
//	ON_WM_APPCOMMAND()
ON_BN_CLICKED(IDC_BTN_ADD, &CTestDlg::OnClickedBtnAdd)
ON_STN_CLICKED(IDC_NUMBER1, &CTestDlg::OnStnClickedNumber1)
ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
ON_STN_CLICKED(IDC_SEPARATOR, &CTestDlg::OnStnClickedSeparator)
ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������


//void CTestDlg::OnAppCommand(CWnd* pWnd, UINT nCmd, UINT nDevice, UINT nKey)
//{
//	// �ù���Ҫ��ʹ�� Windows 2000 ����߰汾��
//	// ���� _WIN32_WINNT �� WINVER ���� >= 0x0500��
//	CDialogEx::OnAppCommand(pWnd, nCmd, nDevice, nKey);
//}


void CTestDlg::OnClickedBtnAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//static BOOL bIsCreate = FALSE;
	////if (m_bIsCreate == FALSE)
	//if(bIsCreate==FALSE)
	//{
	//	m_btn.Create("ά��", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD,
	//		CRect(0, 0, 100, 100), this, 123);
	//	bIsCreate = TRUE;
	//	//m_bIsCreate = TRUE;
	//}
	//else
	//{
	//	m_btn.DestroyWindow();
	//	//m_bIsCreate = FALSE;
	//	bIsCreate = FALSE;
	//}

	/*if (!m_btn.m_hWnd)
	{
		m_btn.Create("ά��", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD,
			CRect(0, 0, 100, 100), this, 123);
	}
	else
	{
		m_btn.DestroyWindow();
	}*/
	//������1
	//int num1, num2, num3;
	//char ch1[10], ch2[10], ch3[10];
	//GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	//GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 10);
	//num1 = atoi(ch1);
	//num2 = atoi(ch2);
	//num3 = num1 + num2;
	//_itoa_s(num3, ch3, 10);//10�ǽ���
	//GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);

	//������2
	//int num1, num2, num3;
	//char ch1[10], ch2[10], ch3[10];
	//GetDlgItemText(IDC_EDIT1, ch1, 10);
	//GetDlgItemText(IDC_EDIT2, ch2, 10);
	////GetDlgItemText��C++�еĺ�����������������Ի����Ի�����
	////�Ŀؼ���صı�����ı���GetDlgItemText��Ա�������ı�������
	////lpStrָ���λ�ò����ؿ������ֽڵ���Ŀ��
	//num1 = atoi(ch1);
	//num2 = atoi(ch2);
	//num3 = num1 + num2;
	//_itoa_s(num3, ch3, 10);//10�ǽ���

	//SetDlgItemText(IDC_EDIT3, ch3);//SetDlgItemText��һ�ֺ�����
	//���������öԻ����пؼ����ı��ͱ��⡣
	//����ԭ����BOOLSetDlgltemText(HWND hDlg,int nlDDlgltem,LPCTSTR IpString)��

	//������3
	/*int num1, num2, num3;
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);

	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);*/

	//������4

	//UpdateData();
	//m_num3 = m_num1 + m_num2;
	//UpdateData(FALSE);
	//UpdateDataˢ�µ��ǵ�ǰ�Ի���
	//UpdateData(true);//���ڽ���Ļ�Ͽؼ��е����ݽ����������С�
	//UpdateData(false);//���ڽ���������Ļ�ж�Ӧ�ؼ�����ʾ������

	//������5//�ؼ�����

	//int num1, num2, num3;
	//char ch1[10], ch2[10], ch3[10];

	//m_edit1.GetWindowText(ch1, 10);
	//m_edit2.GetWindowText(ch2, 10);

	//num1 = atoi(ch1);
	//num2=  atoi(ch2);
	//num3 = num1 + num2;
	//_itoa_s(num3, ch3, 10);

	//m_edit3.SetWindowText(ch3);

	//������6
	//int num1, num2, num3;
	//char ch1[10], ch2[10], ch3[10];

	///*::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//::SendMessage(m_edit1.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//GetDlgItem(IDC_EDIT1)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);*/
	//m_edit1.SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	//m_edit2.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	//num1 = atoi(ch1);
	//num2=  atoi(ch2);
	//num3 = num1 + num2;
	//_itoa_s(num3, ch3, 10);

	//m_edit3.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3);

	//������7
	int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);
	num1 = atoi(ch1);
	num2=  atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10);
	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL,1,3);
	m_edit3.SetFocus();

}


void CTestDlg::OnStnClickedNumber1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	if (GetDlgItem(IDC_NUMBER1)->GetWindowText(str), str == "Number1:")
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowText("��ֵ1:");
	}
	else
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowText("Number1:");
	}
}


void CTestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == "����<<")
	{
		SetDlgItemText(IDC_BUTTON2, "��չ>>");
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, "����<<");
	}

	static CRect rectLarge;
	static CRect rectSmall;

	if (rectLarge.IsRectNull())
	{
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);

		rectSmall.left = rectLarge.left;
		rectSmall.top= rectLarge.top;
		rectSmall.right = rectLarge.right;
		rectSmall.bottom = rectSeparator.bottom;
	}
	if (str == "����<<")
	{
		SetWindowPos(NULL, 0, 0, rectSmall.Width(),rectSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	else
	{
		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
}


void CTestDlg::OnStnClickedSeparator()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CTestDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���ȱʡ��ť
	//CDialogEx::OnOK();
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();
	//GetFocus()->GetNextWindow()->SetFocus();
	//����ȷ����ǰ����λ���ĸ��ؼ��ϡ��﷨GetFocus ( )
	//����ֵGraphicObject������ִ�гɹ�ʱ���ص�ǰ�õ�����ؼ������ã�
	//��������ʱ������Ч���á�
	GetNextDlgTabItem(GetFocus())->SetFocus();
}

WNDPROC prevProc;

LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	if (uMsg == WM_CHAR && wParam == 0x0d)
	{
		//::SetFocus(::GetNextWindow(hwnd, GW_HWNDNEXT));
		//SetFocus(::GetWindow(hwnd, GW_HWNDNEXT));
		SetFocus(::GetNextDlgTabItem(::GetParent(hwnd), hwnd, FALSE));

		return 1;
	}
	else
	{
		return prevProc(hwnd, uMsg, wParam, lParam);
	}
}

BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (LONG)WinSunProc);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
