#ifndef Nhanvien_cpp
#define Nhanvien_cpp
#include <iostream>
#include <string>
#include <fstream>

#include "NhanVien.h"

using namespace std;

string LaySoLuongNhanVien() {
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_NhanVien = LaySoLuongNhanVien();

// ---------------------------------------------------------------------------------------------------------------------------------------
// NHANVIEN

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

string NhanVien::LaySoLuong()
{
    return number_NhanVien;
}

void NhanVien::themTaiKhoan(TaiKhoanNhanVien& tk){
    this -> taiKhoanNhanVien = &tk;
    CaiDatThongTin();
    ofstream fout;
    fout.open("NHANVIEN.txt", ios::app);
    fout << endl;
    fout << ("NV" + tk.layTaiKhoan()) << endl;
    fout << tk.layMatKhau();
    fout.close();
}

// Đổi thông tin cá nhân
void NhanVien::DoiThongTinCaNhan(){
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
    ofstream fout;
    fout.open("temp.txt", ios::app);
    this -> ThongTinCaNhan::DoiThongTinCaNhan();
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            number_NhanVien = line.substr(0,line.size()-1); // Cắt kí tự "\n" cuối line
            ++count; fout << line << endl;
        }
        else if (count == nhanVien_count_line) fout << line; 
        else { 
            ++count; 
            fout << line << endl; 
        }
        if (line == idNhanVien){
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

void NhanVien::CaiDatThongTin()
{
    string temp = "NV";
    int num = stoi(number_NhanVien);
    num++; 
    number_NhanVien = to_string(num);
    idNhanVien = temp + number_NhanVien;

    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            fout << number_NhanVien << endl;
            count++;
        } else {
            fout << line << endl;
        }
    }

    fout << idNhanVien << endl;
    fout << HoTen << endl;
    fout << Tuoi << endl;
    fout << DiaChi << endl;
    fout << SoDienThoai;

    fin.close();
    fout.close();

    remove("NHANVIEN.txt");
    rename("temp.txt","NHANVIEN.txt");    
}

bool NhanVien::operator ==(const NhanVien& rhs) const{
    return idNhanVien.compare(rhs.idNhanVien) == 0;
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

// ---------------------------------------------------------------------------------------------------------------------------------------
// DANHSACHNHANVIEN 

void DanhSachNhanVien::CaiDatDanhSach(){
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    getline(fin, number_NhanVien);
    nhanVien_count_line += 1;
    string line;
    while(!fin.eof()){
        NhanVien temp;
        getline(fin, temp.idNhanVien);
        getline(fin, temp.HoTen);
        getline(fin, temp.Tuoi);
        getline(fin, temp.DiaChi);
        getline(fin, temp.SoDienThoai);

        set.insert(temp);
        
        // Lấy ra 2 dòng chứa tài khoản và mật khẩu của nhân viên
        getline(fin, line);
        getline(fin, line);
        nhanVien_count_line += 7;
    }
    fin.close();
}

ostream& operator <<(ostream& os, const NhanVien& nv){
    cout << "Xin chào ! Tôi là : " << nv.HoTen;
    return os;
}

void DanhSachNhanVien::InDanhSach(){
    cout << "---------------Danh sach nhan vien---------------" << endl;
    for(size_t i = 0; i < set.getSize(); i++)
        set[i].LayThongTinCaNhan();
}

void DanhSachNhanVien::TimKiemNhanVien(string id) // Tìm kiếm nhân viên theo idNhanVien
{
    cout << "------------------Nhan Vien " << id << "-------------------" << endl;
    // Tạo một nhân viên tạm để chứa id nhằm tìm kiếm trong tập hợp (Vì đã định nghĩa toán tử == so sánh hai NhanVien theo id)
    NhanVien nv(id);

    int index = set.findEle(nv);

    if(index == -1) 
        cout << "-> Khong co nhan vien co ID " << id << "!" << endl;
    else 
        set[index].LayThongTinCaNhan();
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// TAI KHOAN NHAN VIEN

TaiKhoanNhanVien::TaiKhoanNhanVien() : TaiKhoan("","") {}
TaiKhoanNhanVien::TaiKhoanNhanVien(string ten, string mk) : TaiKhoan(ten,mk), nhanVien() {}

TaiKhoanNhanVien::TaiKhoanNhanVien(const TaiKhoanNhanVien& tk) : TaiKhoan(tk), nhanVien(tk.nhanVien) {}

TaiKhoanNhanVien& TaiKhoanNhanVien::operator=(const TaiKhoanNhanVien& rhs){
    nhanVien = rhs.nhanVien;
    TenDangNhap = rhs.TenDangNhap;
    MatKhau = rhs.MatKhau;

    return (*this);
}

bool TaiKhoanNhanVien::operator==(const TaiKhoanNhanVien& rhs){
    return (TenDangNhap == rhs.TenDangNhap && MatKhau == rhs.MatKhau);
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH TAI KHOAN NHAN VIEN

DanhSachTaiKhoanNhanVien::~DanhSachTaiKhoanNhanVien() {}

void DanhSachTaiKhoanNhanVien::caiDatDanhSach(){
    ifstream fin;
    fin.open("NHANVIEN.txt", ios::in);
    int count = 1;
    string line;
    while(getline(fin,line)){
        if(count != 1){
            TaiKhoanNhanVien tk;

            tk.nhanVien.idNhanVien = line; getline(fin,line);
            tk.nhanVien.HoTen = line; getline(fin,line);
            tk.nhanVien.Tuoi = line; getline(fin,line);
            tk.nhanVien.DiaChi = line; getline(fin, line);
            tk.nhanVien.SoDienThoai = line; getline(fin,line);

            tk.TenDangNhap = line; getline(fin, line);
            tk.MatKhau = line;
            
            set.insert(tk);
            count += 6;
        } 
        count++;
    }   
}

bool DanhSachTaiKhoanNhanVien::kiemTraTaiKhoan(TaiKhoanNhanVien& nv){
    int index = set.findEle(nv);
    if(index == -1)
        return false;
    else
        return true;
}  

void DanhSachTaiKhoanNhanVien::inDanhSach(){
    size_t n = set.getSize();
    for(size_t i = 0; i != n; i++){
        cout << set[i].TenDangNhap << " " << set[i].MatKhau;
        set[i].nhanVien.LayThongTinCaNhan();
        cout << endl;
    }
}

TaiKhoanNhanVien& DanhSachTaiKhoanNhanVien::suDungTaiKhoan(string ten, string mk){
    TaiKhoanNhanVien tk(ten,mk);
    int index = set.findEle(tk);
    return set[index];
}

#endif