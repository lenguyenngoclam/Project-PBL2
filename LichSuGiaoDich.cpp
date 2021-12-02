#ifndef LichSuGiaoDich_h
#define LichSuGiaoDich_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"

using namespace std;

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
        Set<LichSuGiaoDich> set;
    public :
        DanhSachLichSuGiaoDich() : set(soLuongGiaoDich) {};

        DanhSachLichSuGiaoDich& operator =(const DanhSachLichSuGiaoDich& rhs){
            set = rhs.set;
            return (*this);
        }

        void caiDatDanhSach();
        void themLichSuGiaoDich(LichSuGiaoDich& lsu){
            set.insert(lsu);
        }

        friend class TheATM;
        friend class DanhSachKhachHang;
};


// ----------------------------------------------------------------------------------------------------------------------------------------------
// LICH SU GIAO DICH

ostream& operator <<(ostream& os, const LichSuGiaoDich& ls){
    cout << "Mã giao dịch : " << ls.maGiaoDich << endl;
    cout << "Nội dung giao dịch : " << ls.noiDung;
    return os;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH LICH SU GIAO DICH

void DanhSachLichSuGiaoDich::caiDatDanhSach(){
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);

    string line;
    lichsu_count_line++;
    getline(fin, line);
    while(getline(fin, line)){
        LichSuGiaoDich temp;
        temp.maGiaoDich = line;
        getline(fin, temp.noiDung);
        getline(fin, temp.maTaiKhoan);

        set.insert(temp);
        lichsu_count_line += 3;
    }

    fin.close();
}

#endif