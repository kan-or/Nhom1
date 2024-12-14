#include "pch.h"
#include "Nutlenh.h"

Nutlenh::Nutlenh()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	giatri = 0;
}

Nutlenh::Nutlenh(int mx, int my, CString mnd)
{
	x1 = mx;
	y1 = my;
	giatri = 0;
	x2 = x1 + 50;
	y2 = y1 + 40;
	nd.Format(mnd);
}

void Nutlenh::vehinh(CClientDC* pdc)
{
	Hcn::vehinh(pdc);
	pdc->TextOutW(x1 + 10, y1 + 10, nd);
}

int Nutlenh::bamnutlenh(CPoint p)
{
	if (kttronghinh(p) == 1)
	{
		//	giatri = 1;
		return 1;
	}
	else
		return 0;
}
