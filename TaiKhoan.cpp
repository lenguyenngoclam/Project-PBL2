#include <iostream>
#include "TaiKhoan.h"

using namespace std;

ostream& TaiKhoan::getInfo(ostream& os){
    os << "Username : " << TenDangNhap << endl;
    os << "Password : " << MatKhau << endl;
    return os;
}

TaiKhoan::TaiKhoan(const TaiKhoan& tk) : TenDangNhap(tk.TenDangNhap), MatKhau(tk.MatKhau){}

TaiKhoan& TaiKhoan::operator =(const TaiKhoan& rhs){
    TenDangNhap = rhs.TenDangNhap;
    MatKhau = rhs.MatKhau;
    return (*this);
}

void DanhSachTaiKhoan::ThemTaiKhoan(TaiKhoan *tk){
    node* new_node = new node();
    new_node -> data = tk;
    new_node -> next = (head);
    head = new_node;
}

void DanhSachTaiKhoan::InDanhSach(){
    node* current = head;
    while(current != NULL){
        //current->data->getInfo(cout);
        current = current -> next;
    }
}
