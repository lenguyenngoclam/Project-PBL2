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

    Node<NhanVien>* current = ds.getHead();
    (current -> getNext() -> getData()).DoiThongTinCaNhan();
    // ds.InDanhSach();
    return 0;
}