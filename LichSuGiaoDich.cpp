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

void LichSuGiaoDich::xoaLichSuGiaoDich(){
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    string line;
    lichsu_count_line -= 3;
    int count = 1;

    getline(fin, line);
    fout << line << endl;
    count++;
    while(getline(fin, line)){
        if(maGiaoDich != line){
            fout << line << endl;
            getline(fin,line);
            fout << line << endl;
            count += 2;
            getline(fin,line); 
            if(count == lichsu_count_line)
                fout << line;
            else fout << line << endl;  
            count++;
        } else {
            getline(fin,line);
            getline(fin,line);
        }
    }

    remove("LichSuGiaoDich.txt");
    rename("temp.txt", "LichSuGiaoDich.txt");

    fout.close();
    fin.close(); 
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH LICH SU GIAO DICH

void DanhSachLichSuGiaoDich::capNhatDanhSach(){
    ls.deleteList();
    caiDatDanhSach();
}

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