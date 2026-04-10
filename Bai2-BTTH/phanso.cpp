#include <iostream>
#include "PhanSo.h"
using namespace std;

// Hàm tìm UCLN
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// ================= NHAP =================
// Input: tử, mẫu
// Output: phân số hợp lệ
// Algorithm:
// B1: Nhập tử
// B2: Nhập mẫu
// B3: Nếu mẫu = 0 → nhập lại

void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}




void PhanSo::Xuat() {
    cout << iTu << "/" << iMau;
}

// ================= RUT GON =================
// Input:
// - Phân số (iTu, iMau)
// Output:
// - Phân số tối giản
// Giải thuật:
// 1. Tìm UCLN của |iTu| và |iMau|
// 2. Chia iTu và iMau cho UCLN
// 3. Nếu iMau < 0 thì đổi dấu cả tử và mẫu


void PhanSo::RutGon() {
    int ucln = UCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    // Đưa dấu về tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

// ================= TONG =================
// Input:
// - Hai phân số a/b và c/d
// Output:
// - Tổng hai phân số
// Giải thuật:
// 1. Tính tử mới = a*d + c*b
// 2. Tính mẫu mới = b*d
// 3. Rút gọn kết quả


PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// ================= HIEU =================
// Input: 2 số phức
// Output: hiệu
// Giải thuật:
// (a+bi)-(c+di)

PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// ================= TICH =================
// Input:
// - Hai số phức (a+bi) và (c+di)
// Output:
// - Tích hai số phức
// Giải thuật:
// 1. Áp dụng công thức:
// (a+bi)(c+di) = (ac - bd) + (ad + bc)i
// 2. Tính phần thực = ac - bd
// 3. Tính phần ảo = ad + bc

PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// ================= THUONG =================
// Input: 2 số phức
// Output: thương
// Giải thuật:
// chia theo công thức liên hợp

PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

// ================= SO SÁNH =================
// Input: 2 số phức
// Output: 1: >, 0: =, -1: <
// Giải thuật:
// nhân chéo tử mẫu rồi so sánh trái phải


int PhanSo::SoSanh(PhanSo ps) {
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;
}
