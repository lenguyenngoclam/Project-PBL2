#include <iostream>
#include "TaiKhoan.h"

using namespace std;

ostream& TaiKhoan::getInfo(ostream& os){
    os << "Username : " << TenDangNhap << endl;
    os << "Password : " << MatKhau << endl;
    return os;
}

TaiKhoan::TaiKhoan(const TaiKhoan& tk) : TenDangNhap(tk.TenDangNhap), MatKhau(tk.MatKhau){}

