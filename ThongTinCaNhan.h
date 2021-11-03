#ifndef ThongTinCaNhan_h
#define ThongTinCaNhan_h

#include <iostream>
#include <string>

using namespace std;

class ThongTinCaNhan{
    protected :
        string hoTen;
        string diaChi;
        string soDienThoai;
        int tuoi;
    public :
        ThongTinCaNhan(string, string, string);
        virtual ~ThongTinCaNhan();
        void layThongTinCaNhan();
};
#endif