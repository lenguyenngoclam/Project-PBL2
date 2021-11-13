#include <iostream>
#include <fstream>
#include <vector>
#include "NhanVien.h"

using namespace std;

int count_line = 0;

NhanVien::NhanVien(string id, string ten, string dc, string sdt, string t) : ThongTinCaNhan(ten,dc,sdt,t) {
    idNhanVien = id;
}

NhanVien::NhanVien(const NhanVien& nv) : ThongTinCaNhan(nv){
    idNhanVien = nv.idNhanVien;
}
NhanVien& NhanVien::operator =(const NhanVien& nv){
    ThongTinCaNhan::operator=(nv);
    idNhanVien = nv.idNhanVien;
    return (*this);
}

// Đổi thông tin cá nhân
void NhanVien::DoiThongTinCaNhan(){
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    //Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
    ofstream fout;
    fout.open("temp.txt", ios::app);
    this -> ThongTinCaNhan::DoiThongTinCaNhan();
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == count_line) fout << line; 
        else { count++; fout << line << endl; }
        if(line == idNhanVien){
            for(int i = 0; i < 4; i++){
                getline(fin, line);
                line.replace(0, line.length(), a[i]);
                b[i] = a[i];
                fout << line << endl;
            }
            count += 4;
        }
    }

    fin.close();
    fout.close();

    remove("NHANVIEN.txt");
    rename("temp.txt","NHANVIEN.txt");
}


void NhanVien::LayThongTinCaNhan() const{
    cout << "- ID: " << idNhanVien << endl;
    ThongTinCaNhan::LayThongTinCaNhan();
}

bool NhanVien::operator !=(const NhanVien& rhs) const{
    return idNhanVien.compare(rhs.idNhanVien) != 0;
}

bool NhanVien::operator <(const NhanVien& rhs) const{
    return idNhanVien.compare(rhs.idNhanVien) < 0;
}

bool NhanVien::operator >(const NhanVien& rhs) const{
    return idNhanVien.compare(rhs.idNhanVien) > 0;
}

// DanhSachNhanVien 
void DanhSachNhanVien::CaiDatDanhSach(){
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    while(!fin.eof()){
        NhanVien temp;
        getline(fin, temp.idNhanVien);
        getline(fin, temp.HoTen);
        getline(fin, temp.Tuoi);
        getline(fin, temp.DiaChi);
        getline(fin, temp.SoDienThoai);
        ls.insert(temp);
        count_line += 5;
    }
    fin.close();
}

ostream& operator <<(ostream& os, const NhanVien& nv){
    nv.LayThongTinCaNhan();
    return os;
}

void DanhSachNhanVien::InDanhSach(){
    ls.printList();
}

Node<NhanVien>* DanhSachNhanVien::getHead(){
    return ls.getHead();
}

