#include "pch.h"
#include "Hcn.h"

Hcn::Hcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Hcn::Hcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Hcn::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

void Hcn::dichlen()
{
	y1 = y1 - D;
	y2 = y2 - D;
}

void Hcn::dichxuong()
{
	y1 = y1 + D;
	y2 = y2 + D;
}

void Hcn::dichtrai()
{
	x1 = x1 - D;
	x2 = x2 - D;
}

void Hcn::dichphai()
{
	x1 = x1 + D;
	x2 = x2 + D;
}

int Hcn::kttronghinh(CPoint p)
{
	if (p.x > x1 && p.x < x2 && p.y > y1 && p.y < y2)
		return 1;
	else
		return 0;
}

int Hcn::ktgiaonhau(Hcn b)
{
	if (x2 < b.x1 || x1 > b.x2 || y2 < b.y1 || y1 > b.y2)
		return 0;
	else
		return 1;
}
