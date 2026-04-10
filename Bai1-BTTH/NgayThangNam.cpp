#include <iostream>
#include "NgayThangNam.h"
using namespace std;

// ================= NHAP =================
// Input: 
//   - iNgay: ngày
//   - iThang: tháng
//   - iNam: năm
// Output: 
//   - Gán giá trị nhập vào cho các thuộc tính của đối tượng
// Giải thuật:
//   1. Nhập iNgay
//   2. Nhập iThang
//   3. Nhập iNam
//   4. Kiểm tra tính hợp lệ của ngày, tháng, năm
//      - Tháng 1, 3, 5, 7, 8
//        - Tháng 4, 6, 9, 11
//        - Tháng 2: xem xét năm nhuận
//      - Nếu không hợp lệ, yêu cầu nhập lại

void NgayThangNam::Nhap() {
    while (true) {
        cout << "Nhap ngay: ";
        cin >> iNgay;
        cout << "Nhap thang: ";
        cin >> iThang;
        cout << "Nhap nam: ";
        cin >> iNam;
        if ((iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12) && (iNgay < 1 || iNgay > 31)) {
            cout << "Ngay khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        if ((iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11) && (iNgay < 1 || iNgay > 30)) {
            cout << "Ngay khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        if (iThang == 2) {
            if ((iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0)) {
                if (iNgay < 1 || iNgay > 29) {
                    cout << "Ngay khong hop le. Vui long nhap lai." << endl;
                    continue;
                }
            } else {
                if (iNgay < 1 || iNgay > 28) {
                    cout << "Ngay khong hop le. Vui long nhap lai." << endl;
                    continue;
                }
            }
        }
        if (iThang < 1 || iThang > 12) {
            cout << "Thang khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        if (iNam <= 0) {
            cout << "Nam khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        break;
    }

}

// ================= XUAT =================
// Input: iNgay, iThang,iNam đã được gán giá trị
// Output: 
//   - Xuất ngày theo định dạng dd/mm/yyyy
// Giải thuật:
//   1. In iNgay
//   2. In dấu "/"
//   3. In iThang
//   4. In dấu "/"
//   5. In iNam

void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

// ================= NGAY THANG NAM TIEP THEO =================
// Input: 
//   - iNgay, iThang, iNam đã được gán giá trị
// Output: 
//   - Cập nhật thành ngày kế tiếp
// Giải thuật:
//   1. Tăng iNgay lên 1
//   2. Nếu iNgay > số ngày tối đa trong tháng:
//        - Đặt iNgay = 1
//        - Tăng iThang lên 1
//   3. Nếu iThang > 12:
//        - Đặt iThang = 1
//        - Tăng iNam lên 1
//  4. Xác định số ngày tối đa trong tháng dựa trên iThang và iNam (xem xét năm nhuận)
//    - Tháng 1, 3, 5, 7, 8, 10, 12: 31 ngày
//    - Tháng 4, 6, 9, 11: 30 ngày
//    - Tháng 2: 28 ngày, nếu năm nhuận thì 29
//    - Năm nhuận: chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100
//   - Nếu iNgay vượt quá số ngày tối đa, thực hiện chuyển tháng và năm nếu cần thiết
//   - Cập nhật iNgay, iThang, iNam cho ngày kế tiếp

void NgayThangNam::NgayThangNamTiepTheo() {
    int ngayTrongThang;

    switch(iThang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            ngayTrongThang = 31;
            break;
        case 4: case 6: case 9: case 11:
            ngayTrongThang = 30;
            break;
        case 2:
            if ((iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0))
                ngayTrongThang = 29;
            else
                ngayTrongThang = 28;
            break;
    }

    iNgay++;

    if (iNgay > ngayTrongThang) {
        iNgay = 1;
        iThang++;

        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
}
