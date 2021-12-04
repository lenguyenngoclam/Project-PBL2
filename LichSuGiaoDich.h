#ifndef LichSuGiaoDich_h
#define LichSuGiaoDich_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"

using namespace std;

int lichsu_count_line = 0;

class LichSuGiaoDich{
    private :
        string maGiaoDich;
        string noiDung;
        string maTaiKhoan;
    public :
        LichSuGiaoDich(string ma = "", string nd = "", string mtk = "") : maGiaoDich(ma), noiDung(nd), maTaiKhoan(mtk){}
        LichSuGiaoDich(const LichSuGiaoDich& ls) : maGiaoDich(ls.maGiaoDich), noiDung(ls.noiDung), maTaiKhoan(ls.maTaiKhoan) {};

        ~LichSuGiaoDich() = default;

        LichSuGiaoDich& operator =(const LichSuGiaoDich& ls){
            maGiaoDich = ls.maGiaoDich;
            noiDung = ls.noiDung;
            maTaiKhoan = ls.maTaiKhoan;
            return (*this);
        } 

        bool operator ==(const LichSuGiaoDich& rhs){
            return (maGiaoDich == rhs.maGiaoDich);
        }

        string layMaGiaoDich() { return maGiaoDich; }
        string layMaTaiKhoan() { return maTaiKhoan; }
        string layNoiDung() { return noiDung; }

        friend ostream& operator <<(ostream&, const LichSuGiaoDich&);
        friend class DanhSachLichSuGiaoDich;

};

class DanhSachLichSuGiaoDich{
    private :
        LinkedList<LichSuGiaoDich> ls;
    public :
        DanhSachLichSuGiaoDich() = default;

        DanhSachLichSuGiaoDich& operator =(const DanhSachLichSuGiaoDich& rhs){
            ls = rhs.ls;
            return (*this);
        }

        void caiDatDanhSach();
        void themLichSuGiaoDich(LichSuGiaoDich& lsu){
            ls.insert(lsu);
        }

        friend class TheATM;
        friend class DanhSachKhachHang;
};

#endif