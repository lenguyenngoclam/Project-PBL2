#ifndef KhachHang_h
#define KhachHang_h

//Testing
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
};

class KhachHang{
    private :
        static int idKhachHang;
        TheATM theATM;
    public :
        void dongTaiKhoan();
};

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang khachHang;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        void datMatKhau() override;
        void datTenDangNhap() override;
};

#endif
