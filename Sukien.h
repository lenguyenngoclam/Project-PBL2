#ifndef SuKien_h
#define SuKien_h

#include <iostream>
#include <string>

#include "TaiKhoan.h"
#include "NhanVien.cpp"

using namespace std;

class SuKien{
    public :
        bool SuKienThemTaiKhoan(DanhSachNhanVien &ls, DanhSachTaiKhoan &);
};

#endif