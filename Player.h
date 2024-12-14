#pragma once
#include "Hcn.h"
class Player
{
public:
	Hcn dau, than, chan;
	Player();
	Player(int mx, int my);
	void venhinh(CClientDC* pdc);
	void nhaylen();


};

