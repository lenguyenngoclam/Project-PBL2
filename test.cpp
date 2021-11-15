#include <iostream>
#include <string>
#include <fstream>
#include "test-h.cpp"
#include "NhanVien.cpp"
#include "NganHang.cpp"

using namespace std;

int main(){
    DanhSachNhanVien ds;
    ds.CaiDatDanhSach();
    ds.InDanhSach();

    // Node<NhanVien>* current = ds.getHead();
    // (current -> getData()).DoiThongTinCaNhan();
    // cout << "------------Danh sach moi------------" << endl;
    // ds.InDanhSach();

    NhanVien nv;
    nv.CaiDatThongTin();
    nv.LayThongTinCaNhan();
    ds.SuaDanhSach(nv);
    cout << "------------Danh sach moi------------" << endl;
    ds.InDanhSach();
    return 0;
}