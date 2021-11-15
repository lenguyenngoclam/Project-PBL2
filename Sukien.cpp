#include <iostream>
#include "Sukien.h"

using namespace std;

bool SuKien::suKienThemTaiKhoan(DanhSachNhanVien& ls){
    string choice;
    cout << "Loại tài khoản muốn thêm";
    getline(cin,choice);

    string tenDangNhap, matKhau;
    cout << "TÀI KHOẢN : " << endl;
    getline(cin, tenDangNhap);
    cout << "Mật khẩu : " << endl;
    getline(cin, matKhau);

    if(choice == "NV"){
        TaiKhoanNhanVien temp(tenDangNhap,matKhau);
        temp.nv.CaiDatThongTin();
        dsTaiKhoan.themTaiKhoan(&temp);
        ls.themNhanVien(temp.nv);
    }
    return true;
}