#ifndef TaiKhoan_h
#define TaiKhoan_h

#include <iostream>
#include <fstream>

using namespace std;

class DanhSachTaiKhoan;

class TaiKhoan{
    protected :
        string TenDangNhap;
        string MatKhau;
    public :    
        TaiKhoan() : TenDangNhap(""), MatKhau("") {};
        TaiKhoan(string ten, string mk) : TenDangNhap(ten), MatKhau(mk) {};

        virtual ~TaiKhoan() {};
        virtual void DatTaiKhoan() = 0;
        //virtual string kiemTraDangNhap() = 0; 
        friend DanhSachTaiKhoan;
};

#endif