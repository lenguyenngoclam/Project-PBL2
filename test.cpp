#include <iostream>
#include <string>
#include "test-h.cpp"
#include <fstream>
#include "NhanVien.cpp"

using namespace std;

int main(){

    DanhSachNhanVien ds;
    ds.caiDatDanhSach();
    ds.inDanhSach();

    Node<NhanVien>* current = ds.getHead();
    (current -> getNext() -> getData()).DoiThongTinCaNhan();
    return 0;
}