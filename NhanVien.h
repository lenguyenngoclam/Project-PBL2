#ifndef NhanVien_h
#define NhanVien_h

#include <iostream>
#include <fstream>

#include "include.h"

using namespace std;

class DanhSachNhanVien;
class TaiKhoanNhanVien;
class DanhSachTaiKhoanNhanVien;

class NhanVien : public ThongTinCaNhan{
    private :
        string idNhanVien;
        TaiKhoanNhanVien *taiKhoanNhanVien;
        void themTaiKhoan(TaiKhoanNhanVien&);
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
        friend class DanhSachTaiKhoanNhanVien;
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

        void TimKiemNhanVien(string id);
        
        Set<NhanVien>& getSetNhanVien() { return set; }

        friend class NhanVien;
};

class TaiKhoanNhanVien : public TaiKhoan{
    private :
        NhanVien nhanVien;
    public :
        TaiKhoanNhanVien();
        TaiKhoanNhanVien(string ten, string mk);
        ~TaiKhoanNhanVien() override = default;

        TaiKhoanNhanVien(const TaiKhoanNhanVien& tk);

        void themTaiKhoan(NhanVien& nv);
        string layTaiKhoan() { return TenDangNhap; }
        string layMatKhau() {return MatKhau; }
        NhanVien layNhanVien() { return nhanVien; }

        TaiKhoanNhanVien& operator=(const TaiKhoanNhanVien& rhs); 

        bool operator==(const TaiKhoanNhanVien& rhs);       
        friend class SuKien;
        friend class NhanVien;
        friend class DanhSachTaiKhoanNhanVien;
};

class DanhSachTaiKhoanNhanVien{
    private :
        Set<TaiKhoanNhanVien> set;
    public :
        DanhSachTaiKhoanNhanVien() : set() {};
        DanhSachTaiKhoanNhanVien(size_t n) : set(n) {};
        ~DanhSachTaiKhoanNhanVien();
        void caiDatDanhSach();
        bool kiemTraTaiKhoan(TaiKhoanNhanVien& nv);
        void inDanhSach();
        TaiKhoanNhanVien& suDungTaiKhoan(string, string);

        friend class TaiKhoanNhanVien;
};


#endif