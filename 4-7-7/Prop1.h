#pragma once


// CProp1 �Ի���

class CProp1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1)

public:
	CProp1();
	virtual ~CProp1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_LARGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	int m_occupation;
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();
	CString m_workAddr;
};
