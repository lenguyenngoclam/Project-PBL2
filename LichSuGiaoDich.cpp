#ifndef LICHSUGIAODICH_CPP
#define LICHSUGIAODICH_CPP

#include "LichSuGiaoDich.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------
// LICH SU GIAO DICH

ostream& operator <<(ostream& os, const LichSuGiaoDich& ls){
    cout << "# Mã giao dịch : " << ls.maGiaoDich << endl;
    cout << "  Nội dung giao dịch : " << ls.noiDung;
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

        ls.insert(temp);
        lichsu_count_line += 3;
    }

    fin.close();
}

#endif