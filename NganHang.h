#ifndef NganHang_h
#define NganHang_h
#include <iostream>
#include "LinkedListTemplate.h"

using namespace std;

class DanhSachNganHang;

class NganHang{
    private :
        string idNganHang;
        string TenNganHang;
        string DiaChiNganHang;
    public :
        static int s_id;
        NganHang();
        NganHang(string ten, string diachi);
        NganHang(const NganHang& nh);
        NganHang& operator=(const NganHang& nh);

        // Relational operator overloading
        bool operator >(const NganHang& nh) const;
        bool operator ==(const NganHang& nh) const;
        bool operator <(const NganHang& nh) const;
        bool operator !=(const NganHang& nh) const;

        ~NganHang() = default;

        static void CaiDatID();
        bool DangNhapTaiKhoan(); 
        friend ostream& operator <<(ostream& os, const NganHang& nh);
        friend class DanhSachNganHang;
};

class DanhSachNganHang{
    private :
        LinkedList<NganHang> ls;
    public :
        DanhSachNganHang() = default;
        ~DanhSachNganHang() = default;

        void ThemNganHang();
        void LayThongTinNganHang(string t, string dc);
        void InNganHang();
};

ostream& operator<<(ostream& os, const NganHang& nh){
    if(nh.TenNganHang == "" && nh.DiaChiNganHang == "")
        return os;
    os << "Ten Ngan Hang : " << nh.TenNganHang << endl;
    os << "Dia chi Ngan Hang : " << nh.DiaChiNganHang << endl;
    return os;
}
#endif

