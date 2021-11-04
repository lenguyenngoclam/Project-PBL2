#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <string>
#include "ThongTinCaNhan.h"
#include "TaiKhoan.h"
using namespace std;

class TheATM{
    private :
        static string maSoThe;
        string matKhau;
        string maTaiKhoan;
    public :    
        void napTien(double soTien);
        void rutTien();
        void xemSoDu();
        void datMatKhau();
        void doiMatKhau();
};

class KhachHang{
    private :
        static int idKhachHang;
        TheATM theATM;
    public :
        void moTaiKhoan();
        void dongTaiKhoan();
        void taoATM(); // Chuc nang de dky the atm luc mo tai khoan
        void taoOnlineBanking();
        void xemSoDu();
};

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang khachHang;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        void datMatKhau() override;
        void datTenDangNhap() override;
        void doiMatKhau() override;
};

#endif