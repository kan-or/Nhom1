#pragma once
#include "Hcn.h"
class Nutlenh :
    public Hcn
{
public:
    CString nd;
    int giatri;
    Nutlenh();
    Nutlenh(int mx, int my, CString mnd);
    void vehinh(CClientDC* pdc);
    int bamnutlenh(CPoint p);
};

