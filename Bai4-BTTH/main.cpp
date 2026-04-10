#include <iostream>
using namespace std;
#include "giophutgiay.h"

int main(){
    GioPhutGiay t;

    t.Nhap();
    t.Xuat();
    t.TinhCongThemMotGiay();
    cout << "\nSau khi cong them 1 giay: " << endl;
    t.Xuat();

    return 0;
}