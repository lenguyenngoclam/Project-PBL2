#include "ThongTinCaNhan.h"

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

void ThongTinCaNhan::CaiDatThongTin()
{
    cout << "\t\t- Nhập họ và tên: "; getline(cin,HoTen);
    cout << "\t\t- Nhập tuổi: "; fflush(stdin); getline(cin, Tuoi);
    cout << "\t\t- Nhập địa chỉ: "; fflush(stdin); getline(cin,DiaChi);
    cout << "\t\t- Nhập số điện thoại: "; fflush(stdin); getline(cin, SoDienThoai);
}

