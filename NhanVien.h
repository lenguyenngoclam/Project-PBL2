#ifndef NhanVien_h
#define NhanVien_h

#include <iostream>
#include <fstream>

#include "include.h"

using namespace std;

class DanhSachNhanVien;
class TaiKhoanNhanVien;
class DanhSachTaiKhoanNhanVien;

string LaySoLuongNhanVien() {
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_NhanVien = LaySoLuongNhanVien();
int soLuongNhanVien = stoi(number_NhanVien);

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

        string LayTen() const { return HoTen; }
        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;
        void CaiDatThongTin() override;

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
        LinkedList<NhanVien> ls;
    public :
        DanhSachNhanVien() : ls() {}
        ~DanhSachNhanVien() = default;

        void CaiDatDanhSach();
        void InDanhSach();

        void TimKiemNhanVien(string id);
        
        LinkedList<NhanVien>& getListNhanVien() { return ls; }

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
        LinkedList<TaiKhoanNhanVien> ls;
    public :
        DanhSachTaiKhoanNhanVien() : ls() {};
        ~DanhSachTaiKhoanNhanVien();
        void caiDatDanhSach();
        // Kiểm tra tài khoản có hợp lệ không
        bool kiemTraTaiKhoan(TaiKhoanNhanVien& nv);
        void inDanhSach();
        TaiKhoanNhanVien& suDungTaiKhoan(string, string);

        friend class TaiKhoanNhanVien;
};


#endif