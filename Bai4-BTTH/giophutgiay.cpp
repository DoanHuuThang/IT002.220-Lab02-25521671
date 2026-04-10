#include <iostream>
using namespace std;
#include "giophutgiay.h"

// Nhap
// Input: giờ, phút, giây
// Output: lưu dữ liệu
// Algorithm:
// 1. Nhập 3 giá trị
// 2. Kiểm tra tính hợp lệ nếu sai thì yêu cầu nhập lại
void GioPhutGiay::Nhap(){
    while (true) {
        cin >> gio >> phut >> giay;
        if (gio >= 0 && gio < 24 && phut >= 0 && phut < 60 && giay >= 0 && giay < 60) {
            break; // Dữ liệu hợp lệ, thoát vòng lặp
        } else {
            cout << "Nhap sai, vui long nhap lai (gio: 0-23, phut: 0-59, giay: 0-59): ";
        }
    }
}

// Xuat
// Input: thời gian
// Output: hh:mm:ss
// Algorithm:
// 1. In theo format
void GioPhutGiay::Xuat(){
    cout << (gio < 10 ? "0" : "") << gio << ":"
         << (phut < 10 ? "0" : "") << phut << ":"
         << (giay < 10 ? "0" : "") << giay;
}

// TinhCongThemMotGiay
// Input: thời gian hiện tại
// Output: +1 giây
// Algorithm:
// 1. Tăng giây
// 2. Nếu giây = 60 → reset, tăng phút
// 3. Nếu phút = 60 → reset, tăng giờ
// 4. Nếu giờ = 24 → reset về 0
void GioPhutGiay::TinhCongThemMotGiay() {
    giay++;
    if (giay == 60) {
        giay = 0;
        phut++;
        if (phut == 60) {
            phut = 0;
            gio++;
            if (gio == 24) {
                gio = 0;
            }
        }
    }
}