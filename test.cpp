#include <iostream>
#include <string>
#include <fstream>
#include "Sukien.cpp"

using namespace std;

int main(){
<<<<<<< HEAD
    // DanhSachNhanVien ds;
    // ds.CaiDatDanhSach();
    // ds.InDanhSach();

    // Node<NhanVien>* current = ds.getHead();
    // (current -> getData()).DoiThongTinCaNhan();
    // cout << "------------Danh sach moi------------" << endl;
    // ds.InDanhSach();

    NhanVien nv;
    nv.CaiDatThongTin();
    nv.LayThongTinCaNhan();
    // ds.SuaDanhSach(nv);
    // cout << "------------Danh sach moi------------" << endl;
    // ds.InDanhSach();
=======
    TaiKhoanNhanVien temp("ngoclam3092002","3092002");
    DanhSachTaiKhoan ds;
    ds.themTaiKhoan(&temp);
    ds.head -> data -> getInfo(cout);
>>>>>>> main
    return 0;
}