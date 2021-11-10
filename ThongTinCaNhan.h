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

        virtual void LayThongTinCaNhan() const;
        void NhapThongTinCaNhan();
        virtual void DoiThongTinCaNhan();

};

// Vì là hàm ảo nên phải khai báo chung 1 file
void ThongTinCaNhan::LayThongTinCaNhan() const
{
    cout << "- Ho va ten: " << HoTen << endl;
    cout << "- Tuoi: " << Tuoi << endl;
    cout << "- Dia chi: " << DiaChi << endl;
    cout << "- So dien thoai: " << SoDienThoai << endl;
    cout << "--------------------------------------------------" << endl;
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
            getline(cin,Tuoi); break;
        }
        case 3: {
            fflush(stdin);
            cout << "- Nhap dia chi: "; 
            getline(cin,DiaChi); break;
        }
        case 4: {
            fflush(stdin);
            cout << "- Nhap so dien thoai: "; 
            getline(cin, SoDienThoai); break;
        }
    }
    cout << "----------Thong tin moi----------" << endl;
    LayThongTinCaNhan();
}


#endif