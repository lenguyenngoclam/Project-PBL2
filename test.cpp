#include <iostream>
#include <string>
#include <fstream>
#include "Sukien.cpp"

using namespace std;

int main(){
    SuKien event;
    DanhSachNhanVien ls;
    ls.CaiDatDanhSach();
    while(event.suKienThemTaiKhoan(ls)){
        break;
    }

    ls.InDanhSach();
    return 0;
}