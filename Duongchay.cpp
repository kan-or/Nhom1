#include "pch.h"
#include "Duongchay.h"
#include<Windows.h>

Duongchay::Duongchay()
{
    duongvien = Hcn(XDAU, YDAU, XDAU + 1500, YDAU + 400);
    int a[5];
    a[0] = 20;
    a[1] = 15;
    a[2] = 25;
    a[3] = 30;
    a[4] = 35;
    int h = rand() % 5;
    for (int i = 0; i < 5; i++)
    {
        h = rand() % 5;
        vatcan[i] = Hcn(XDAU + 50 + i * 300, duongvien.y2 - a[h], XDAU + 60 + i * 300, duongvien.y2);
    }

}

void Duongchay::vehinh(CClientDC* pdc)
{
    duongvien.vehinh(pdc);
    for (int i = 0; i < 5; i++)
        vatcan[i].vehinh(pdc);
}

int Duongchay::chamrobot(Player rb)
{
    int i = 0;
    // Kiểm tra va chạm với tất cả các vật cản
    for (i = 0; i < 5; i++)
    {
        if (vatcan[i].ktgiaonhau(rb.dau) == 1 || vatcan[i].ktgiaonhau(rb.than) == 1
            || vatcan[i].ktgiaonhau(rb.chan) == 1)
        {
            // Chỉ hiển thị Game Over sau khi va chạm
            AfxMessageBox(_T("Game Over!"));  // Sử dụng MessageBox để hiển thị thông báo
            return 1;  // Trả về 1 khi có va chạm để báo hiệu kết thúc trò chơi
        }
    }
    return 0;  // Không có va chạm, tiếp tục trò chơi
}

void Duongchay::chay()
{
    // Di chuyển các vật cản
    for (int i = 0; i < 5; i++)
    {
        vatcan[i].dichtrai();
        if (vatcan[i].x1 < duongvien.x1)
        {
            vatcan[i].x1 = duongvien.x2 - 10;
            vatcan[i].x2 = duongvien.x2;
            int a[5];
            a[0] = 20;
            a[1] = 15;
            a[2] = 25;
            a[3] = 30;
            a[4] = 35;
            int h = rand() % 5;
            vatcan[i].y1 = vatcan[i].y2 - a[h];
        }
    }
}

