#ifndef SuKien_h
#define SuKien_h

#include <iostream>
#include <string>
#include "NhanVien.cpp"

using namespace std;

class SuKien{
    public :
        bool suKienThemTaiKhoan(DanhSachNhanVien &ls, DanhSachTaiKhoan &);
};

#endif