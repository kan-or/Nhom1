// runnerGameView.h : interface of the CRunnerGameView class
//

#pragma once

#include "Game.h"  // Bao gồm Game.h để sử dụng lớp RunnerGame

// Kiểm tra để đảm bảo các khai báo kiểu dữ liệu MFC
#include <afxwin.h>  // Cần thiết cho CDC, CView, CWnd và các kiểu MFC khác

class CRunnerGameView : public CView
{
protected: // tạo từ serialization chỉ
	CRunnerGameView() noexcept;
	DECLARE_DYNCREATE(CRunnerGameView)

	// Thuộc tính
public:
	CRunnerGameDoc* GetDocument() const;

	// Thao tác
public:
	Game game; // Khai báo đối tượng runnerGame của lớp RunnerGame
	int kd;

	// Ghi đè
public:
	virtual void OnDraw(CDC* pDC);  // ghi đè để vẽ view này
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:

	// Triển khai
public:
	virtual ~CRunnerGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Các hàm map sự kiện được tạo
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int batDauGame();  // Đổi tên hàm batdaugame thành batDauGame để phù hợp với tên mới
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Phiên bản debug trong runnerGameView.cpp
inline CRunnerGameDoc* CRunnerGameView::GetDocument() const
{
	return reinterpret_cast<CRunnerGameDoc*>(m_pDocument);  // Trả về tài liệu đúng kiểu
}
#endif
