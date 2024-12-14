#pragma once
#include "Hcn.h"
#include "Player.h"
#define XDAU 50
#define YDAU 100
class Duongchay
{
public:
	Hcn duongvien;
	Hcn vatcan[5];
	Duongchay();
	void vehinh(CClientDC* pdc);
	void chay();
	int chamrobot(Player rb);
};

