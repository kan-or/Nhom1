#pragma once
#define D 4
class Hcn
{
public:
	int x1, y1, x2, y2;
	Hcn();
	Hcn(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC* pdc);
	void dichlen();
	void dichxuong();
	void dichtrai();
	void dichphai();
	int kttronghinh(CPoint p);
	int ktgiaonhau(Hcn b);
};

