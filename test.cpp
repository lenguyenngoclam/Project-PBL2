#include <iostream>

using namespace std;

#include "KhachHang.cpp"

int main(){

    KhachHang kh1("01","Ngoc lam","48C","0962814899","2200");
    KhachHang kh2("02","Ngoc lam","48C","0962814899","2200");
    LinkedList<KhachHang> ls;
    ls.insert(kh1);
    ls.insert(kh2);
    cout << ls[0];
    return 0;
}