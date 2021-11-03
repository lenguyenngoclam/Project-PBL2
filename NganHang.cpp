#include <iostream>
#include <string.h>
#include "NganHang.h"

using namespace std;

//Constructor of NganHang class
int NganHang::s_id = 1;

void NganHang::caiDatID(){
    NganHang::s_id++;
}
NganHang::NganHang() : tenNganHang(""), diaChiNganHang(""){
    idNganHang = "NH" + to_string(NganHang::s_id);
    caiDatID();
}
NganHang::NganHang(string t, string dc) : idNganHang("NH" + to_string(s_id)), tenNganHang(t), diaChiNganHang(dc){
    caiDatID();
}
NganHang::NganHang(const NganHang& nh) : idNganHang("NH" + to_string(s_id)), tenNganHang(nh.tenNganHang), diaChiNganHang(nh.diaChiNganHang){
    caiDatID();
}
NganHang& NganHang::operator=(const NganHang& nh){
    idNganHang = s_id;
    tenNganHang = nh.tenNganHang;
    diaChiNganHang = nh.diaChiNganHang;
    caiDatID();
    return (*this);
}

//Relational operator overloading of NganHang class
bool NganHang::operator==(const NganHang& nh) const{
    return (tenNganHang == nh.tenNganHang) && (diaChiNganHang == nh.diaChiNganHang);
}
bool NganHang::operator!=(const NganHang& nh) const{
    return (idNganHang != nh.idNganHang) && (tenNganHang != nh.tenNganHang) && (diaChiNganHang != nh.diaChiNganHang);
}
bool NganHang::operator>(const NganHang& nh) const{
    int t1 = stoi(idNganHang.substr(idNganHang.size() - 3,3)), 
        t2 = stoi((nh.idNganHang).substr(nh.idNganHang.size() - 3, 3));
    return (t1 > t2);
}
bool NganHang::operator<(const NganHang& nh) const{
    int t1 = stoi(idNganHang.substr(idNganHang.size() - 3,3)), 
        t2 = stoi((nh.idNganHang).substr(nh.idNganHang.size() - 3, 3));
    return (t1 < t2);
}

//DanhSachNganHang member function 
void DanhSachNganHang::themTaiKhoan(){

}
void DanhSachNganHang::xoaTaiKhoan(){

}
void DanhSachNganHang::themNganHang(){
    NganHang nh1("BIDV","Da Nang");
    ls.insert(nh1);
}
void DanhSachNganHang::layThongTinNganHang(string t, string dc){
    NganHang nh(t,dc);
    ls.getInfo(nh);
}
void DanhSachNganHang::inNganHang(){
    ls.printList();
}