#ifndef TAIKHOANKHACHHANG_H
#define TAIKHOANKHACHHANG_H

#include <iostream>
#include "KhachHang.cpp"

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

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang kh;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        //void DatMatKhau() override;
        //void DatTenDangNhap() override;
};

#endif