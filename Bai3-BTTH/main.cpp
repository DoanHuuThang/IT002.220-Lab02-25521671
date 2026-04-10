#include <iostream>
using namespace std;
#include "sophuc.h"

int main(){
    SoPhuc a,b;

    a.Nhap();
    b.Nhap();

    cout << "So phuc A: "; a.Xuat(); cout << endl;
    cout << "So phuc B: "; b.Xuat(); cout << endl;
    cout << "Tong: "; a.Tong(b).Xuat(); cout << endl;
    cout << "Hieu: "; a.Hieu(b).Xuat(); cout << endl;
    cout << "Tich: "; a.Tich(b).Xuat(); cout << endl;
    cout << "Thuong: "; a.Thuong(b).Xuat(); cout << endl;

    return 0;
}