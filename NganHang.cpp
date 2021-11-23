#include <iostream>
#include <string.h>
#include <fstream>
#include "NganHang.h"

using namespace std;

// --------------------------------------------------------------------------------------------------------------------------------------------
// NGANHANG

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

void NganHang::LayThongTinNganHang()
{
    cout << "- ID ngân hàng: " << idNganHang << endl;
    cout << "- Tên ngân hàng: " << TenNganHang << endl;
    cout << "- Địa chỉ ngân hàng: " << DiaChiNganHang;
    cout << "---------------------------------------------------------------------" << endl;
}

// --------------------------------------------------------------------------------------------------------------------------------------------
// DANHSACHNGANHANG

void DanhSachNganHang::ThemNganHang(){
    ifstream fin;
    fin.open("NGANHANG.txt",ios::in);
    while(!fin.eof()){
        NganHang temp;
        getline(fin,temp.idNganHang);
        getline(fin,temp.TenNganHang);
        getline(fin,temp.DiaChiNganHang);
        set.insert(temp);
    }
    fin.close();
}

void DanhSachNganHang::LayThongTinNganHang(string id,string t, string dc){
    NganHang nh(id,t,dc);
    int index = set.findEle(nh);
    set[index].LayThongTinNganHang();
}

void DanhSachNganHang::InNganHang(){
    size_t n = set.getSize();
    for(size_t i = 0; i != n; i++){
        set[i].LayThongTinNganHang();
        cout << endl;
    }
}