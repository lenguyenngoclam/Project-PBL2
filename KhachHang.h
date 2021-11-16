#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <string>

#include "ThongTinCaNhan.h"
#include "TaiKhoan.h"
#include "LinkedListTemplate.h"
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

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
        TheATM TheATM;
    public :
        KhachHang() {
            ThongTinCaNhan();
        }
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);

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

class OnlineBanking : public TaiKhoan{
    private :   
        KhachHang kh;
    public :
        OnlineBanking() = default;
        ~OnlineBanking() override = default;
        //void DatMatKhau() override;
        //void DatTenDangNhap() override;
};

class DanhSachKhachHang{
    private:
        LinkedList<KhachHang> ls;
    public:
        DanhSachKhachHang() = default;
        ~DanhSachKhachHang() = default;

        void CaiDatDanhSach();
        void InDanhSach();
        void SuaDanhSach(const KhachHang &nv);
        void ThemKhachHang(KhachHang& nv); 
        void TimKiemKhachHang(string id);

        Node<KhachHang>* getHead();

        friend class KhachHang;
};


#endif
