// runnerGameView.cpp : cài đặt lớp CRunnerGameView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS có thể được định nghĩa trong một dự án ATL triển khai các bộ xử lý xem trước, thu nhỏ
// và bộ lọc tìm kiếm, cho phép chia sẻ mã tài liệu với dự án đó.
#ifndef SHARED_HANDLERS
#include "runnerGame.h"
#endif

#include "runnerGameDoc.h"
#include "runnerGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRunnerGameView

IMPLEMENT_DYNCREATE(CRunnerGameView, CView)

BEGIN_MESSAGE_MAP(CRunnerGameView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CRunnerGameView tạo và hủy

CRunnerGameView::CRunnerGameView() noexcept
{
	// TODO: thêm mã khởi tạo ở đây
	game = Game();
	kd = 0;
}

CRunnerGameView::~CRunnerGameView()
{
}

BOOL CRunnerGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Thay đổi lớp hoặc kiểu cửa sổ ở đây bằng cách thay đổi
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRunnerGameView vẽ

void CRunnerGameView::OnDraw(CDC* /*pDC*/)
{
	CRunnerGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	// TODO: thêm mã vẽ cho dữ liệu gốc ở đây

	game.vehinh(&pdc);  // Vẽ hình của đối tượng game (có thể là đường, vật cản, player,...)
}


void CRunnerGameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRunnerGameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRunnerGameView chẩn đoán

#ifdef _DEBUG
void CRunnerGameView::AssertValid() const
{
	CView::AssertValid();
}

void CRunnerGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRunnerGameDoc* CRunnerGameView::GetDocument() const // phiên bản không phải debug là inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRunnerGameDoc)));
	return (CRunnerGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CRunnerGameView xử lý sự kiện

void CRunnerGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Thêm mã xử lý sự kiện hoặc gọi mặc định
	CClientDC pdc(this);
	if (game.bamnut(&pdc, point) == 1)
	{
		batDauGame();
	}
	CView::OnLButtonDown(nFlags, point);
}

UINT vatCanChay(LPVOID pParam)
{
	int ran = 0;
	CRunnerGameView* cview = (CRunnerGameView*)pParam;
	CClientDC pdc(cview);
	cview->game.vatcanchay(&pdc);
	return 0;
}

UINT capNhatHinh(LPVOID pParam)
{
	int ran = 0;
	CRunnerGameView* cview = (CRunnerGameView*)pParam;
	CClientDC pdc(cview);
	cview->game.capnhathinh(&pdc);
	return 0;
}

int CRunnerGameView::batDauGame()
{
	// TODO: Thêm mã triển khai ở đây.
	AfxBeginThread(capNhatHinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(vatCanChay, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
}

void CRunnerGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Thêm mã xử lý sự kiện hoặc gọi mặc định
	if (nChar == 32 && kd == 0)
	{
		kd = 1;
		game.playernhay();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRunnerGameView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Thêm mã xử lý sự kiện hoặc gọi mặc định
	kd = 0;
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
