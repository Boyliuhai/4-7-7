
// 4-7-7View.h : CMy477View ��Ľӿ�
//

#pragma once


class CMy477View : public CView
{
protected: // �������л�����
	CMy477View();
	DECLARE_DYNCREATE(CMy477View)

// ����
public:
	CMy477Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy477View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	int m_iOccupation;
	CString m_strWorkAddr;
	BOOL m_bLike[4];
	CString m_strSalary;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBitmap bitmap;
public:
//	CString m_strline;
//	CString m_strLine;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	CString m_strLine;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_nWidth;
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
private:
	int m_nIndex;
	CMenu m_menu;
public:
	afx_msg void OnDialog();
//	afx_msg void On32781();
	afx_msg void OnTaopao();
	afx_msg void OnPropertysheet();
};

#ifndef _DEBUG  // 4-7-7View.cpp �еĵ��԰汾
inline CMy477Doc* CMy477View::GetDocument() const
   { return reinterpret_cast<CMy477Doc*>(m_pDocument); }
#endif

