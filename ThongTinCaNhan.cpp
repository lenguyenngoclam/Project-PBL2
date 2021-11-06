#include "ThongTinCaNhan.h"
#include <iostream>
#include <string>

using namespace std;

ThongTinCaNhan::ThongTinCaNhan(string ten,string dchi,string sdt,int tuoi) : HoTen(ten), DiaChi(dchi), SoDienThoai(sdt), Tuoi(tuoi)
{

}

void ThongTinCaNhan::LayThongTinCaNhan()
{
    cout << "- Ho va ten: " << HoTen << endl;
    cout << "- Tuoi: " << Tuoi << endl;
    cout << "- Dia chi: " << DiaChi << endl;
    cout << "- So dien thoai: " << SoDienThoai << endl;
}

void ThongTinCaNhan::NhapThongTinCaNhan()
{
    cout << "- Nhap ho va ten: "; getline(cin,HoTen);
    cout << "- Nhap tuoi: "; fflush(stdin); cin >> Tuoi; 
    cout << "- Nhap dia chi: "; fflush(stdin); getline(cin,DiaChi);
    cout << "- Nhap so dien thoai: "; fflush(stdin); cin >> SoDienThoai;
}

void ThongTinCaNhan::DoiThongTinCaNhan()
{
    int opt;
    cout << "--------Chon thong tin muon thay doi--------" << endl;
    cout << " + Option 1: Ho va ten" << endl;
    cout << " + Option 2: Tuoi" << endl;
    cout << " + Option 3: Dia chi" << endl;
    cout << " + Option 4: So dien thoai" << endl;
    cout << "- Chon option: "; cin >> opt; fflush(stdin); 
    switch (opt)
    {
        case 1: {
            cout << "- Nhap ho va ten moi: "; 
            getline(cin,HoTen); break;
        }
        case 2: {
            fflush(stdin);
            cout << "- Nhap tuoi: "; 
            cin >> Tuoi; break;
        }
        case 3: {
            fflush(stdin);
            cout << "- Nhap dia chi: "; 
            getline(cin,DiaChi); break;
        }
        case 4: {
            fflush(stdin);
            cout << "- Nhap so dien thoai: "; 
            cin >> SoDienThoai; break;
        }
    }
    cout << "----------Thong tin moi----------" << endl;
    LayThongTinCaNhan();
}