#include <iostream>
using namespace std;
#include "sophuc.h"

// Nhap
// Input: phần thực, phần ảo
// Output: gán giá trị
// Algorithm:
// 1. Nhập thuc
// 2. Nhập ao
void SoPhuc::Nhap(){
    cin >> thuc >> ao;
}

// Xuat
// Input: số phức
// Output: a + bi
// Algorithm:
// 1. In thuc
// 2. Kiểm tra dấu ao để in đúng format
void SoPhuc::Xuat(){
    cout << thuc;
    if(ao >= 0) cout << " + " << ao << "i";
    else cout << " - " << -ao << "i";
}

// Tong
// Input: 2 số phức
// Output: tổng
// Algorithm:
// 1. Cộng phần thực
// 2. Cộng phần ảo
SoPhuc SoPhuc::Tong(SoPhuc b){
    SoPhuc kq;
    kq.thuc = thuc + b.thuc;
    kq.ao = ao + b.ao;
    return kq;
}

// Hieu
// Input: 2 số phức
// Output: hiệu
// Algorithm:
// 1. Trừ phần thực
// 2. Trừ phần ảo
SoPhuc SoPhuc::Hieu(SoPhuc b){
    SoPhuc kq;
    kq.thuc = thuc - b.thuc;
    kq.ao = ao - b.ao;
    return kq;
}

// Tich
// Input: 2 số phức
// Output: tích
// Algorithm:
// 1. (a+bi)(c+di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::Tich(SoPhuc b){
    SoPhuc kq;
    kq.thuc = thuc*b.thuc - ao*b.ao;
    kq.ao = thuc*b.ao + ao*b.thuc;
    return kq;
}

// Thuong
// Input: 2 số phức
// Output: thương
// Algorithm:
// 1. (a+bi)/(c+di) = [(a+bi)(c-di)] / (c^2 + d^2)
SoPhuc SoPhuc::Thuong(SoPhuc b){
    SoPhuc kq;
    double mau = b.thuc*b.thuc + b.ao*b.ao;
    kq.thuc = (thuc*b.thuc + ao*b.ao) / mau;
    kq.ao = (ao*b.thuc - thuc*b.ao) / mau;
    return kq;
}