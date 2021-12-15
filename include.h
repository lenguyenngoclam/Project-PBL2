#ifndef INCLUDE_H
#define INCLUDE_H

#include <windows.h>
#include <conio.h>

#include "ThongTinCaNhan.cpp"
#include "TaiKhoan.h"
#include "LinkedListTemplate.cpp"

int nhanVien_count_line = 0;
int khachHang_count_line = 0;
int vi_count_line = 0;

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

bool timKiemTrongFile(string tenFile, string ten){
    const char* c = tenFile.c_str();
    ifstream fin;
    fin.open(c, ios::in);

    string line;
    while(getline(fin, line)){
        if(line == ten){
            fin.close(); 
            return true;
        }
    }
    fin.close();
    return false;
}

void xoaTrongFile(string tenFile, string ten){
    const char* c = tenFile.c_str();
    ifstream fin;
    fin.open(c, ios::in);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    string line;
    getline(fin,line);
    int count_line = stoi(line), count = 1;

    if(count_line == 0)
        return;

    count_line--;

    while(getline(fin,line)){
        if(count == 1) {
            if(count_line == 1)
                fout << to_string(count_line);
            else 
                fout << to_string(count_line) << endl;
            count++;
        } else {
            if(line != ten){
                if(count == count_line)
                    fout << line;
                else 
                    fout << line << endl;
                count++;
            }
        } 
    }
    fin.close();
    fout.close();

    remove(c);
    rename("temp.txt",c);
}

void themVaoFile(string tenFile, string ten){
    const char* c = tenFile.c_str();
    ofstream fout;
    fout.open("temp.txt", ios::app);
    ifstream fin;
    fin.open(c, ios::in);

    string line;
    getline(fin,line);
    int count_line = stoi(line), count = 1; 

    count_line++;
    fout << to_string(count_line) << endl;

    while(getline(fin,line)){
        fout << line << endl;
        count++;
    }

    fout << ten;

    fin.close();
    fout.close();

    remove(c);
    rename("temp.txt",c); 
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

// ----------------------------------------------------------------------------------------------------------------------------------------------
// HAM CHUC NANG

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------

void goodbye(string &str,int t)
{
    string s = str;
    cout << "\t\t";
    for (int i=0;i<s.size();i++)
    {
        cout << s[i];
        Sleep(t);
    }
}

#endif