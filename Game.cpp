#include "pch.h"
#include "Game.h"

Game::Game()
{
	thietlap();
}

void Game::vehinh(CClientDC* pdc)
{
	CString strdiem;
	strdiem.Format(_T("diem : %d    "), diem);
	pdc->TextOutW(100, 20, strdiem);
	nl.vehinh(pdc);
	dc.vehinh(pdc);
	rb.venhinh(pdc);
}

int Game::bamnut(CClientDC* pdc, CPoint p)
{
	if (nl.bamnutlenh(p) == 1 && nl.giatri == 0)
	{
		thietlap();
		nl.giatri = 1;
		nl.nd.Format(_T("stop"));
		nl.vehinh(pdc);
		dk = 1;
		return 1;
	}
	else
		if (nl.bamnutlenh(p) == 1 && nl.giatri == 1)
		{
			nl.giatri = 0;
			nl.nd.Format(_T("start"));
			nl.vehinh(pdc);
			dk = 0;
			return 0;
		}
}

void Game::vatcanchay(CClientDC* pdc)
{
	while (dk == 1)
	{
		diem++;
		dc.chay();
		Sleep(30);
	}

}

void Game::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		CString strdiem;
		strdiem.Format(_T("diem : %d    "), diem);
		pdc->TextOutW(100, 20, strdiem);
		dc.vehinh(pdc);
		rb.venhinh(pdc);
		if (dc.chamrobot(rb) == 1)
		{
			dk = 0;
			thang = -1;
			//bien nut thanh nut start
			nl.giatri = 0;
			nl.nd.Format(_T("start"));
			nl.vehinh(pdc);
		}
		Sleep(20);
	}
}

void Game::playernhay()
{
	rb.nhaylen();
}

void Game::thietlap()
{
	CString str;
	str.Format(_T("start"));
	nl = Nutlenh(30, 20, str);
	dc = Duongchay();
	rb = Player(200, dc.duongvien.y2 - 30);
	dk = 0;
	thang = 0;
	diem = 0;
}
