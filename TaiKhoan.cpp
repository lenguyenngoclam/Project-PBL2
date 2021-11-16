#include <iostream>
#include "TaiKhoan.h"

using namespace std;

ostream& TaiKhoan::getInfo(ostream& os){
    os << "Username : " << tenDangNhap << endl;
    os << "Password : " << matKhau << endl;
    return os;
}

TaiKhoan::TaiKhoan(const TaiKhoan& tk) : tenDangNhap(tk.tenDangNhap), matKhau(tk.matKhau){}

TaiKhoan& TaiKhoan::operator=(const TaiKhoan& rhs){
    tenDangNhap = rhs.tenDangNhap;
    matKhau = rhs.matKhau;
    return (*this);
}

void DanhSachTaiKhoan::themTaiKhoan(TaiKhoan *tk){
    node* new_node = new node();
    new_node -> data = tk;
    new_node -> next = (head);
    head = new_node;
}

void DanhSachTaiKhoan::inDanhSach(){
    node* current = head;
    while(current != NULL){
        //current->data->getInfo(cout);
        current = current -> next;
    }
}
