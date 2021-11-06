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
        virtual void DatMatKhau() = 0;
        virtual void DatTenDangNhap() = 0;
        virtual void DoiMatKhau() = 0;
};
#endif