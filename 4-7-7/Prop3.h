#pragma once


// CProp3 �Ի���

class CProp3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp3)

public:
	CProp3();
	virtual ~CProp3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_LARGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnInitDialog();
//	afx_msg void OnCbnSelchangeCombo3();
	virtual BOOL OnWizardFinish();
	CString m_strSalary;
};