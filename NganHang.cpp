#include <iostream>
#include <string.h>
#include <fstream>
#include "NganHang.h"

using namespace std;

// Constructor of NganHang class

NganHang::NganHang() : idNganHang(""), TenNganHang(""), DiaChiNganHang(""){

}

NganHang::NganHang(string id,string t, string dc) : idNganHang(id), TenNganHang(t), DiaChiNganHang(dc){

}

NganHang::NganHang(const NganHang& nh) : idNganHang(nh.idNganHang), TenNganHang(nh.TenNganHang), DiaChiNganHang(nh.DiaChiNganHang){

}

NganHang& NganHang::operator =(const NganHang& nh){
    if (this != &nh)
    {
        idNganHang = nh.idNganHang;
        TenNganHang = nh.TenNganHang;
        DiaChiNganHang = nh.DiaChiNganHang;
    }
    return *this;
}

// Relational operator overloading of NganHang class
bool NganHang::operator ==(const NganHang& nh) const{
    return TenNganHang.compare(nh.TenNganHang) && DiaChiNganHang.compare(nh.DiaChiNganHang);
}

bool NganHang::operator !=(const NganHang& nh) const{
    return idNganHang.compare(nh.idNganHang) != 0;
}
bool NganHang::operator >(const NganHang& nh){
    return idNganHang.compare(nh.idNganHang) > 0;
}

bool NganHang::operator <(const NganHang& nh) const{
    return idNganHang.compare(nh.idNganHang) < 0; 
}

// DanhSachNganHang member function 
void DanhSachNganHang::ThemNganHang(){
    ifstream fin;
    fin.open("NGANHANG.txt",ios::in);
    while(!fin.eof()){
        NganHang temp;
        getline(fin,temp.idNganHang);
        getline(fin,temp.TenNganHang);
        getline(fin,temp.DiaChiNganHang);
        ls.insert(temp);
    }
    fin.close();
}

void DanhSachNganHang::LayThongTinNganHang(string id,string t, string dc){
    NganHang nh(id,t,dc);
    ls.getInfo(nh);
}

void DanhSachNganHang::InNganHang(){
    ls.printList();
}