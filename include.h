#ifndef INCLUDE_H
#define INCLUDE_H

#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.h"
#include "LinkedListTemplate.cpp"

int nhanVien_count_line = 0;
int khachHang_count_line = 0;
int vi_count_line = 0;

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

// ----------------------------------------------------------------------------------------------------------------------------------------------
// HAM CHUC NANG

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------



#endif