#include <iostream>
#include <string.h>
#include <fstream>
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
    return (idNganHang != nh.idNganHang);
}
bool NganHang::operator >(const NganHang& nh) const{
    return (idNganHang > nh.idNganHang);
}

bool NganHang::operator <(const NganHang& nh) const{
    return (idNganHang < nh.idNganHang); 
}

//DanhSachNganHang member function 
void DanhSachNganHang::ThemNganHang(){
    ifstream fin;
    fin.open("NGANHANG.txt",ios::in);
    while(!fin.eof()){
        NganHang temp;
        getline(fin,temp.TenNganHang);
        getline(fin, temp.DiaChiNganHang);
        ls.insert(temp);
    }
    fin.close();
}

void DanhSachNganHang::LayThongTinNganHang(string t, string dc){
    NganHang nh(t,dc);
    ls.getInfo(nh);
}

void DanhSachNganHang::InNganHang(){
    ls.printList();
}