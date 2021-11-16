#ifndef NhanVien_h
#define NhanVien_h

#include <iostream>
#include <fstream>
#include "TaiKhoan.cpp"
#include "ThongTinCaNhan.cpp"
#include "LinkedListTemplate.h"

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

        ~NhanVien() override = default;

        NhanVien(const NhanVien& nv);
        NhanVien& operator =(const NhanVien& nv);

        string LaySoLuong();

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;
        void CaiDatThongTin();

        bool operator <(const NhanVien& rhs) const;
        bool operator >(const NhanVien& rhs) const;
        bool operator !=(const NhanVien& rhs) const;

        friend class DanhSachNhanVien;
        friend class TaiKhoanNhanVien;
        friend ostream& operator <<(ostream& os, const NhanVien& nv);
};


class TaiKhoanNhanVien : public TaiKhoan{
    private :
        NhanVien nv;
    public :
        TaiKhoanNhanVien();
        TaiKhoanNhanVien(string ten, string mk);
        ~TaiKhoanNhanVien() override = default;

        TaiKhoanNhanVien(const TaiKhoanNhanVien& tk);

        void datTaiKhoan() override;
        
        //string kiemTraDangNhap() override;

        TaiKhoanNhanVien& operator=(const TaiKhoanNhanVien& rhs);        
        ostream& getInfo(ostream&) override;
        friend class SuKien;
};


class DanhSachNhanVien{
    private :
        LinkedList<NhanVien> ls;
    public :
        DanhSachNhanVien() = default;
        ~DanhSachNhanVien() = default;

        void CaiDatDanhSach();
        void InDanhSach();
        void SuaDanhSach(const NhanVien &nv);
        void themNhanVien(NhanVien& nv); 
        Node<NhanVien>* getHead();

        friend class NhanVien;
};


#endif