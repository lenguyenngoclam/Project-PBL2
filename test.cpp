#include <iostream>
#include <initializer_list>
#include "NhanVien.cpp"

using namespace std;

int main(){

    NhanVien nv("","Le Nguyen Ngoc Lam","48C k20","0962814899","20");
    TaiKhoanNhanVien tk("ngoclam3092002","3092002");
    tk.themTaiKhoan(nv);
    return 0;
}