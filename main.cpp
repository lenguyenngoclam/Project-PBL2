#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <conio.h>

#include "NhanVien.cpp"
#include "KhachHang.cpp"

using namespace std;

void giaoDienDangNhap(string &tk, string &mk){
    char s[50];
    cout << "\t\t-------- Xin moi dang nhap -------" << endl;
    cout << "\t\tTai khoan : "; getline(cin,tk); fflush(stdin);
    cout << "\t\tMat khau : "; getpassword(s,50); mk = s; fflush(stdin);
}

void giaoDienNhapID(string& id){
    cout << "\t\t- Xin moi nhap ID : ";
    getline(cin, id); fflush(stdin);
}

int main(){
    DanhSachTaiKhoanNhanVien dsTaiKhoan;
    DanhSachKhachHang dsKhachHang;
    DanhSachNhanVien dsNhanVien;
    DanhSachLichSuGiaoDich dsLichSu;
    dsLichSu.caiDatDanhSach();
    dsNhanVien.CaiDatDanhSach();
    dsKhachHang.CaiDatDanhSach();
    dsTaiKhoan.caiDatDanhSach();

    dsKhachHang.caiDatLichSuGiaoDich(dsLichSu);

    string hello = "------------ NGAN HANG VIETCOMBANK XIN CHAO QUY KHACH -------------";
    goodbye(hello,40); cout << endl;


    while(true) {

        cout << "\t\t+-----------+--------------------+" << endl;
        cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(15) << "Chuc nang" << setw(6) << "|" << endl;
        cout << "\t\t+-----------|--------------------+" << endl;
        cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(15) << "Nhan vien" << setw(6) << "|" << endl;
        cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(16) << "Khach hang" << setw(5) << "|" << endl;
        cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(10) << "Exit" << setw(11) << "|" << endl;
        cout << "\t\t+-----------+--------------------+" << endl;
        fflush(stdin); cout << "\t\t-> Lua chon cua ban: ";

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
                cout << "\t\tTai khoan hoac mat khau bi sai. Vui long dang nhap lai....." << endl;
                giaoDienDangNhap(tenDangNhap,matKhau);
                tenDangNhap = "NV" + tenDangNhap;
                tk = TaiKhoanNhanVien (tenDangNhap,matKhau);    
            }

            tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
            cout << "\t\t------------ Xin chao ------------" << endl;
            cout << "\t\t"; tk.layNhanVien().LayThongTinCaNhan();

            string tempString = "n";
            while(tempString == "n") {
                cout << "\t\tLua chon cua nhan vien: " << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(21) << "Chuc nang" << setw(19) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(30) << "Xem danh sach khach hang" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(34) << "Tao tai khoan cho khach hang" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(30) << "Sua thong tin khach hang" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(34) << "Lay thong tin cua khach hang" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(15) << "Dang xuat" << setw(25) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                fflush(stdin); cout << "\t\t-> Lua chon cua ban: ";
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
                            cout << "\t\t->ID khach hang khong ton tai !. Moi quy khach nhap lai....." << endl;
                            giaoDienNhapID(tempID);
                            tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        }
                        cout << "\t\t------------------ Khach hang " << tempID << " ------------------" << endl;
                        (dsKhachHang.getListKhachHang())[tempIndex].LayThongTinCaNhan();
                        break;
                    case 5:
                        tempString = "c";
                        string gb = "Tam biet " + tk.layNhanVien().LayTen() + ".....";
                        goodbye(gb,100);
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
                cout << "\t\tLua chon cua khach hang: " << endl;
                cout << "\t\t+-----------+--------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(28) << "Chuc nang" << setw(29) << "|" << endl;
                cout << "\t\t+-----------+--------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(20) << "Su dung the ATM" << setw(37) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(49) << "Muon dang ki la thanh vien moi cua ngan hang" << setw(8) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(14) << "Dang xuat" << setw(43) << "|" << endl;
                cout << "\t\t+-----------+--------------------------------------------------------+" << endl;
                fflush(stdin); cout << "\t\t-> Lua chon cua ban: ";
                            
                getline(cin, choice);
                cout << "\t\t+--------------------------------------------------------------------+" << endl;
                if (choice == "1" || choice == "2") 
                    cout << "\t\t----------------- XIN CHAO QUY KHACH --------------" << endl << endl;

                switch(stoi(choice)) {
                    
                    case 1 :
                        giaoDienDangNhap(tenDangNhap, matKhau);
                        while(!dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            cout << "\t\tTai khoan hoac mat khau bi sai. Vui long dang nhap lai....." << endl;
                            giaoDienDangNhap(tenDangNhap,matKhau);
                        }

                        while(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            size_t viTriKhachHang = dsKhachHang.timKiemATM(tenDangNhap, matKhau);
                            TheATM &the = (dsKhachHang.getListKhachHang()[viTriKhachHang]).layThongTinThe();

                            cout << "\t\t-------- Moi quy khach thuc hien giao dich --------" << endl << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(22) << "Chuc nang" << setw(16) << "|" << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(17) << "Xem so du" << setw(21) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(16) << "Rut tien" << setw(22) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(16) << "Nap tien" << setw(22) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(19) << "Chuyen tien" << setw(19) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(28) << "In lich su giao dich" << setw(10) << "|" << endl;
                            cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(26) << "Ket thuc giao dich" << setw(12) << "|" << endl;
                            cout << "\t\t+-----------+-------------------------------------+" << endl;
                            fflush(stdin); cout << "\t\t-> Lua chon cua ban: ";
                            getline(cin, choice);

                            cout << "\t\t+-------------------------------------------------+" << endl;

                            double d;
                            switch(stoi(choice)){
                                case 1 :    
                                    cout << "\t\tSo du cua ban = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 2 :
                                    cout << "\t\tSo tien muon rut = "; cin >> d;
                                    if(the.laySoDu() < d)
                                        cout << "\t\tSo tien can rut khong hop le !" << endl;
                                    else {
                                        the.RutTien(d);
                                        cout << "\t\t-> So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    }
                                    break;
                                case 3 :
                                    cout << "\t\tSo tien muon nap = "; cin >> d;
                                    the.NapTien(d);
                                    cout << "\t\t-> So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 4 : 
                                    cout << "\t\tNhap so tai khoan nguoi nhan : ";
                                    getline(cin, maTaiKhoan);
                                    tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                    if(tempIndex == -1)
                                        cout << "\t\tKhong tim thay ma tai khoan !" << endl;
                                    else {
                                        cout << "\t\t--------- Thong tin nguoi nhan ---------" << endl;
                                        (dsKhachHang.getListKhachHang())[tempIndex].LayThongTinCaNhan();
                                        TheATM& nguoiNhan = dsKhachHang.getListKhachHang()[tempIndex].layThongTinThe();
                                        cout << "\t\tNhap so tien can chuyen : ";
                                        cin >> soTien;

                                        if(soTien > the.laySoDu())
                                            cout << "\t\tSo du tai khoan khong du !" << endl;
                                        else {
                                            the.chuyenTien(nguoiNhan, soTien);
                                            cout << "\t\t-> So du hien tai = " << to_string(the.laySoDu()) << endl;
                                        }
                                    }
                                    break;
                                case 5 :    
                                    the.inLichSuGiaoDich();
                                    break;
                                case 6 : 
                                    string gb = "Giao dich da ket thuc. Xin chao quy khach.....";
                                    goodbye(gb,100);
                                    cout << endl;
                                    break;
                            }
                            if (choice == "6") break;
                        }
                    
                    case 2 :
                    {
                        srand(time(0));
                        size_t index = rand() % dsKhachHang.getListKhachHang().getCurr();

                        NhanVien& nv = dsNhanVien.getListNhanVien()[index];

                        cout << nv << endl;

                        cout << "\t\tVui long nhap cac thong tin duoi day !" << endl;
                        dsKhachHang.taoTaiKhoanKhachHang(); 
                        cout << "\t\t-> Da tao tai khoan thanh cong!" << endl;
                    }
                        break;

                    case 3 :
                        tempString = "c";
                        string gb = "Tam biet quy khach.....";
                        goodbye(gb,100);
                        cout << endl << endl;
                        break;
                }

            }

        } else if (first_choice == "exit") {
            string gb = "XIN CHAO TAM BIET VA HEN GAP LAI QUY KHACH.....";
            goodbye(gb,50);   
            break;
        }
        else {
            string s = "Option khong hop le. Moi ban chon lai.....";
            goodbye(s,25); cout << endl;
        }  
        
    }
    return 0;
}
