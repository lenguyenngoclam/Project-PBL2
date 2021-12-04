#ifndef INCLUDE_H
#define INCLUDE_H

#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.h"
#include "SetTemplate.cpp"
#include "LinkedListTemplate.cpp"

int nhanVien_count_line = 0;
int khachHang_count_line = 0;

string LaySoLuongKhachHang() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_KhachHang = LaySoLuongKhachHang();
int soLuong = stoi(number_KhachHang);


#endif