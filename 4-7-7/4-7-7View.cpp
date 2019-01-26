
// 4-7-7View.cpp : CMy477View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMy477View 构造/析构

CMy477View::CMy477View()
{
	// TODO: 在此处添加构造代码
	m_ptOrigin = 0;
	/*m_bDraw = FALSE;
	m_ptOld = 0;*/
	m_strLine = _T("");
	m_nWidth = 0;
	m_nIndex = 0;
	m_iOccupation=-1;
	m_strWorkAddr="";
	memset(m_bLike,0,sizeof(m_bLike));//数组初始化
	m_strSalary="";
}

CMy477View::~CMy477View()
{
}

BOOL CMy477View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	//cs.lpszClass = "sunxin.org";

	/*cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
		LoadCursor(NULL, IDC_CROSS), (HBRUSH)GetStockObject(BLACK_BRUSH), 0);*/
	//默认的
		//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);
	
	return CView::PreCreateWindow(cs);
}

// CMy477View 绘制

void CMy477View::OnDraw(CDC* pDC)
{
	CMy477Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CFont font;
	font.CreatePointFont(200, "华文行楷");

	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&font);
	CString strTemp;
	strTemp = "你的职业:";
	switch (m_iOccupation)
	{
	case 0:
		strTemp += "程序员";
		break;
	case 1:
		strTemp += "系统工程师";
		break;
	case 2:
		strTemp += "项目经理";
		break;
	default:
		break;
	}
	pDC->TextOut(0, 0, strTemp);

	strTemp = "你的工作地点:";
	strTemp += m_strWorkAddr;
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	pDC->TextOut(0, tm.tmHeight, strTemp);

	strTemp = "你的兴趣爱好:";
	if (m_bLike[0])
	{
		strTemp += "足球";
	}
	if (m_bLike[1])
	{
		strTemp += "篮球";
	}
	if (m_bLike[2])
	{
		strTemp += "排球";
	}
	if (m_bLike[3])
	{
		strTemp += "游泳";
	}
	pDC->TextOut(0, tm.tmHeight * 2, strTemp);

	strTemp = "你的薪资水平 :";
	strTemp += m_strSalary;
	pDC->TextOut(0, tm.tmHeight * 3, strTemp);
	//.....................输出字符串
	//CString str("长江大学");
	CString str;
	str = "长江大学";
	pDC->TextOut(200, 100, str);

	CSize sz = pDC->GetTextExtent(str);//求出字符串长度       不可以放在下面写

	//str.LoadString(IDS_WEIXIN);
	//pDC->TextOut(0, 200, str);
	//路径层
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

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy477View 打印


void CMy477View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy477View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy477View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy477View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CMy477View 诊断

#ifdef _DEBUG
void CMy477View::AssertValid() const
{
	CView::AssertValid();
}

void CMy477View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy477Doc* CMy477View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy477Doc)));
	return (CMy477Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy477View 消息处理程序


void CMy477View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//MessageBox(_T("view clicked"));
	SetCaretPos(point);//设置插入付位置
	m_strLine.Empty();
	m_ptOrigin = point;
	/*m_ptOrigin = m_ptOld=point;
	m_bDraw = TRUE;
	*/
	CView::OnLButtonDown(nFlags, point);
}


void CMy477View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//.........画线1
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);//获取全局
	//MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	//LineTo(hdc, point.x, point.y);
	//::ReleaseDC(m_hWnd, hdc);
	//..............

	//.........画线2
	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/
	//...............

	//.........画线3
	/*CClientDC dc(this);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/
	//................

	//.........画线4
	//CClientDC dc(GetParent());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................

	//.........画线5
	//CWindowDC dc(GetParent());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................

	//.........画线6
	//CWindowDC dc(GetDesktopWindow());
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//................
	 
	//.........画线7
	//CPen pen(PS_SOLID, 10, RGB(255, 0, 0));//实线
	//CClientDC dc(this);
	//CPen *pOldPen = dc.SelectObject(&pen);//用是将新创建的画笔作为当前画笔，但是SelectObject()的返回值则是新建画笔之前的画笔的
	//dc.MoveTo(m_ptOrigin);
	//dc.LineTo(point);
	//dc.SelectObject(pOldPen);//恢复原来的画笔，其实这个应该是一个习惯问题，不恢复问题也不大，但是你不恢复的话，后面用DC的时候可能用的就是你现在创建的画笔而不是默认的画笔。要养成好习惯，否则以后可能会出问题
	 //................

	 //.........画线8
	//CBrush brush(RGB(255, 0, 0));

	/*CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bitmap);
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin, point), &brush);*/
	 //................

	 //.........画线透明画刷9
	//CClientDC dc(this);
	//CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//画刷句柄转化为对象
	//CBrush *pOldBrush = dc.SelectObject(pBrush);
	//dc.Rectangle(CRect(m_ptOrigin, point));
	//dc.SelectObject(pOldBrush);
	 //................

	//m_bDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy477View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//...................... 扇形
	//CClientDC dc(this);
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	//CPen *pOldPen = dc.SelectObject(&pen);
	//if (m_bDraw == TRUE)
	//{
	//	dc.SetROP2(R2_BLACK);
	//	dc.MoveTo(m_ptOrigin);//起点
	//	//dc.LineTo(point);//终点
	//	//m_ptOrigin = point;//连续
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

	// TODO:  在此添加您专用的创建代码
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);//获取字体信息
	//CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);//插入符
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CClientDC dc(this);
	//CFont font;
	//font.CreatePointFont(300, "华文行楷", NULL);
	//CFont *pOldFont = dc.SelectObject(&font);
	//TEXTMETRIC tm;
	//dc.GetTextMetrics(&tm);
	//if (0x0d == nChar)//回车
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
	//else if (0x08 == nChar)//退格
	//{
	//	COLORREF clr = dc.SetTextColor(dc.GetBkColor());//设置文本颜色
	//	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
	//	m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);//删除一个
	//	dc.SetTextColor(clr);							//恢复先前颜色
	//}
	//else//增加
	//{
	//	m_strLine += (BYTE)nChar;
	//}
	//CSize sz = dc.GetTextExtent(m_strLine);					//获取宽度
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nWidth += 5;//5个像素点增加
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
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CMenu menu;
//	menu.LoadMenu(IDR_MENU1);
//	CMenu *pPopup = menu.GetSubMenu(0);
//	ClientToScreen(&point);
//	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
//	//该函数在指定位置显示快捷菜单，并跟踪菜单项的选择，快捷菜单可出现在屏幕的任意位置
//
//	CView::OnRButtonDown(nFlags, point);
//}


void CMy477View::OnShow()
{
	MessageBox("View Show!");
	// TODO: 在此添加命令处理程序代码
}


void CMy477View::OnDialog()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
}


void CMy477View::OnPropertysheet()
{
	// TODO: 在此添加命令处理程序代码
	CPropSheet propSheet("你好");
	propSheet.SetWizardMode();//向导按钮
	if (ID_WIZFINISH == propSheet.DoModal())
	{
		m_iOccupation = propSheet.m_prop1.m_occupation;
		m_strWorkAddr = propSheet.m_prop1.m_workAddr;
		m_bLike[0] = propSheet.m_prop2.m_football;
		m_bLike[1] = propSheet.m_prop2.m_basketball;
		m_bLike[2] = propSheet.m_prop2.m_volleyball;
		m_bLike[3] = propSheet.m_prop2.m_swim;
		m_strSalary = propSheet.m_prop3.m_strSalary;
		Invalidate();//窗口无效
	}
}
