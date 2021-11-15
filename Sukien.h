#ifndef SuKien_h
#define SuKien_h

#include <iostream>
#include <string>
#include "TaiKhoan.cpp"
#include "NhanVien.cpp"

using namespace std;

class SuKien{
    private :
        DanhSachTaiKhoan dsTaiKhoan;
    public :
        bool suKienThemTaiKhoan();
};

#endif