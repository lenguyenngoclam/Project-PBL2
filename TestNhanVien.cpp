#include <iostream>
#include "NhanVien.cpp"
#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.cpp"
#include "LinkedListTemplate.h"

using namespace std;

int main()
{
    DanhSachNhanVien ds;
    ds.CaiDatDanhSach();
    ds.InDanhSach();

    // Node<NhanVien> *current = ds.getHead();
    // (current -> getData()).DoiThongTinCaNhan();
    // ds.InDanhSach();

    NhanVien kh;
    cout << "- Nhap nhan vien moi:\n";
    kh.CaiDatThongTin();
    ds.SuaDanhSach(kh);
    ds.InDanhSach();

    string id;
    cout << "- Nhap ID nhan vien can tim: "; getline(cin,id); fflush(stdin);
    ds.TimKiemNhanVien(id);
    return 0;
}