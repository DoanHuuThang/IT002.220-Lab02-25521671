#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main() {
    NgayThangNam a;

    a.Nhap();

    cout << "Ngay vua nhap: ";
    a.Xuat();

    a.NgayThangNamTiepTheo();

    cout << "Ngay tiep theo: ";
    a.Xuat();

    return 0;
}
