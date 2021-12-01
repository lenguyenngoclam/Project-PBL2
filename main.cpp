#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>

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

    cout << "------------ NGAN HANG VIETCOMBANK XIN CHAO QUY KHACH -------------" << endl;
    while(true){

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
        else first_choice = "exit";

        if(first_choice == "nv"){

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
            while(tempString == "n"){

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
                
                string choose;
                getline(cin, choose);
                cout << "\t\t+---------------------------------------------------+" << endl;

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
                            cout << "\t\t->ID khach hang khong ton tai !. Moi quy khach nhap lai....." << endl;
                            giaoDienNhapID(tempID);
                            tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        }
                        
                        if (tempIndex != -1) 
                        {
                            cout << "\t\t------------------ Khach hang " << tempID << " -------------------" << endl;
                            (dsKhachHang.getSetKhachHang())[tempIndex].LayThongTinCaNhan();
                        }
                        break;
                    case 5:
                        tempString = "c";
                        break;
                }

            }
        } 
        else if(first_choice == "kh"){

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp, tempString = "n";

            while (tempString == "n") {

                cout << "Lua chon: " << endl;
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
                            TheATM &the = (dsKhachHang.getSetKhachHang()[viTriKhachHang]).layThongTinThe();

                            cout << "------ Moi quy khach thuc hien giao dich ------" << endl;
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
                                        cout << "So tien can rut khong hop le !" << endl;
                                    else {
                                        the.RutTien(d);
                                        cout << "-> So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    }
                                    break;
                                case 3 :
                                    cout << "So tien muon nap = "; cin >> d;
                                    the.NapTien(d);
                                    cout << "-> So du hien tai = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 4 : 
                                    cout << "Nhap so tai khoan nguoi nhan : ";
                                    getline(cin, maTaiKhoan);
                                    tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                    if(tempIndex == -1)
                                        cout << "Khong tim thay ma tai khoan !" << endl;
                                    else {
                                        cout << "-------- Thong tin nguoi nhan ---------" << endl;
                                        (dsKhachHang.getSetKhachHang())[tempIndex].LayThongTinCaNhan();
                                        TheATM& nguoiNhan = dsKhachHang.getSetKhachHang()[tempIndex].layThongTinThe();

                                        cout << "Nhap so tien can chuyen : ";
                                        cin >> soTien;

                                        if(soTien > the.laySoDu())
                                            cout << "So du tai khoan khong du !" << endl;
                                        else {
                                            the.chuyenTien(nguoiNhan, soTien);
                                            cout << "-> So du hien tai = " << to_string(the.laySoDu()) << endl;
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
                        size_t index = rand() % dsNhanVien.getSetNhanVien().getCurr();

                        NhanVien& nv = dsNhanVien.getSetNhanVien()[index];
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
            cout << "XIN CHAO TAM BIET VA HEN GAP LAI QUY KHACH.....";   
            break;
        }
        else {
            cout << "Moi ban nhap lai....." << endl;
        }   
    }
    return 0;
}

/*
void giaoDienDangNhap(string &tk, string &mk){
    cout << "Xin mời đăng nhập : " << endl;
    cout << "Tài khoản : "; getline(cin,tk);
    cout << "Mật khẩu : "; getline(cin, mk);
}

void giaoDienNhapID(string& id){
    cout << "Xin mời nhập ID : " << endl;
    getline(cin, id);
}

int main(){
    DanhSachTaiKhoanNhanVien dsTaiKhoan;
    DanhSachKhachHang dsKhachHang;
    DanhSachNhanVien dsNhanVien;
    DanhSachOnlineBanking dsOnlineBanking;

    dsOnlineBanking.caiDatDanhSach();
    dsNhanVien.CaiDatDanhSach();
    dsKhachHang.CaiDatDanhSach();
    dsTaiKhoan.caiDatDanhSach();

    
    while(true){

        cout << "Bạn là " << endl;
        cout << "1. Nhân viên" << endl;
        cout << "2. Khách hàng" << endl;
        string choice;
        cout << "-> Lựa chọn của bạn: ";
        getline(cin,choice);

        // Mã tài khoản ATM
        string tenDangNhap, matKhau, maTaiKhoan;

        choice = (choice == "1") ? "nv" : "kh";

        if(choice == "nv"){

            giaoDienDangNhap(tenDangNhap, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);

            while(!dsTaiKhoan.kiemTraTaiKhoan(tk)){
                cout << "Tài khoản mật khẩu bị sai. Vui lòng đăng nhập lại" << endl;
                giaoDienDangNhap(tenDangNhap,matKhau);
                tk = TaiKhoanNhanVien(tenDangNhap, matKhau);    
            }

            tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
            cout << "------ Xin chào -------" << endl;
            tk.layNhanVien().LayThongTinCaNhan();

            string tempString = "n";
            while(tempString == "n"){
                cout << "Bạn muốn : " << endl;
                cout << "1. Xem danh sách khách hàng" << endl;
                cout << "2. Tạo tài khoản cho khách hàng" << endl;
                cout << "3. Sửa thông tin khách hàng" << endl;
                cout << "4. Lấy thông tin của khách hàng" << endl;
                cout << "-> Lựa chọn của bạn: ";
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

                        dsKhachHang.TimKiemKhachHang(tempID);
                        break;
                }

                cout << "Đăng xuất ? (c/n) "; fflush(stdin);
                getline(cin, tempString);
            }
        } else if(choice == "kh"){

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp;

            cout << "1. Sử dụng thẻ ATM" << endl;
            cout << "2. Sử dụng online banking" << endl;
            cout << "3. Muốn đăng kí là thành viên của ngân hàng hoặc đăng kí online banking" << endl;

            getline(cin,choice);

            switch(stoi(choice)){
                case 1 :
                    giaoDienDangNhap(tenDangNhap, matKhau);
                    while(!dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                        cout << "Tài khoản mật khẩu bị sai. Vui lòng đăng nhập lại" << endl;
                        giaoDienDangNhap(tenDangNhap,matKhau);
                    }

                    while(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                        size_t viTriKhachHang = dsKhachHang.suDungATM(tenDangNhap, matKhau);
                        TheATM& the = dsKhachHang.getSetATM()[viTriKhachHang];

                        cout << "\t1. Xem số dư" << endl;
                        cout << "\t2. Rút tiền" << endl;
                        cout << "\t3. Nạp tiền" << endl;
                        getline(cin, choice);
                        double d;
                        switch(stoi(choice)){
                            case 1 :    
                                cout << "Số dư = " << to_string(the.laySoDu()) << endl;
                                break;
                            case 2 :
                                cout << "Số tiền muốn rút = "; cin >> d;
                                if(the.laySoDu() < d)
                                    cout << "Số tiền cần rút không hợp lệ" << endl;
                                else {
                                    the.RutTien(d);
                                    cout << "Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                }
                                break;
                            case 3 :
                                cout << "Số tiền muốn nạp = "; cin >> d;
                                the.NapTien(d);
                                cout << "Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                break;
                        }
                        cout << "Đăng xuất ? (c/n) "; fflush(stdin);
                        string tempString;
                        getline(cin, tempString);
                        if(tempString == "c")
                            break; 
                    }
                case 2 :

                    giaoDienDangNhap(tenDangNhap, matKhau);

                    if(dsOnlineBanking.kiemTraTaiKhoan(tenDangNhap, matKhau)){
                        cout << "\t1. Xem số dư" << endl;
                        cout << "\t2. Chuyển tiền" << endl;
                        getline(cin, choice);
                        string idKhachHang = dsOnlineBanking.layIDKhachHang(tenDangNhap,matKhau);

                        TheATM& the = dsKhachHang.layThongTinTheATM(idKhachHang);

                        switch(stoi(choice)){
                            case 1:   
                                cout << "Số dư = " << to_string(the.laySoDu()) << endl; 
                                break;
                            case 2: 
                                cout << "Nhập số tài khoản ATM người nhận : ";
                                getline(cin, maTaiKhoan);
                                tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                if(tempIndex == -1)
                                    cout << "Không tìm thấy mã tài khoản" << endl;
                                else {
                                    cout << "Thông tin người nhận : " << endl;
                                    (dsKhachHang.getSetKhachHang())[tempIndex].LayThongTinCaNhan();
                                    TheATM& nguoiNhan = dsKhachHang.getSetATM()[tempIndex];
                                    cout << "Nhập số tiền cần chuyển : ";
                                    cin >> soTien;
                                    if(soTien > the.laySoDu())
                                        cout << "Số dư tài khoản không đủ" << endl;
                                    else {
                                        the.chuyenTien(nguoiNhan, soTien);
                                        cout << "Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                    }
                                }
                                break;
                        }
                    }
                    else 
                        cout << "Not OK";
                    
                    break;
                case 3 :
                    srand(time(0));
                    size_t index = rand() % dsKhachHang.getSetKhachHang().getCurr();

                    NhanVien& nv = dsNhanVien.getSetNhanVien()[index];

                    cout << nv << endl;
                    cout << "1. Đăng kí online banking" << endl;
                    cout << "2. Đăng kí thành viên mới của ngân hàng" << endl;
                    getline(cin, choice);
                    switch(stoi(choice)){
                        case 1 :
                            giaoDienDangNhap(tenDangNhap, matKhau);
                            
                            if(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                                tempIndex = dsKhachHang.suDungATM(tenDangNhap, matKhau);
                                temp = (dsKhachHang.getSetKhachHang())[tempIndex].layIdKhachHang();
                                if(dsOnlineBanking.kiemTraOnlineBanking(temp) == false)
                                    dsOnlineBanking.themOnlineBanking(temp);
                                else 
                                    cout << "Khách hàng này đã có tài khoản online banking" << endl;
                            } else {
                                cout << "Đăng nhập sai" << endl;
                            }
                            break;
                        case 2 :
                            cout << "Vui lòng nhập các thông tin dưới đây !" << endl;
                            dsKhachHang.taoTaiKhoanKhachHang();
                            break;
                    }
                    

                    break;
            }
            break;
        } else {
            cout << "Error";
        }
    }

    system("pause");
    return 0;
}*/