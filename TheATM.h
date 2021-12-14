#ifndef TheATM_h
#define TheATM_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"
#include "LichSuGiaoDich.cpp"

class TheATM{
    private :
        string MaTaiKhoan;
        string MatKhau;
        double soDu;
        string idKhachHang;
        LinkedList<LichSuGiaoDich> ls;
    public :    
        TheATM(string tk, string mk) : MaTaiKhoan(tk), MatKhau(mk), soDu(0), idKhachHang("") {};
        TheATM(string tk, string mk, double d, string id) : soDu(d), MatKhau(mk), MaTaiKhoan(tk), idKhachHang(id){};
        TheATM() : soDu(0), MatKhau(""), MaTaiKhoan(""), idKhachHang(""){};

        TheATM(const TheATM&);

        TheATM& operator =(const TheATM& the);

        void NapTien(double soTien, string);
        void RutTien(double , string);
        double laySoDu();

        string layMaThe() { return MaTaiKhoan; }
        string layIDKhachHang() { return idKhachHang; }

        // Hàm thành viên có tác dụng ghi lại tất cả các dòng trong file KHACHHANG.txt nhưng thay đổi số dư của thẻ dựa trên con trỏ hàm
        void suaFile(double (*func)(double, double), double soTien);
        //Ghi lịch sử giao dịch vào file
        void ghiFile(LichSuGiaoDich& lsu);

        // Ghi dữ liệu người dùng nhập vào file 
        void caiDatTheATM();
        // Hiển thị mã tài khoản và số dư của thẻ
        void layThongTinThe() const;
        // Chuyển tiền cho thẻ ATM khác
        void chuyenTien(TheATM& maThe, double tien);
        //In lịch sử giao dịch
        void inLichSuGiaoDich();
        //Thêm lịch sử giao dịch tử file
        void caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich&);
        void xoaTheATM();

        friend class KhachHang;
        friend class DanhSachKhachHang;
        friend ostream& operator<<(ostream& os, const TheATM& the);

        bool operator==(const TheATM& the);
};

ostream& operator<<(ostream& os, const TheATM& the){
    the.layThongTinThe();
    return os;
}

#endif