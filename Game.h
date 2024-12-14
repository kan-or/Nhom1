#pragma once
#include "Duongchay.h"
#include "Player.h"
#include "Nutlenh.h"
class Game
{
public:
	int diem;
	int dk, thang;
	Nutlenh nl;
	Duongchay dc;
	Player rb;
	Game();
	void vehinh(CClientDC* pdc);
	int bamnut(CClientDC* pdc, CPoint p);
	void vatcanchay(CClientDC* pdc);
	void capnhathinh(CClientDC* pdc);
	void playernhay();
	void thietlap();
};

