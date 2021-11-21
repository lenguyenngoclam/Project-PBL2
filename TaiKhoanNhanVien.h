#ifndef TAIKHOANNHANVIEN_H
#define TAIKHOANNHANVIEN_H

#include "NhanVien.cpp"

using namespace std;

class TaiKhoanNhanVien : public TaiKhoan{
    private :
        NhanVien nv;
    public :
        TaiKhoanNhanVien();
        TaiKhoanNhanVien(string ten, string mk);
        ~TaiKhoanNhanVien() override = default;

        TaiKhoanNhanVien(const TaiKhoanNhanVien& tk);

        void DatTaiKhoan() override;
        
        //string kiemTraDangNhap() override;

        TaiKhoanNhanVien& operator=(const TaiKhoanNhanVien& rhs);        
        ostream& getInfo(ostream&) override;
        friend class SuKien;
};

#endif