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
        TaiKhoan();
        TaiKhoan(string ten, string mk) : TenDangNhap(ten), MatKhau(mk) {};
        TaiKhoan(const TaiKhoan& tk);

        virtual ~TaiKhoan() {};
        virtual void DatTaiKhoan() = 0;
        //virtual string kiemTraDangNhap() = 0;
        virtual ostream& getInfo(ostream&);

        TaiKhoan& operator =(const TaiKhoan& rhs);

};

class node{
    public :
        TaiKhoan* data;
        node* next;  
};

class DanhSachTaiKhoan{
    public : 
        node* head = NULL;
    public : 
        DanhSachTaiKhoan() = default;

        ~DanhSachTaiKhoan() = default;

        void ThemTaiKhoan(TaiKhoan *tk);
        void CaiDatDanhSach();
        void InDanhSach();
};  
#endif