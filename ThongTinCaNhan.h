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
        int Tuoi;
    public :
        ThongTinCaNhan(string = "",string = "",string = "",int = 19);
        virtual ~ThongTinCaNhan() {}
        void LayThongTinCaNhan();
        void NhapThongTinCaNhan();
        void DoiThongTinCaNhan();
};
#endif