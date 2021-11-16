#include <iostream>
#include "Sukien.h"

using namespace std;

bool SuKien::suKienThemTaiKhoan(DanhSachNhanVien& ls, DanhSachTaiKhoan &dsTaiKhoan){
    string choice;
    cout << "Loại tài khoản muốn thêm";
    getline(cin,choice);

    string tenDangNhap, matKhau;
    cout << "TÀI KHOẢN : " << endl;
    getline(cin, tenDangNhap);
    cout << "Mật khẩu : " << endl;
    getline(cin, matKhau);

    if(choice == "NV"){
        //Nếu lựa chọn là thêm tài khoản cho nhân viên 
        TaiKhoanNhanVien temp(tenDangNhap,matKhau);

        //Cài đặt thông tin cho nhân viên sau đó ghi dữ liệu vào file
        temp.nv.CaiDatThongTin();

        //Thêm tài khoản vừa tạo vào danh sách tài khoản
        dsTaiKhoan.themTaiKhoan(&temp);

        //Thêm nhân viên mới vào danh sách nhân viên
        ls.themNhanVien(temp.nv);

        //Ghi tài khoản nhân viên vào file
        temp.datTaiKhoan();

        // -> Ta được một tài khoản chứa thông tin nhân viên.
    }
    return true;
}