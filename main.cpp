#include <iostream>
#include "NhanVien.cpp"


using namespace std;

int main(){
    DanhSachTaiKhoanNhanVien dsTaiKhoan;
    dsTaiKhoan.caiDatDanhSach();
    dsTaiKhoan.inDanhSach();
    
    while(true){
        cout << "Bạn là " << endl;
        cout << "1. Nhân viên" << endl;
        cout << "2. Khách hàng" << endl;
        string choice;
        getline(cin,choice);
        if(choice == "1"){
            string tenDangNhap, matKhau;
            cout << "Xin mời đăng nhập : " << endl;
            cout << "Tài khoản : " << endl; getline(cin,tenDangNhap);
            cout << "Mật khẩu : " << endl; getline(cin, matKhau);
            tenDangNhap = "NV" + tenDangNhap;
            TaiKhoanNhanVien tk(tenDangNhap,matKhau);
            if(dsTaiKhoan.kiemTraTaiKhoan(tk))
                cout << "OK";
            else 
                cout << "Not OK";
        }
    }
    

   return 0;
}