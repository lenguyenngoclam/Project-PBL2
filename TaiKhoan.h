#ifndef TaiKhoan_h
#define TaiKhoan_h

#include <iostream>
#include <fstream>

using namespace std;

class TaiKhoan{
    protected :
        string TenDangNhap;
        string MatKhau;
    public :    
        TaiKhoan() : TenDangNhap(""), MatKhau("") {};
        TaiKhoan(string ten, string mk) : TenDangNhap(ten), MatKhau(mk) {};
        TaiKhoan(const TaiKhoan& tk) : TenDangNhap(tk.TenDangNhap), MatKhau(tk.MatKhau){};

        virtual ~TaiKhoan() {};
};

#endif