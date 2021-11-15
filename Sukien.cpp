#include <iostream>
#include "Sukien.h"

using namespace std;

bool SuKien::suKienThemTaiKhoan(){
    string choice = TaiKhoan::giaoDienThemTaiKhoan();
    string tenDangNhap, matKhau;
    cin >> tenDangNhap >> matKhau;
    if(choice == "NV"){
        TaiKhoanNhanVien temp(tenDangNhap,matKhau);
        temp.nv.CaiDatThongTin();
        dsTaiKhoan.themTaiKhoan(&temp);
    }
    return true;
}