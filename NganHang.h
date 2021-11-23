#ifndef NganHang_h
#define NganHang_h
#include <iostream>
#include "SetTemplate.h"

using namespace std;

class DanhSachNganHang;

class NganHang{
    private :
        string idNganHang;
        string TenNganHang;
        string DiaChiNganHang;
    public :
        NganHang();
        NganHang(string id,string t, string dc);
        NganHang(const NganHang& nh);
        NganHang& operator=(const NganHang& nh);

        // Relational operator overloading
        bool operator >(const NganHang& nh);
        bool operator ==(const NganHang& nh) const;
        bool operator <(const NganHang& nh) const;
        bool operator !=(const NganHang& nh) const;

        ~NganHang() = default;

        bool DangNhapTaiKhoan(); 
        void LayThongTinNganHang();
        friend ostream& operator <<(ostream& os, const NganHang& nh);
        friend class DanhSachNganHang;
};

class DanhSachNganHang{
    private :
        Set<NganHang> set;
    public :
        DanhSachNganHang() = default;
        ~DanhSachNganHang() = default;

        void ThemNganHang();
        void LayThongTinNganHang(string id,string t, string dc);
        void InNganHang();
};

ostream& operator <<(ostream& os, const NganHang& nh){
    if(nh.TenNganHang == "" && nh.DiaChiNganHang == "")
        return os;
    os << "ID Ngan Hang: " << nh.idNganHang << endl;
    os << "Ten Ngan Hang : " << nh.TenNganHang << endl;
    os << "Dia chi Ngan Hang : " << nh.DiaChiNganHang << endl;
    os << "--------------------------------------------------" << endl;
    return os;
}
#endif

