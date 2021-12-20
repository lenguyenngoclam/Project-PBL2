#ifndef LICHSUGIAODICH_CPP
#define LICHSUGIAODICH_CPP

#include <string.h>

#include "LichSuGiaoDich.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------
// LICH SU GIAO DICH

ostream& operator <<(ostream& os, const LichSuGiaoDich& ls){
    if ((ls.noiDung).size() <= 62) os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(33) << "|" << endl;
    else if ((ls.noiDung).size() > 62 && (ls.noiDung).size() <= 63) os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(32) << "|" << endl;
    else if ((ls.noiDung).size() > 63 && (ls.noiDung).size() < 89) os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(31) << "|" << endl;
    else if ((ls.noiDung).size() >= 89 && (ls.noiDung).size() < 91) os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(11) << "|" << endl;
    else if ((ls.noiDung).size() >= 91 && (ls.noiDung).size() < 95) os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(7) << "|" << endl;
    else os << "\t\t|" << setw(12) << ls.maGiaoDich << setw(11) << "|  " << ls.noiDung << setw(11) << "|" << endl;
    os << "\t\t+--------------------+----------------------------------------------------------------------------------+" << endl;
    return os;
}

void LichSuGiaoDich::xoaLichSuGiaoDich(){
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);
    ofstream fout;
    fout.open("temp1.txt", ios::app);

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

    fout.close();
    fin.close(); 

    remove("LichSuGiaoDich.txt");
    rename("temp1.txt", "LichSuGiaoDich.txt");
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH LICH SU GIAO DICH

void DanhSachLichSuGiaoDich::capNhatDanhSach(){
    ls.deleteList();
    lichsu_count_line = 0;
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