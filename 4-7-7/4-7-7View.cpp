
// 4-7-7View.cpp : CMy477View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4-7-7.h"
#endif
#include "TaoPao.h"
#include "TestDlg.h"
#include "4-7-7Doc.h"
#include "4-7-7View.h"
#include"PropSheet.h"
#include"resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy477View

IMPLEMENT_DYNCREATE(CMy477View, CView)

BEGIN_MESSAGE_MAP(CMy477View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy477View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_TIMER()
//	ON_WM_RBUTTONDOWN()
ON_COMMAND(IDM_SHOW, &CMy477View::OnShow)
ON_COMMAND(IDM_DIALOG, &CMy477View::OnDialog)
//ON_COMMAND(ID_32781, &CMy477View::On32781)
ON_COMMAND(IDM_TAOPAO, &CMy477View::OnTaopao)
ON_COMMAND(IDM_PROPERTYSHEET, &CMy477View::OnPropertysheet)
END_MESSAGE_MAP()

// CMy477View ����/����

CMy477View::CMy477View()
{
	// TODO: �ڴ˴���ӹ������
	m_ptOrigin = 0;
	/*m_bDraw = FALSE;
	m_ptOld = 0;*/
	m_strLine = _T("");
	m_nWidth = 0;
	m_nIndex = 0;
	m_iOccupation=-1;
	m_strWorkAddr="";
	memset(m_bLike,0,sizeof(m_bLike));//�����ʼ��
	m_strSalary="";
}

CMy477View::~CMy477View()
{
}

BOOL CMy477View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.lpszClass = "sunxin.org";

	/*cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
		LoadCursor(NULL, IDC_CROSS), (HBRUSH)GetStockObject(BLACK_BRUSH), 0);*/
	//Ĭ�ϵ�
		//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);
	
	return CView::PreCreateWindow(cs);
}

// CMy477View ����

void CMy477View::OnDraw(CDC* pDC)
{
	CMy477Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CFont font;
	font.CreatePointFont(200, "�����п�");

	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&font);
	CString strTemp;
	strTemp = "���ְҵ:";
	switch (m_iOccupation)
	{
	case 0:
		strTemp += "����Ա";
		break;
	case 1:
		strTemp += "ϵͳ����ʦ";
		break;
	case 2:
		strTemp += "��Ŀ����";
		break;
	default:
		break;
	}
	pDC->TextOut(0, 0, strTemp);

	strTemp = "��Ĺ����ص�:";
	strTemp += m_strWorkAddr;
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	pDC->TextOut(0, tm.tmHeight, strTemp);

	strTemp = "�����Ȥ����:";
	if (m_bLike[0])
	{
		strTemp += "����";
	}
	if (m_bLike[1])
	{
		strTemp += "����";
	}
	if (m_bLike[2])
	{
		strTemp += "����";
	}
	if (m_bLike[3])
	{
		strTemp += "��Ӿ";
	}
	pDC->TextOut(0, tm.tmHeight * 2, strTemp);

	strTemp = "���н��ˮƽ :";
	strTemp += m_strSalary;
	pDC->TextOut(0, tm.tmHeight * 3, strTemp);
	//.....................����ַ���
	//CString str("������ѧ");
	CString str;
	str = "������ѧ";
	pDC->TextOut(200, 100, str);

	CSize sz = pDC->GetTextExtent(str);//����ַ�������       �����Է�������д

	//str.LoadString(IDS_WEIXIN);
	//pDC->TextOut(0, 200, str);
	//·����
	pDC->BeginPath();
	pDC->Rectangle(200, 100, 200 + sz.cx, 100 + sz.cy);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);
	for (int i = 0; i < 530; i += 10)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(530, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 530);
	}
	//...............................

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy477View ��ӡ


void CMy477View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy477View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy477View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy477View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMy477View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy477View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy477View ���

#ifdef _DEBUG
void CMy477View::AssertValid() const
{
	CView::AssertValid();
}

void CMy477View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy477Doc* CMy477View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy477Doc)));
	return (CMy477Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy477View ��Ϣ�������


void CMy477View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//MessageBox(_T("view clicked"));
	SetCaretPos(point);//���ò��븶λ��
	m_strLine.Empty();
	m_ptOrigin = point;
	/*m_ptOrigin = m_ptOld=point;
	m_bDraw = TRUE;
	*/
	CView::OnLButtonDown(nFlags, point);
}


void CMy477View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//.........����1
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);//��ȡȫ��
	//MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//LineTo(hdc, point.x, point.y);
	//::ReleaseDC(m_hWnd, hdc);
	//..............

	//.........����2
	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/
	//...............

	//.........����3
	/*CClientDC dc(this);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/
	//................

	//.........����4
	//CClientDC dc(GetParent());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................

	//.........����5
	//CWindowDC dc(GetParent());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................

	//.........����6
	//CWindowDC dc(GetDesktopWindow());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................
	 
	//.........����7
	//CPen pen(PS_SOLID, 10, RGB(255, 0, 0));//ʵ��
	//CClientDC dc(this);
	//CPen *pOldPen = dc.SelectObject(&pen);//���ǽ��´����Ļ�����Ϊ��ǰ���ʣ�����SelectObject()�ķ���ֵ�����½�����֮ǰ�Ļ��ʵ�
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//dc.SelectObject(pOldPen);//�ָ�ԭ���Ļ��ʣ���ʵ���Ӧ����һ��ϰ�����⣬���ָ�����Ҳ���󣬵����㲻�ָ��Ļ���������DC��ʱ������õľ��������ڴ����Ļ��ʶ�����Ĭ�ϵĻ��ʡ�Ҫ���ɺ�ϰ�ߣ������Ժ���ܻ������
	 //................

	 //.........����8
	//CBrush brush(RGB(255, 0, 0));

	/*CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bitmap);
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin, point), &brush);*/
	 //................

	 //.........����͸����ˢ9
	//CClientDC dc(this);
	//CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//��ˢ���ת��Ϊ����
	//CBrush *pOldBrush = dc.SelectObject(pBrush);
	//dc.Rectangle(CRect(m_ptOrigin, point));
	//dc.SelectObject(pOldBrush);
	 //................

	//m_bDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy477View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//...................... ����
	//CClientDC dc(this);
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	//CPen *pOldPen = dc.SelectObject(&pen);
	//if (m_bDraw == TRUE)
	//{
	//	dc.SetROP2(R2_BLACK);
	//	dc.MoveTo(m_ptOrigin);//���
	//	//dc.LineTo(point);//�յ�
	//	//m_ptOrigin = point;//����
	//	dc.LineTo(m_ptOld);
	//	dc.MoveTo(m_ptOrigin);
	//	dc.LineTo(point);
	//	m_ptOld = point;
	//}
	//dc.SelectObject(pOldPen);
	//..........................
	CView::OnMouseMove(nFlags, point);
}


int CMy477View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);//��ȡ������Ϣ
	//CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);//�����
	bitmap.LoadBitmap(IDB_BITMAP2);
	CreateCaret(&bitmap);
	ShowCaret();
	
	SetTimer(1, 100, NULL);
	
	//SetClassLong(m_hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
	//SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HELP));
	
	
	return 0;
}


void CMy477View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CClientDC dc(this);
	//CFont font;
	//font.CreatePointFont(300, "�����п�", NULL);
	//CFont *pOldFont = dc.SelectObject(&font);
	//TEXTMETRIC tm;
	//dc.GetTextMetrics(&tm);
	//if (0x0d == nChar)//�س�
	//{
	//	if (0 == ++m_nIndex)
	//	{
	//		m_menu.CreatePopupMenu();
	//		GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT)m_menu.m_hMenu, "Phonebook");
	//		GetParent()->DrawMenuBar();
	//	}
	//	m_strLine.Empty();
	//	m_ptOrigin.y += tm.tmHeight;
	//}
	//else if (0x08 == nChar)//�˸�
	//{
	//	COLORREF clr = dc.SetTextColor(dc.GetBkColor());//�����ı���ɫ
	//	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
	//	m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);//ɾ��һ��
	//	dc.SetTextColor(clr);							//�ָ���ǰ��ɫ
	//}
	//else//����
	//{
	//	m_strLine += (BYTE)nChar;
	//}
	//CSize sz = dc.GetTextExtent(m_strLine);					//��ȡ���
	//CPoint pt;
	//pt.x = m_ptOrigin.x + sz.cx;
	//pt.y = m_ptOrigin.y;
	//SetCaretPos(pt);
	//dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);

	//dc.SelectObject(pOldFont);
	CClientDC dc(this);
	if (0x0d==nChar)
	{
		if (0 == ++m_nIndex)
			{
				m_menu.CreatePopupMenu();
				GetParent()->GetMenu()->AppendMenu(MF_POPUP, (UINT)m_menu.m_hMenu, "Phonebook");
				GetParent()->DrawMenuBar();
			}
		m_strLine.Empty();
		Invalidate();
	}
	else
	{
		m_strLine += (BYTE)nChar;
		dc.TextOut(0, 0, m_strLine);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy477View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nWidth += 5;//5�����ص�����
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;
	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadString(IDS_WEIXIN);
	dc.DrawText(str, rect, DT_LEFT);

	/*rect.top = 150;
	rect.bottom = rect.top + tm.tmHeight;
	dc.DrawText(str, rect, DT_RIGHT);*/

	CSize sz = dc.GetTextExtent(str);
	if (m_nWidth > sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0, 255, 0));
		dc.TextOut(0, 200, str);
	}

	CView::OnTimer(nIDEvent);
}

//
//void CMy477View::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CMenu menu;
//	menu.LoadMenu(IDR_MENU1);
//	CMenu *pPopup = menu.GetSubMenu(0);
//	ClientToScreen(&point);
//	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
//	//�ú�����ָ��λ����ʾ��ݲ˵��������ٲ˵����ѡ�񣬿�ݲ˵��ɳ�������Ļ������λ��
//
//	CView::OnRButtonDown(nFlags, point);
//}


void CMy477View::OnShow()
{
	MessageBox("View Show!");
	// TODO: �ڴ���������������
}


void CMy477View::OnDialog()
{
	// TODO: �ڴ���������������
	/*CTestDlg dlg;
	dlg.DoModal();*/

	CTestDlg *pDlg=new CTestDlg();
	pDlg->Create(IDD_DIALOG1, this);
	
	pDlg->ShowWindow(SW_SHOW);
}

void CMy477View::OnTaopao()
{
	CTaoPao dlg; 
	dlg.DoModal();
	// TODO: �ڴ���������������
}


void CMy477View::OnPropertysheet()
{
	// TODO: �ڴ���������������
	CPropSheet propSheet("���");
	propSheet.SetWizardMode();//�򵼰�ť
	if (ID_WIZFINISH == propSheet.DoModal())
	{
		m_iOccupation = propSheet.m_prop1.m_occupation;
		m_strWorkAddr = propSheet.m_prop1.m_workAddr;
		m_bLike[0] = propSheet.m_prop2.m_football;
		m_bLike[1] = propSheet.m_prop2.m_basketball;
		m_bLike[2] = propSheet.m_prop2.m_volleyball;
		m_bLike[3] = propSheet.m_prop2.m_swim;
		m_strSalary = propSheet.m_prop3.m_strSalary;
		Invalidate();//������Ч
	}
}
