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
            cout << "Tài khoản : "; getline(cin,tenDangNhap);
            cout << "\nMật khẩu : " << endl; getline(cin, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);
            if(dsTaiKhoan.kiemTraTaiKhoan(tk)){
                TaiKhoanNhanVien tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
                tk.layNhanVien().LayThongTinCaNhan();
                break;
            }
            else 
                cout << "Not OK";
        }
    }

    
   return 0;
}