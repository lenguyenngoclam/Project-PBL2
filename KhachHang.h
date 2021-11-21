#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <fstream>
#include <string>

#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.h"
#include "SetTemplate.cpp"

using namespace std;

class TheATM;

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
        TheATM theAtm;
    public :
        KhachHang() {
            ThongTinCaNhan();
        }
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);
        KhachHang(string id) : idKhachHang(id), ThongTinCaNhan() {};

        ~KhachHang() override = default;

        KhachHang(const KhachHang &kh);
        KhachHang &operator =(const KhachHang &kh);

        string LaySoLuong();

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;
        void CaiDatThongTin();

        bool operator ==(const KhachHang& rhs) const;
        bool operator !=(const KhachHang& rhs) const;
        bool operator >(const KhachHang& rhs) const;
        bool operator <(const KhachHang& rhs) const;

        void MoTaiKhoan();
        void DongTaiKhoan();
        void TaoATM(); // Chuc nang de dky the atm luc mo tai khoan
        void TaoOnlineBanking();
        void XemSoDu();

        friend class DanhSachKhachHang;
};

class TheATM{
    private :
        double soDu;
        string MatKhau;
        string MaTaiKhoan;
        KhachHang khachHang;
    public :    
        void NapTien(double soTien);
        void RutTien(double );
        void XemSoDu();
        void DatMatKhau();
        void DoiMatKhau();
};

class DanhSachKhachHang{
    private:
        Set<KhachHang> set;
    public:
        DanhSachKhachHang() = default;
        ~DanhSachKhachHang() = default;

        void CaiDatDanhSach();
        void InDanhSach();
        void SuaDanhSach(const KhachHang &nv);
        void ThemKhachHang(KhachHang& nv); 
        void TimKiemKhachHang(string id);

        friend class KhachHang;
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
