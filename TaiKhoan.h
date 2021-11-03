#ifndef TaiKhoan_h
#define TaiKhoan_h

#include <iostream>

using namespace std;
class TaiKhoan{
    protected :
        string tenDangNhap;
        string matKhau;
    public :    
        TaiKhoan() = default;
        virtual ~TaiKhoan();
        virtual void datMatKhau() = 0;
        virtual void datTenDangNhap() = 0;
};
#endif