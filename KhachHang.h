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
        static string MaSoThe;
        string MatKhau;
        string MaTaiKhoan;
    public :    
        void NapTien(double soTien);
        void RutTien();
        void XemSoDu();
        void DatMatKhau();
        void DoiMatKhau();
};

class KhachHang{
    private :
        static int idKhachHang;
        TheATM TheATM;
    public :
        void MoTaiKhoan();
        void DongTaiKhoan();
        void TaoATM(); // Chuc nang de dky the atm luc mo tai khoan
        void TaoOnlineBanking();
        void XemSoDu();
};

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang KhachHang;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        void DatMatKhau() override;
        void DatTenDangNhap() override;
        string kiemTraDangNhap() override;
};

#endif
