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
        void layThongTin();
        void caiDatThongTin();
};

class TaiKhoanNhanVien : public TaiKhoan{
    private :
        NhanVien nv;
    public :
        TaiKhoanNhanVien();
        ~TaiKhoanNhanVien() override = default;
        void datMatKhau() override;
        void datTenDangNhap() override;
};

#endif