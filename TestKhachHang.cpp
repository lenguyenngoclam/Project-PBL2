#include <iostream>
#include "KhachHang.cpp"
#include "ThongTinCaNhan.cpp"
#include "LinkedListTemplate.h"

using namespace std;

int main()
{
    DanhSachKhachHang ds;
    ds.CaiDatDanhSach();
    ds.InDanhSach();

    // Node<KhachHang> *current = ds.getHead();
    // (current -> getData()).DoiThongTinCaNhan();
    // ds.InDanhSach();

    KhachHang kh;
    cout << "- Nhap khach hang moi:\n";
    kh.CaiDatThongTin();
    ds.SuaDanhSach(kh);
    ds.InDanhSach();

    string id;
    cout << "- Nhap ID khach hang can tim: "; getline(cin,id); fflush(stdin);
    ds.TimKiemKhachHang(id);
    return 0;
}