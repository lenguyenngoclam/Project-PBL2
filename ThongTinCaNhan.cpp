#include "ThongTinCaNhan.h"
#include <iostream>
#include <string>

using namespace std;

ThongTinCaNhan::ThongTinCaNhan(string ten,string dchi,string sdt,string tuoi) : HoTen(ten), DiaChi(dchi), SoDienThoai(sdt), Tuoi(tuoi)
{

}

ThongTinCaNhan::ThongTinCaNhan(const ThongTinCaNhan& tt){
    HoTen = tt.HoTen;
    DiaChi = tt.DiaChi;
    SoDienThoai = tt.SoDienThoai;
    Tuoi = tt.Tuoi;
}

ThongTinCaNhan& ThongTinCaNhan::operator =(const ThongTinCaNhan& tt){
    HoTen = tt.HoTen;
    DiaChi = tt.DiaChi;
    SoDienThoai = tt.SoDienThoai;
    Tuoi = tt.Tuoi;
    return (*this);
}

void ThongTinCaNhan::NhapThongTinCaNhan()
{
    cout << "- Nhap ho va ten: "; getline(cin,HoTen);
    cout << "- Nhap tuoi: "; fflush(stdin); getline(cin, Tuoi);
    cout << "- Nhap dia chi: "; fflush(stdin); getline(cin,DiaChi);
    cout << "- Nhap so dien thoai: "; fflush(stdin); getline(cin, SoDienThoai);
}

