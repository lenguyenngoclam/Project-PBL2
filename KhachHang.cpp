#include <iostream>
#include <string>
#include <fstream>

#include "ThongTinCaNhan.h"
#include "TaiKhoan.h"
#include "KhachHang.h"

using namespace std;

string LaySoLuongKhachHang() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

int count_line = 0;
string number_KhachHang = LaySoLuongKhachHang();

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

string KhachHang::LaySoLuong()
{
    return number_KhachHang;
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
        if (count == 1) {
            number_KhachHang = line.substr(0,line.size()-1); // Cắt kí tự "\n" cuối line
            ++count; fout << line << endl;
        }
        else if (count == count_line) fout << line; 
        else { 
            ++count; 
            fout << line << endl; 
        }
        if (line == idKhachHang){
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
    string temp = "KH";
    int num = stoi(number_KhachHang);
    num++; 
    number_KhachHang = to_string(num);
    idKhachHang = temp + number_KhachHang;

    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file KHACHHANG.txt và đổi tên file temp thành KHACHHANG
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            fout << number_KhachHang << endl;
            count++;
        } else {
            fout << line << endl;
        }
    }

    fout << idKhachHang << endl;
    fout << HoTen << endl;
    fout << Tuoi << endl;
    fout << DiaChi << endl;
    fout << SoDienThoai;

    fin.close();
    fout.close();

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");  
}

bool KhachHang::operator ==(const KhachHang& rhs) const{
    return idKhachHang.compare(rhs.idKhachHang) == 0;
}

bool KhachHang::operator !=(const KhachHang& rhs) const{
    return idKhachHang.compare(rhs.idKhachHang) != 0;
}

bool KhachHang::operator <(const KhachHang& rhs) const{
    return idKhachHang.compare(rhs.idKhachHang) < 0;
}

bool KhachHang::operator >(const KhachHang& rhs) const{
    return idKhachHang.compare(rhs.idKhachHang) > 0;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DanhSachKhachHang 
void DanhSachKhachHang::CaiDatDanhSach(){
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    getline(fin, number_KhachHang);
    count_line += 1;
    while(!fin.eof()){
        KhachHang temp;
        getline(fin, temp.idKhachHang);
        getline(fin, temp.HoTen);
        getline(fin, temp.Tuoi);
        getline(fin, temp.DiaChi);
        getline(fin, temp.SoDienThoai);
        ls.insert(temp);
        count_line += 5;
    }
    fin.close();
}

ostream& operator <<(ostream& os, const KhachHang& kh){
    kh.LayThongTinCaNhan();
    return os;
}

void DanhSachKhachHang::InDanhSach(){
    cout << "---------------Danh sach khach hang---------------" << endl;
    ls.printList();
}

void DanhSachKhachHang::SuaDanhSach(const KhachHang &kh)
{
// Sua trong DSLK
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    getline(fin, number_KhachHang);
    while(!fin.eof()){
        KhachHang temp;
        getline(fin, temp.idKhachHang);
        getline(fin, temp.HoTen);
        getline(fin, temp.Tuoi);
        getline(fin, temp.DiaChi);
        getline(fin, temp.SoDienThoai);
        if (fin.eof()) {
            KhachHang temp1;
            temp1.idKhachHang = kh.idKhachHang;
            temp1.HoTen = kh.HoTen;
            temp1.Tuoi = kh.Tuoi;
            temp1.DiaChi = kh.DiaChi;
            temp1.SoDienThoai = kh.SoDienThoai;
            ls.insert(temp1);
            break;
        }
    }
    fin.close();
    
// Sua trong file KHACHHANG.txt
    ifstream fin2;
    fin2.open("KHACHHANG.txt", ios::in);

    ofstream fout;
    fout.open("temp.txt", ios::app);

    string line; int count = 1;
    while(getline(fin2, line)){
        if (count == 1) {
            number_KhachHang = line.substr(0,line.size()-1); // Cắt kí tự "\n" cuối line
            ++count; fout << line << endl;
        }
        else if (count == count_line) {
            fout << line << endl;
            fout << kh.idKhachHang << endl;
            fout << kh.HoTen << endl; 
            fout << kh.Tuoi << endl; 
            fout << kh.DiaChi << endl;
            fout << kh.SoDienThoai;   
            count_line += 5;     
            break;    
        }
        else { 
            ++count; 
            fout << line << endl; 
        }
    }

    fin2.close();
    fout.close();
    
    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");
}

Node<KhachHang>* DanhSachKhachHang::getHead()
{
    return ls.getHead();
}

void DanhSachKhachHang::ThemKhachHang(KhachHang& nv){
    ls.insert(nv);
}

void DanhSachKhachHang::TimKiemKhachHang(string id) // Tìm kiếm khách hàng theo idKhachHang
{
    cout << "-----------------Khach Hang " << id << "-------------------" << endl;
    Node<KhachHang> *current = getHead();
    int found;
     while(current != NULL){
        if(current -> getData().idKhachHang == id)
        {
            current -> getData().LayThongTinCaNhan();
            found = 1;
            break;
        }    
        current = current -> getNext();
        found = 0;
    }
    if (found == 0) cout << "-> Khong co khach hang nao co ID " << id << "!" << endl;
}