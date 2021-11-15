#ifndef TaiKhoan_h
#define TaiKhoan_h

#include <iostream>
#include "LinkedListTemplate.h"

using namespace std;

class TaiKhoan{
    protected :
        string tenDangNhap;
        string matKhau;
    public :    
        TaiKhoan();
        TaiKhoan(string ten, string mk) : tenDangNhap(ten), matKhau(mk) {};
        virtual ~TaiKhoan();
        virtual void DatMatKhau() = 0;
        virtual void DatTenDangNhap() = 0;
        virtual string kiemTraDangNhap() = 0;

        static string giaoDienThemTaiKhoan();
};

class DanhSachTaiKhoan{
    private : 
        LinkedList<TaiKhoan*> ls;
    public : 
        void themTaiKhoan(TaiKhoan *tk);
};  
#endif