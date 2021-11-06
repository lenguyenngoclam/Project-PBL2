#ifndef NhanVien_h
#define NhanVien_h

#include <iostream>
#include "TaiKhoan.h"
#include "ThongTinCaNhan.h"

using namespace std;

class NhanVien : public ThongTinCaNhan{
    private :
        static string idNhanVien;
    public :
        NhanVien(string hoten, string diachi, string sodienthoai, int tuoi);
        ~NhanVien() override = default;
        void LayThongTin();
        void CaiDatThongTin();
};

class TaiKhoanNhanVien : public TaiKhoan{
    private :
        NhanVien nv;
    public :
        TaiKhoanNhanVien();
        ~TaiKhoanNhanVien() override = default;
        void DatMatKhau() override;
        void DatTenDangNhap() override;
};

#endif