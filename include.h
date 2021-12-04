#ifndef INCLUDE_H
#define INCLUDE_H

#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.h"
#include "SetTemplate.cpp"
#include "LinkedListTemplate.cpp"

int nhanVien_count_line = 0;
int khachHang_count_line = 0;

string LaySoLuongKhachHang() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string LaySoLuongGiaoDich() {
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_KhachHang = LaySoLuongKhachHang();
int soLuong = stoi(number_KhachHang);
string number_lichsu = LaySoLuongGiaoDich();
int soLuongGiaoDich = stoi(number_lichsu);

void getpassword(char s[], int size) // Nhập mật khẩu dạng dấu *
{
    char ch = 0;
    memset(s,0,size);
    fflush(stdin);
    while (ch != 13) // ch khác Enter
    {
        fflush(stdin);
        ch = getch();
        if (ch <= 0) getch(); // Loại bỏ kí các tự điều khiển
        else if (ch > 31 && ch < 127) // Các kí tự ASCII in được
        {
            if (int(strlen(s)) < size - 1) // Nếu chuỗi chưa đầy
            {
                cout << '*';
                s[strlen(s)] = ch;
            }
        } else if (ch == 8) // Xóa một kí tự
        if (s[0]) // Nếu chuỗi khác rỗng
        {
            s[strlen(s)-1] = 0; // Xoá kí tự cuối cùng của chuỗi
            cout << ch << ' ' << ch; // Xoá một kí tự trước đó trên màn hình
        }
    }
    cout << endl;
    fflush(stdin);
}

#endif