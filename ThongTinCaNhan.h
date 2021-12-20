#ifndef ThongTinCaNhan_h
#define ThongTinCaNhan_h

#include <iostream>
#include <string>

using namespace std;

class ThongTinCaNhan{
    protected :
        string HoTen;
        string DiaChi;
        string SoDienThoai;
        string Tuoi;
    public :
        ThongTinCaNhan(string = "",string = "",string = "",string = "19");

        virtual ~ThongTinCaNhan() {}

        ThongTinCaNhan(const ThongTinCaNhan&);
        ThongTinCaNhan& operator =(const ThongTinCaNhan&);

        virtual void InThongTin() const;
        virtual void CaiDatThongTin();
        virtual void DoiThongTinCaNhan();

};

// Vì là hàm ảo nên phải khai báo chung 1 file
void ThongTinCaNhan::InThongTin() const
{
    cout << "|" << setw(27) << HoTen << setw(8) << "|" << setw(5) << Tuoi << setw(4) << 
    "|" << setw(21) << DiaChi << setw(7) << "|" << setw(15) << SoDienThoai << setw(5) << "|" << endl;
    cout << "\t\t+-------------+----------------------------------+--------+---------------------------+-------------------+" << endl;
}

void ThongTinCaNhan::DoiThongTinCaNhan()
{
    int opt;
    cout << "\t\t----------- Chọn thông tin muốn thay đổi ------------" << endl;
    cout << "\t\t + Option 1: Họ và tên" << endl;
    cout << "\t\t + Option 2: Tuổi" << endl;
    cout << "\t\t + Option 3: Địa chỉ" << endl;
    cout << "\t\t + Option 4: Số điện thoại" << endl;
    cout << "\t\t -> Option của bạn: "; cin >> opt; fflush(stdin); 
    switch (opt)
    {
        case 1: {
            cout << "\t\t- Nhập họ và tên mới: "; 
            getline(cin,HoTen); fflush(stdin); break;
        }
        case 2: {
            cout << "\t\t- Nhập tuổi mới: "; 
            getline(cin,Tuoi);  fflush(stdin);break;
        }
        case 3: {
            cout << "\t\t- Nhập địa chỉ mới: "; 
            getline(cin,DiaChi); fflush(stdin); break;
        }
        case 4: {
            cout << "\t\t- Nhập số điện thoại mới: "; 
            getline(cin,SoDienThoai); fflush(stdin); break;
        }
    }
}

#endif