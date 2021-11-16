#include <iostream>
#include <string>
#include <fstream>
#include "Sukien.cpp"

using namespace std;

int main(){
    TaiKhoanNhanVien temp("ngoclam3092002","3092002");
    DanhSachTaiKhoan ds;
    ds.themTaiKhoan(&temp);
    ds.head -> data -> getInfo(cout);
    return 0;
}