#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <conio.h>

#include "NhanVien.cpp"
#include "includeKhachHang.h"
#include "ViDienTu.cpp"

using namespace std;

void giaoDienDangNhap(string &tk, string &mk){
    char s[50];
    cout << "\t\t-------- Xin mời đăng nhâp -------" << endl;
    cout << "\t\tTài khoản : "; getline(cin,tk); fflush(stdin);
    cout << "\t\tMật khẩu : "; getpassword(s,50); mk = s; fflush(stdin);
}

void giaoDienNhapID(string& id){
    cout << "\t\t- Xin mời nhập ID : ";
    getline(cin, id); fflush(stdin);
}

int main(){
    DanhSachTaiKhoanNhanVien dsTaiKhoan;
    DanhSachKhachHang dsKhachHang;
    DanhSachNhanVien dsNhanVien;
    DanhSachLichSuGiaoDich dsLichSu;
    DanhSachViDienTu dsVi;
    dsLichSu.caiDatDanhSach();
    dsNhanVien.CaiDatDanhSach();
    dsKhachHang.CaiDatDanhSach();
    dsTaiKhoan.caiDatDanhSach();
    dsVi.caiDatDanhSach();

    dsKhachHang.caiDatLichSuGiaoDich(dsLichSu);

    string hello = "----------------- NGÂN HÀNG VIETCOMBANK XIN KÍNH CHÀO QUÝ KHÁCH ------------------";
    goodbye(hello,30); cout << endl;


    while(true) {
        cout << "\t\tBạn là: " << endl;
        cout << "\t\t+-----------+--------------------+" << endl;
        cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(18) << "Chức năng" << setw(6) << "|" << endl;
        cout << "\t\t+-----------|--------------------+" << endl;
        cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(17) << "Nhân viên" << setw(6) << "|" << endl;
        cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(18) << "Khách hàng" << setw(5) << "|" << endl;
        cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(10) << "Exit" << setw(11) << "|" << endl;
        cout << "\t\t+-----------+--------------------+" << endl;
        fflush(stdin); cout << "\t\t-> Option của bạn: ";

        string first_choice,choice;
        getline(cin,choice);
        cout << "\t\t+-----------+--------------------+" << endl << endl;

        
        // Tên đăng nhâp, mật khẩu, mã tài khoản cho ATM
        string tenDangNhap, matKhau, maTaiKhoan;

        if (choice == "1") first_choice = "nv";
        else if (choice == "2") first_choice = "kh";
        else if (choice == "3") first_choice = "exit";
        else first_choice = choice;

        if(first_choice == "nv") {

            giaoDienDangNhap(tenDangNhap, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);

            while(!dsTaiKhoan.kiemTraTaiKhoan(tk)){
                cout << "\t\tTài khoản hoặc mật khẩu bị sai. Vui lòng đăng nhập lại....." << endl;
                giaoDienDangNhap(tenDangNhap,matKhau);
                tenDangNhap = "NV" + tenDangNhap;
                tk = TaiKhoanNhanVien (tenDangNhap,matKhau);    
            }

            tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
            cout << "-------------- Xin chao --------------" << endl;
            tk.layNhanVien().InThongTin();

            string tempString = "n";
            while(tempString == "n") {
                cout << "\t\t# Các option của nhân viên: " << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(25) << "Chức năng" << setw(18) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(33) << "Xem danh sách khách hàng" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(41) << "Tạo tài khoản cho khách hàng" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(35) << "Sửa thông tin khách hàng" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(41) << "Lấy thông tin của khách hàng" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(37) << "Xóa thẻ ATM cho khách hàng" << setw(8) << "|" << endl;
                cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(19) << "Đăng xuất" << setw(25) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                fflush(stdin); cout << "\t\t-> Option của bạn: ";
                getline(cin, choice);

                cout << "\t\t+---------------------------------------------------+" << endl;

                string tempID;
                size_t tempIndex;

                switch(stoi(choice)){
                    case 1: 
                        dsKhachHang.InDanhSach();
                        break;
                    case 2:
                        dsKhachHang.taoTaiKhoanKhachHang();
                        break;
                    case 3: 
                        giaoDienNhapID(tempID);
                        dsKhachHang.suaThongTinKhachHang(tempID);
                        break;
                    case 4:
                        giaoDienNhapID(tempID);
                        tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        while(tempIndex == -1){
                            cout << "\t\t->ID khách hàng không tồn tại!. Mời quý khách nhập lại....." << endl;
                            giaoDienNhapID(tempID);
                            tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        }
                        (dsKhachHang.getListKhachHang())[tempIndex].InThongTin();
                        break;
                    case 5:
                        break;
                    case 6:
                        tempString = "c";
                        string gb = "Tạm biệt " + tk.layNhanVien().LayTen() + ".....";
                        goodbye(gb,50);
                        cout << endl << endl;
                        //system("cls"); // clear màn hình
                        break;
                }

            }
        } 
        else if(first_choice == "kh") {

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp, tempString = "n";

            while (tempString == "n") {
                cout << "\t\t# Các option của khách hàng: " << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(34) << "Chức năng" << setw(30) << "|" << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(30) << "Sử dụng thẻ ATM" << setw(37) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(67) << "Muốn đăng kí là thành viên mới của ngân hàng" << setw(8) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(22) << "Đăng xuất" << setw(43) << "|" << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                fflush(stdin); cout << "\t\t-> Option của bạn: ";
                            
                getline(cin, choice);
                cout << "\t\t+------------------------------------------------------------------------+" << endl;
                if (choice == "1" || choice == "2") 
                    cout << "\t\t----------------- XIN CHÀO QUÝ KHÁCH --------------" << endl << endl;

                switch(stoi(choice)) {
                    
                    case 1 :
                        giaoDienDangNhap(tenDangNhap, matKhau);
                        while(!dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            cout << "\t\tTài khoản hoặc mật khẩu bị sai. Vui lòng đăng nhập lại....." << endl;
                            giaoDienDangNhap(tenDangNhap,matKhau);
                        }

                        while(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            size_t viTriKhachHang = dsKhachHang.timKiemATM(tenDangNhap, matKhau);
                            TheATM &the = (dsKhachHang.getListKhachHang()[viTriKhachHang]).layThongTinThe();

                            cout << "\t\t-------- Mời quý khách thực hiện giao dịch --------" << endl << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(25) << "Chức năng" << setw(16) << "|" << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(21) << "Xem số dư" << setw(20) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(20) << "Rút tiền" << setw(21) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(21) << "Nạp tiền" << setw(21) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(24) << "Chuyển tiền" << setw(18) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(35) << "In lịch sử giao dịch" << setw(9) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(32) << "Kết thúc giao dịch" << setw(11) << "|" << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            fflush(stdin); cout << "\t\t-> Option của bạn: ";
                            getline(cin, choice);

                            cout << "\t\t+-------------------------------------------------+" << endl;

                            double d;
                            switch(stoi(choice)){
                                case 1 :    
                                    cout << "\t\tSố dư của bạn = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 2 :
                                    cout << "\t\tSố tiền muốn rút = "; cin >> d;
                                    if(the.laySoDu() < d)
                                        cout << "\t\tSố tiền cần rút không hợp lệ !" << endl;
                                    else {
                                        the.RutTien(d, "Rút tiền từ tài khoản với số tiền : " + to_string(d));
                                        cout << "So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    }
                                    break;
                                case 3 :
                                    cout << "So tien muon nap = "; cin >> d;
                                    the.NapTien(d, "Nạp tiền vào tài khoản với số tiền : " + to_string(d));
                                    cout << "So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 4 : 
                                    cout << "\t\tNhập số tài khoản người nhận : ";
                                    getline(cin, maTaiKhoan);
                                    tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                    if(tempIndex == -1)
                                        cout << "\t\tKhông tìm thấy số tài khoản !" << endl;
                                    else {
                                        cout << "Thong tin nguoi nhan : " << endl;
                                        (dsKhachHang.getListKhachHang())[tempIndex].InThongTin();
                                        TheATM& nguoiNhan = dsKhachHang.getListKhachHang()[tempIndex].layThongTinThe();
                                        cout << "\t\tNhập số tiền cần chuyển : ";
                                        cin >> soTien;

                                        if(soTien > the.laySoDu())
                                            cout << "\t\tSố dư tài khoản không đủ !" << endl;
                                        else {
                                            the.chuyenTien(nguoiNhan, soTien);
                                            cout << "\t\t-> Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                        }
                                    }
                                    break;
                                case 5 :    
                                    the.inLichSuGiaoDich();
                                    break;
                                case 6 : 
                                    string gb = "Giao dịch đã kết thúc. Xin kính chào quý khách.....";
                                    goodbye(gb,45);
                                    cout << endl << endl;
                                    break;
                            }
                            if (choice == "6") break;
                        }
                        break;

                    case 2 :
                    {
                        srand(time(0));
                        size_t index = rand() % dsKhachHang.getListKhachHang().getCurr();

                        NhanVien& nv = dsNhanVien.getListNhanVien()[index];

                        cout << nv << endl;

                        cout << "\t\tVui lòng nhập các thông tin dưới đây !" << endl;
                        dsKhachHang.taoTaiKhoanKhachHang(); 
                        cout << "\t\t-> Đã tạo tài khoản thành công!" << endl;
                    }
                        break;

                    case 3 :
                        tempString = "c";
                        string gb = "Tạm biệt quý khách.....";
                        goodbye(gb,50);
                        cout << endl << endl;
                        break;
                }

            }

        } else if (first_choice == "exit") {
            string gb = "XIN CHÀO TẠM BIỆT VÀ HẸN GẶP LẠI QUÝ KHÁCH.....";
            goodbye(gb,50);   
            break;
        }
        else {
            string s = "Option không hợp lệ. Mời bạn chọn lại.....";
            goodbye(s,30); cout << endl;
        }  
        
    }
    return 0;
}
