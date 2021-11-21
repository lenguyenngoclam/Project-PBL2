#include <iostream>
#include <string>
#include "TaiKhoanNhanVien.h"

using namespace std;


TaiKhoanNhanVien::TaiKhoanNhanVien(string ten, string mk) : TaiKhoan(ten,mk), nv() {}

void TaiKhoanNhanVien::DatTaiKhoan(){
    ofstream fout;
    fout.open("TAIKHOAN.txt", ios::app);
    TaiKhoanNhanVien temp("NV" + TenDangNhap, MatKhau);

    fout << temp.TenDangNhap << endl;
    fout << temp.MatKhau << endl;
}

ostream& TaiKhoanNhanVien::getInfo(ostream& os){
    TaiKhoan::getInfo(os);
    return os;
}

TaiKhoanNhanVien::TaiKhoanNhanVien(const TaiKhoanNhanVien& tk) : TaiKhoan(tk), nv(tk.nv) {}

TaiKhoanNhanVien& TaiKhoanNhanVien::operator=(const TaiKhoanNhanVien& rhs){
    TenDangNhap = rhs.TenDangNhap;
    MatKhau = rhs.MatKhau;
    nv = rhs.nv;

    return (*this);
}
/*
string TaiKhoanNhanVien::kiemTraDangNhap(){
    return "NV";
}
*/