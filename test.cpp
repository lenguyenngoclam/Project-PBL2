#include <iostream>
#include <string>
#include <fstream>

#include "TaiKhoan.cpp"
#include "Sukien.cpp"
#include "ThongTinCaNhan.cpp"

using namespace std;

int main(){
    string username, password;
    cout << "- Username: "; cin >> username;
    cout << "- Password: "; cin >> password;
    TaiKhoanNhanVien temp(username,password);
    DanhSachTaiKhoan ds;
    ds.ThemTaiKhoan(&temp);
    ds.head -> data -> getInfo(cout);
    return 0;
}