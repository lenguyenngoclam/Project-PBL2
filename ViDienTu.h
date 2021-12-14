#ifndef VIDIENTU_H
#define VIDIENTU_H
#include <iostream>

#include "include.h"
#include "includeKhachHang.h"
#include "TheATM.cpp"

using namespace std;

class DanhSachViDienTu;

class ViDienTu : public TaiKhoan{
    private :
        LinkedList<string> lsID;
        double tongSoDu;
    public :
        ViDienTu() = default;
        ViDienTu(string tk, string mk) : TaiKhoan(tk,mk), tongSoDu(0) {}
        ViDienTu(const ViDienTu& vi) : TaiKhoan(vi.TenDangNhap, vi.MatKhau), lsID(vi.lsID), tongSoDu(vi.tongSoDu) {};

        ViDienTu& operator =(const ViDienTu& vi);

        ~ViDienTu() = default;
        
        void suaFile(double (*func)(double, double), double soTien);
        void themLienKetTheATM(TheATM& the);
        void rutTien(DanhSachKhachHang& ds);
        void napTien(DanhSachKhachHang& ds);
        void chuyenTienDenThe(TheATM& the, double soTien);
        void chuyenTienDenVi(ViDienTu& vi, double soTien);
        void caiDatVi();
        void goLienKetTheATM(string maThe);
        
        string layTaiKhoan() { return TenDangNhap; }
        LinkedList<string>& getList() { return lsID; }
        double laySoDu() { return tongSoDu; }

        bool operator ==(const ViDienTu& rhs);

        friend class DanhSachViDienTu;
        friend ostream& operator <<(ostream& os, const ViDienTu& vi);
};

ostream& operator <<(ostream& os, const ViDienTu& vi){
    cout << vi.TenDangNhap << " " << vi.MatKhau << " " << vi.tongSoDu << endl;
    return os;
}

class DanhSachViDienTu{
    private :
        LinkedList<ViDienTu> lsViDienTu;
    public :
        DanhSachViDienTu() = default;

        ~DanhSachViDienTu() = default;
        
        void capNhatDanhSach();
        void caiDatDanhSach();
        void taoViDienTu();
        bool kiemTraDangNhap(string tk, string mk);
        ViDienTu& suDungVi(string tk, string mk);
        size_t suDungVi(string id);

        LinkedList<ViDienTu>& getListVi() { return lsViDienTu; }

};

#endif