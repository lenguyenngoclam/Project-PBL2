#ifndef KhachHang_h
#define KhachHang_h

// Testing
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

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang KhachHang;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        void DatMatKhau() override;
        void DatTenDangNhap() override;
        void DoiMatKhau() override;
};

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
        TheATM TheATM;
    public :
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);

        ~KhachHang() override = default;

        KhachHang(const KhachHang &kh);
        KhachHang &operator =(const KhachHang &kh);

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;
        void CaiDatThongTin();

        void MoTaiKhoan();
        void DongTaiKhoan();
        void TaoATM(); // Chuc nang de dky the atm luc mo tai khoan
        void TaoOnlineBanking();
        void XemSoDu();
};

class DanhSachKhachHang{
    private:
        LinkedList<KhachHang> ls;
    public:
        DanhSachKhachHang() = default;
        ~DanhSachKhachHang() = default;

        void CaiDatDanhSach();
        void InDanhSach();

        Node<KhachHang>* getHead();

        friend class KhachHang;
};


#endif
