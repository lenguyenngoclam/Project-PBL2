#include <iostream>
#include <string>
#include "NhanVien.cpp"
#include "includeKhachHang.h"
#include "ViDienTu.cpp"

using namespace std;

void giaoDienDangNhap(string &tk, string &mk){
    cout << "-------Xin moi dang nhap-------" << endl;
    cout << "Tai khoan : "; getline(cin,tk); fflush(stdin);
    cout << "Mat khau : "; getline(cin, mk); fflush(stdin);
}

void giaoDienNhapID(string& id){
    cout << "Xin moi nhap ID : " << endl;
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

    cout << "-------------- NGAN HANG VIETCOMBANK XIN CHAO QUY KHACH ---------------" << endl;
    while(true){

        cout << "Ban la: " << endl;
        cout << "1. Nhan vien" << endl;
        cout << "2. Khach hang" << endl;
        cout << "3. Exit" << endl;

        string first_choice,choice;
        fflush(stdin); cout << "-> Lua chon cua ban: ";
        getline(cin,choice);

        // Mã tài khoản ATM
        string tenDangNhap, matKhau, maTaiKhoan;

        if (choice == "1") first_choice = "nv";
        else if (choice == "2") first_choice = "kh";
        else first_choice = "exit";

        if(first_choice == "nv"){

            giaoDienDangNhap(tenDangNhap, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);

            while(!dsTaiKhoan.kiemTraTaiKhoan(tk)){
                cout << "Tai khoan hoac mat khau bi sai. Vui long dang nhap lai....." << endl;
                giaoDienDangNhap(tenDangNhap,matKhau);
                tk = TaiKhoanNhanVien(tenDangNhap, matKhau);    
            }

            tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
            cout << "-------------- Xin chao --------------" << endl;
            tk.layNhanVien().LayThongTinCaNhan();

            string tempString = "n";
            while(tempString == "n"){
                cout << "Ban muon : " << endl;
                cout << "1. Xem danh sach khach hang" << endl;
                cout << "2. Tao tai khoan cho khach hang" << endl;
                cout << "3. Sua thong tin khach hang" << endl;
                cout << "4. Lay thong tin cua khach hang" << endl;
                fflush(stdin); cout << "-> Lua chon cua ban: ";
                string choose;
                getline(cin, choose);

                string tempID;
                size_t tempIndex;

                switch(stoi(choose)){
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
                            cout << "ID khách hàng không tồn tại!";
                            giaoDienNhapID(tempID);
                            tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        }
                        (dsKhachHang.getListKhachHang())[tempIndex].LayThongTinCaNhan();
                        break;
                }
                cout << "Dang xuat ? (c/n) "; fflush(stdin);
                getline(cin, tempString);

            }
        } 
        else if(first_choice == "kh"){

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp, tempString = "n";

            while (tempString == "n") {

                cout << "1. Su dung the ATM" << endl;
                cout << "2. Muon dang ki la thanh vien cua ngan hang" << endl;
                fflush(stdin); cout << "-> Lua chon cua ban: ";
                getline(cin,choice);

                switch(stoi(choice)){
                    case 1 :
                        giaoDienDangNhap(tenDangNhap, matKhau);
                        while(!dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            cout << "Tai khoan mat khau bi sai. Vui long dang nhap lai....." << endl;
                            giaoDienDangNhap(tenDangNhap,matKhau);
                        }

                        while(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                            size_t viTriKhachHang = dsKhachHang.timKiemATM(tenDangNhap, matKhau);
                            TheATM &the = (dsKhachHang.getListKhachHang()[viTriKhachHang]).layThongTinThe();

                            cout << "----- Moi quy khach thuc hien giao dich -----" << endl;
                            cout << "\t1. Xem so du" << endl;
                            cout << "\t2. Rut tien" << endl;
                            cout << "\t3. Nap tien" << endl;
                            cout << "\t4. Chuyen tien" << endl;
                            cout << "\t5. In lich su giao dich" << endl;
                            cout << "\t6. Ket thuc giao dich" << endl;
                            fflush(stdin); cout << "-> Lua chon cua ban: ";
                            getline(cin, choice);

                            double d;
                            switch(stoi(choice)){
                                case 1 :    
                                    cout << "So du = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 2 :
                                    cout << "So tien muon rut = "; cin >> d;
                                    if(the.laySoDu() < d)
                                        cout << "So tien can rut khong hop le" << endl;
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
                                    cout << "Nhap so tai khoan nguoi nhan : ";
                                    getline(cin, maTaiKhoan);
                                    tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                    if(tempIndex == -1)
                                        cout << "Khong tim thay ma tai khoan" << endl;
                                    else {
                                        cout << "Thong tin nguoi nhan : " << endl;
                                        (dsKhachHang.getListKhachHang())[tempIndex].LayThongTinCaNhan();
                                        TheATM& nguoiNhan = dsKhachHang.getListKhachHang()[tempIndex].layThongTinThe();
                                        cout << "Nhap so tien can chuyen : ";
                                        cin >> soTien;
                                        if(soTien > the.laySoDu())
                                            cout << "So du tai khoan khong du" << endl;
                                        else {
                                            the.chuyenTien(nguoiNhan, soTien);
                                            cout << "So du hien tai = " << to_string(the.laySoDu()) << endl;
                                        }
                                    }
                                    break;
                                case 5 :    
                                    the.inLichSuGiaoDich();
                                    break;
                                case 6 : 
                                    cout << "Giao dich da ket thuc. Xin chao quy khach....." << endl;
                                    break;
                            }
                            if(choice == "6") break; 
                        }

                        break;
                    
                    case 2 :
                        srand(time(0));
                        size_t index = rand() % dsKhachHang.getListKhachHang().getCurr();

                        NhanVien& nv = dsNhanVien.getListNhanVien()[index];

                        cout << nv << endl;

                        cout << "Vui long nhap cac thong tin duoi day !" << endl;
                        dsKhachHang.taoTaiKhoanKhachHang(); 
                        
                        break;
                        
                }
                cout << "Dang xuat ? (c/n) "; fflush(stdin);
                getline(cin, tempString);
                if(tempString == "c")
                    break;
            }

        } else if (first_choice == "exit") {
            cout << "Xin chao tam biet quy khach va hen gap lai.....";   
            break;
        }
        else {
            cout << "Moi ban nhap lai....." << endl;
        }  
        
    }
    return 0;
}
