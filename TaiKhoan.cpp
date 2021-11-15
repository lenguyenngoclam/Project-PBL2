#include <iostream>
#include "TaiKhoan.h"

using namespace std;

string TaiKhoan::giaoDienThemTaiKhoan(){
    cout << "Loai tai khoan muon them";
    string choice;
    cin >> choice;
    return choice;
}

void DanhSachTaiKhoan::themTaiKhoan(TaiKhoan *tk){
    ls.insert(tk);
}