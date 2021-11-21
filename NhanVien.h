#ifndef NhanVien_h
#define NhanVien_h

#include <iostream>
#include <fstream>

#include "ThongTinCaNhan.h"
#include "TaiKhoan.h"
#include "SetTemplate.cpp"

using namespace std;

class DanhSachNhanVien;
class TaiKhoanNhanVien;

class NhanVien : public ThongTinCaNhan{
    private :
        string idNhanVien;
    public :
        NhanVien() {
            ThongTinCaNhan();
        }
        NhanVien(string id, string hoten, string diachi, string sodienthoai, string tuoi);
        NhanVien(const string id) : ThongTinCaNhan(), idNhanVien(id) {}

        ~NhanVien() override = default;

        NhanVien(const NhanVien& nv);
        NhanVien& operator =(const NhanVien& nv);

        string LaySoLuong();

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;
        void CaiDatThongTin();

        bool operator ==(const NhanVien& rhs) const;
        bool operator <(const NhanVien& rhs) const;
        bool operator >(const NhanVien& rhs) const;
        bool operator !=(const NhanVien& rhs) const;

        friend class DanhSachNhanVien;
        friend class TaiKhoanNhanVien;
        friend ostream& operator <<(ostream& os, const NhanVien& nv);
};


class DanhSachNhanVien{
    private :
        Set<NhanVien> set;
    public :
        DanhSachNhanVien() = default;
        ~DanhSachNhanVien() = default;

        void CaiDatDanhSach();
        void InDanhSach();
        void SuaDanhSach(const NhanVien &nv);
        void ThemNhanVien(NhanVien& nv); 
        void TimKiemNhanVien(string id);

        friend class NhanVien;
};


#endif