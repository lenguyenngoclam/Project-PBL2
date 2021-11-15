#include <iostream>
#include <string>
#include <fstream>

#include "ThongTinCaNhan.h"
#include "TaiKhoan.h"
#include "KhachHang.h"

using namespace std;

int count_line = 0;

KhachHang::KhachHang(string id, string ten, string dc, string sdt, string t) : ThongTinCaNhan(ten,dc,sdt,t) {
    idKhachHang = id;
}

KhachHang::KhachHang(const KhachHang &kh) : ThongTinCaNhan(kh) {
    idKhachHang = kh.idKhachHang;
}

KhachHang &KhachHang::operator =(const KhachHang &kh) {
    ThongTinCaNhan::operator =(kh);
    idKhachHang = kh.idKhachHang;
    return *this;
}

void KhachHang::DoiThongTinCaNhan() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
    ofstream fout;
    fout.open("temp.txt", ios::app);
    this -> ThongTinCaNhan::DoiThongTinCaNhan();
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == count_line) fout << line; 
        else { 
            count++; 
            fout << line << endl; 
        }
        if(line == idKhachHang){
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

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");
}

void KhachHang::LayThongTinCaNhan() const {
    cout << "- ID: " << idKhachHang << endl;
    ThongTinCaNhan::LayThongTinCaNhan();
}

void KhachHang::CaiDatThongTin()
{
    ThongTinCaNhan::NhapThongTinCaNhan();
}