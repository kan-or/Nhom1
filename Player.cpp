#include "pch.h"
#include "player.h"

Player::Player()
{
    int mx = 0, my = 0;
    dau = Hcn(mx - 8, my - 5, mx + 8, my + 10);  // Đầu: nhỏ hơn một chút
    than = Hcn(dau.x1 - 5, dau.y2, dau.x2 + 5, dau.y1 + 30);  // Thân: rộng hơn một chút
    chan = Hcn(than.x1 + 5, than.y2, than.x2 - 5, than.y2 + 5);  // Chân: dài hơn và có sự điều chỉnh để cân đối
}

Player::Player(int mx, int my)
{
    dau = Hcn(mx - 8, my - 5, mx + 8, my + 10);  // Đầu: nhỏ hơn một chút
    than = Hcn(dau.x1 - 5, dau.y2, dau.x2 + 5, dau.y1 + 30);  // Thân: rộng hơn một chút
    chan = Hcn(than.x1 + 5, than.y2, than.x2 - 5, than.y2 + 5);  // Chân: dài hơn và có sự điều chỉnh để cân đối
}

void Player::venhinh(CClientDC* pdc)
{
    // Tạo đối tượng CPen để thiết lập màu sắc cho từng bộ phận
    CPen penDau(PS_SOLID, 2, RGB(255, 0, 0));  // Màu đỏ cho đầu
    CPen penThan(PS_SOLID, 2, RGB(0, 255, 0)); // Màu xanh lá cho thân
    CPen penChan(PS_SOLID, 2, RGB(0, 0, 255)); // Màu xanh dương cho chân

    // Lựa chọn bút để vẽ
    pdc->SelectObject(&penDau);  // Chọn bút màu đỏ cho đầu
    dau.vehinh(pdc);

    pdc->SelectObject(&penThan);  // Chọn bút màu xanh cho thân
    than.vehinh(pdc);

    pdc->SelectObject(&penChan);  // Chọn bút màu xanh dương cho chân
    chan.vehinh(pdc);
}

void Player::nhaylen()
{
    int i = 0;
    for (i = 0; i < 16; i++)
    {
        dau.dichlen();
        than.dichlen();
        chan.dichlen();
        Sleep(20);  // Thêm một chút thời gian để chuyển động mượt mà hơn
    }
    for (i = 0; i < 16; i++)
    {
        dau.dichxuong();
        than.dichxuong();
        chan.dichxuong();
        Sleep(20);  // Thêm một chút thời gian để chuyển động mượt mà hơn
    }
}
