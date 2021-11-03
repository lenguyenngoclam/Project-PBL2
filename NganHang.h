#ifndef NganHang_h
#define NganHang_h
#include <iostream>
#include "LinkedListTemplate.h"

using namespace std;

class NganHang{
    private :
        string idNganHang;
        string tenNganHang;
        string diaChiNganHang;
    public :
        static int s_id;
        NganHang();
        NganHang(string ten, string diaChi);
        NganHang(const NganHang& nh);
        NganHang& operator=(const NganHang& nh);

        //Relational operator overloading
        bool operator>(const NganHang& nh) const;
        bool operator==(const NganHang& nh) const;
        bool operator<(const NganHang& nh) const;
        bool operator!=(const NganHang& nh) const;

        ~NganHang() = default;

        static void caiDatID();
        bool dangNhapTaiKhoan(); 
        friend ostream& operator<<(ostream& os, const NganHang& nh);
};

class DanhSachNganHang{
    private :
        LinkedList<NganHang> ls;
    public :
        DanhSachNganHang() = default;
        ~DanhSachNganHang() = default;

        void themNganHang();
        void layThongTinNganHang(string t, string dc);
        void inNganHang();
        void xoaTaiKhoan();
        void themTaiKhoan();
};

ostream& operator<<(ostream& os, const NganHang& nh){
    os << "Ten Ngan Hang : " << nh.tenNganHang << endl;
    os << "Dia chi Ngan Hang : " << nh.diaChiNganHang << endl;
    return os;
}
#endif

