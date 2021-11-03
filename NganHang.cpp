#include <iostream>
#include <string.h>
#include "NganHang.h"

using namespace std;

//Constructor of NganHang class
int NganHang::s_id = 1;

void NganHang::CaiDatID(){
    NganHang::s_id++;
}

NganHang::NganHang() : TenNganHang(""), DiaChiNganHang(""){
    idNganHang = "NH" + to_string(NganHang::s_id);
    CaiDatID();
}

NganHang::NganHang(string t, string dc) : idNganHang("NH" + to_string(s_id)), TenNganHang(t), DiaChiNganHang(dc){
    CaiDatID();
}

NganHang::NganHang(const NganHang& nh) : idNganHang("NH" + to_string(s_id)), TenNganHang(nh.TenNganHang), DiaChiNganHang(nh.DiaChiNganHang){
    CaiDatID();
}

NganHang& NganHang::operator=(const NganHang& nh){
    idNganHang = "NH" + to_string(s_id);
    TenNganHang = nh.TenNganHang;
    DiaChiNganHang = nh.DiaChiNganHang;
    CaiDatID();
    return (*this);
}

//Relational operator overloading of NganHang class
bool NganHang::operator ==(const NganHang& nh) const{
    return (TenNganHang == nh.TenNganHang) && (DiaChiNganHang == nh.DiaChiNganHang);
}

bool NganHang::operator !=(const NganHang& nh) const{
    return (idNganHang != nh.idNganHang) && (TenNganHang != nh.TenNganHang) && (DiaChiNganHang != nh.DiaChiNganHang);
}

bool NganHang::operator >(const NganHang& nh) const{
    int t1 = stoi(idNganHang.substr(idNganHang.size() - 3,3)), 
        t2 = stoi((nh.idNganHang).substr(nh.idNganHang.size() - 3, 3));
    return (t1 > t2);
}

bool NganHang::operator <(const NganHang& nh) const{
    int t1 = stoi(idNganHang.substr(idNganHang.size() - 3,3)), 
        t2 = stoi((nh.idNganHang).substr(nh.idNganHang.size() - 3, 3));
    return (t1 < t2);
}

//DanhSachNganHang member function 
void DanhSachNganHang::ThemTaiKhoan(){

}

void DanhSachNganHang::XoaTaiKhoan(){

}

void DanhSachNganHang::ThemNganHang(){
    NganHang nh1("BIDV","Da Nang");
    ls.insert(nh1);
}

void DanhSachNganHang::LayThongTinNganHang(string t, string dc){
    NganHang nh(t,dc);
    ls.getInfo(nh);
}

void DanhSachNganHang::InNganHang(){
    ls.printList();
}