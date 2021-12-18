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
    cout << "\t\t~~~~~~~~ Xin mời đăng nhâp ~~~~~~~~" << endl;
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

    cout << endl;
    string hello = "------------------- NGÂN HÀNG METABANK XIN KÍNH CHÀO QUÝ KHÁCH --------------------";
    goodbye(hello,30); cout << endl;


    while(true) {
        cout << "\t\t# Bạn là: " << endl;
        cout << "\t\t+-----------+---------------------+" << endl;
        cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(18) << "Chức năng" << setw(7) << "|" << endl;
        cout << "\t\t+-----------|---------------------+" << endl;
        cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(17) << "Nhân viên" << setw(7) << "|" << endl;
        cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(18) << "Khách hàng" << setw(6) << "|" << endl;
        cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(10) << "Exit" << setw(12) << "|" << endl;
        cout << "\t\t+-----------+---------------------+" << endl;
        cout << "\t\t-> Option của bạn: ";

        string first_choice,choice;
        fflush(stdin); getline(cin,choice);
        cout << "\t\t+-----------+---------------------+" << endl << endl;
        
        // Tên đăng nhâp, mật khẩu, mã tài khoản cho ATM
        string tenDangNhap, matKhau, maTaiKhoan;
        int option;

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
                tk = TaiKhoanNhanVien(tenDangNhap,matKhau);    
            }

            tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
            cout << "\t\t-------------- Xin chào --------------" << endl;
            tk.layNhanVien().InThongTin();
            cout << "\t\t--------------------------------------" << endl;

            string tempString = "n";
            while(tempString == "n") {
                cout << "\t\t# Option của nhân viên: " << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(25) << "Chức năng" << setw(18) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(33) << "Xem danh sách khách hàng" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(41) << "Tạo tài khoản cho khách hàng" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(35) << "Sửa thông tin khách hàng" << setw(10) << "|" << endl;
                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(41) << "Lấy thông tin của khách hàng" << setw(6) << "|" << endl;
                cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(23) << "Xóa khách hàng" << setw(20) << "|" << endl;
                cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(43) << "Lấy thông tin thẻ ATM cho khách" << setw(3) << "|" << endl;
                cout << "\t\t|" << setw(6) << "7" << setw(6) << "|" << setw(19) << "Đăng xuất" << setw(25) << "|" << endl;
                cout << "\t\t+-----------+---------------------------------------+" << endl;
                cout << "\t\t-> Option của bạn: ";
                cin >> option; fflush(stdin);

                cout << "\t\t+---------------------------------------------------+" << endl;

                string tempID;
                size_t tempIndex;

                switch(option){

                    case 1 : 
                        dsKhachHang.InDanhSach();
                        break;
                    case 2 :
                        dsKhachHang.taoTaiKhoanKhachHang();
                        break;
                    case 3 : 
                        giaoDienNhapID(tempID);
                        dsKhachHang.suaThongTinKhachHang(tempID);
                        break;
                    case 4 :
                        giaoDienNhapID(tempID);
                        tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        while(tempIndex == -1){
                            cout << "\t\t-> ID khách hàng không tồn tại ! Mời quý khách nhập lại....." << endl;
                            giaoDienNhapID(tempID);
                            tempIndex = dsKhachHang.timKiemKhachHang(tempID);
                        }
                        cout << "\t\t---------- Khách hàng " << tempID << "----------" << endl;
                        (dsKhachHang.getListKhachHang())[tempIndex].InThongTin();
                        break;
                    case 5 :
                    {
                        string idKhachHang;
                        cout << "\t\tNhập IdKhachHang muốn xóa: "; 
                        fflush(stdin); getline(cin, idKhachHang);
                        size_t index = dsKhachHang.timKiemKhachHang(idKhachHang);

                        while (index == -1)
                        {
                            string noti = "IdKhachHang không tồn tại.....";
                            goodbye(noti,30);
                            cout << "\t\tMời nhập lại IdKhachHang: "; 
                            fflush(stdin); getline(cin, idKhachHang);
                            index = dsKhachHang.timKiemKhachHang(idKhachHang);
                        }

                        KhachHang& kh = dsKhachHang.getListKhachHang()[index];
                        kh.xoaKhachHang();
                        dsLichSu.capNhatDanhSach();
                        dsKhachHang.capNhatDanhSach();
                        dsKhachHang.caiDatLichSuGiaoDich(dsLichSu);
                        break;
                    }
                    case 6 :
                    {
                        string idKhachHang;
                        cout << "\t\tNhập IdKhachHang cần lấy thông tin thẻ ATM: "; 
                        fflush(stdin); getline(cin, idKhachHang);
                        size_t index = dsKhachHang.timKiemKhachHang(idKhachHang);
                        cout << "\t\tThông tin thẻ ATM của quý khách là:" << endl;
                        dsKhachHang.getListKhachHang()[index].layThongTinThe().layThongTinThe();
                        break;
                    }
                    case 7 :
                    {
                        tempString = "c";
                        string gb = "Tạm biệt " + tk.layNhanVien().LayTen() + ".....";
                        goodbye(gb,50);
                        cout << endl << endl;
                        break;
                    }
                    default:
                    {
                        string noti = "Option không hợp lệ. Mời bạn nhập lại.....";
                        goodbye(noti,30);
                        cout << "\t\t+---------------------------------------------------+" << endl;
                    }

                } 

            }
        } 
        else if(first_choice == "kh") {

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp, tempString = "n";

            while (tempString == "n") {
                cout << "\t\t# Option của khách hàng: " << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(34) << "Chức năng" << setw(30) << "|" << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(30) << "Sử dụng thẻ ATM" << setw(37) << "|" << endl;
                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(37) << "Sử dụng ví điện tử" << setw(34) << "|" << endl;
                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(67) << "Muốn đăng kí là thành viên mới của ngân hàng" << setw(8) << "|" << endl;
                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(22) << "Đăng xuất" << setw(43) << "|" << endl;
                cout << "\t\t+-----------+------------------------------------------------------------+" << endl;
                cout << "\t\t-> Option của bạn: ";
                cin >> option; fflush(stdin);

                cout << "\t\t+------------------------------------------------------------------------+" << endl;
                if (option == 1 || option == 2 || option == 3) 
                    cout << "\t\t----------------------------- XIN CHÀO QUÝ KHÁCH -------------------------" << endl << endl;

                switch(option) {
                    
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
                            cout << "\t\t-> Option của bạn: ";
                            cin >> option; fflush(stdin);

                            cout << "\t\t+-------------------------------------------------+" << endl;

                            double d;
                            switch(option){
                                case 1 :    
                                    cout << "\t\tSố dư của bạn = " << to_string(the.laySoDu()) << endl;
                                    break;
                                case 2 :
                                    cout << "\t\tSố tiền muốn rút = "; cin >> d;
                                    if(the.laySoDu() < d) {
                                        string noti = "Số tiền cần rút không hợp lệ !";
                                        goodbye(noti,30);
                                    }
                                    else {
                                        the.RutTien(d, "Rút tiền từ tài khoản với số tiền: " + to_string(d));

                                        string noti = "Rút tiền thành công !";
                                        goodbye(noti,30);
                                        cout << "\t\t-> Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                    }
                                    break;
                                case 3 :
                                {
                                    cout << "\t\tSố tiền muốn nạp = "; cin >> d;
                                    the.NapTien(d, "Nạp tiền vào tài khoản với số tiền: " + to_string(d));

                                    string noti = "Nạp tiền thành công !";
                                    goodbye(noti,30);
                                    cout << "\t\t-> Số dư hiện tại = " << to_string(the.laySoDu()) << endl;
                                    break;
                                }
                                case 4 : 
                                    cout << "\t\tNhập số tài khoản người nhận: ";
                                    getline(cin, maTaiKhoan);
                                    tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                    if(tempIndex == -1) {
                                        string noti = "Không tìm thấy số tài khoản !";
                                        goodbye(noti,30);
                                    }
                                    else {
                                        cout << "\t\t--------------- Thông tin người nhận --------------" << endl;
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
                                    cout << "\t\t~~~~~~~~~~~~~~~~ Lịch sử giao dịch ~~~~~~~~~~~~~~~~" << endl;    
                                    the.inLichSuGiaoDich();
                                    break;
                                case 6 : 
                                {
                                    string gb = "Giao dịch đã kết thúc. Xin kính chào quý khách.....";
                                    goodbye(gb,45);
                                    cout << endl << endl;
                                    break;
                                }
                                default:
                                {
                                    string noti = "Option không hợp lệ. Mời bạn nhập lại.....";
                                    goodbye(noti,30);
                                    cout << "\t\t+-------------------------------------------------+" << endl;
                                }
                            }
                            if (option == 6) break;
                        }
                        break;
                    
                    case 2 :
                    {
                        double d;
                        string IdVi,IdATM;
                        string opt;
                        cout << "\t\t(!) Bạn đã có ví điện tử chưa? (c/n): "; 
                        fflush(stdin); getline(cin ,opt);
                        if (opt == "c")
                        {
                            giaoDienDangNhap(tenDangNhap, matKhau);
                            while(!dsVi.kiemTraDangNhap(tenDangNhap, matKhau)){
                                cout << "\t\tTài khoản hoặc mật khẩu bị sai. Vui lòng đăng nhập lại....." << endl << endl;
                                giaoDienDangNhap(tenDangNhap,matKhau);
                            }

                            while(dsVi.kiemTraDangNhap(tenDangNhap, matKhau)){
                                ViDienTu& vi = dsVi.suDungVi(tenDangNhap, matKhau);
                                size_t index = dsVi.suDungVi(tenDangNhap);

                                cout << "\t\t--------------------- VÍ META ----------------------" << endl << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(25) << "Chức năng" << setw(17) << "|" << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(33) << "Xem số tiền trong ví" << setw(11) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(29) << "Nạp tiền vào ví" << setw(16) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(30) << "Rút tiền về thẻ" << setw(16) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(38) << "Mua thẻ cào điện thoại" << setw(9) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(40) << "Chuyển tiền đến ví khác" << setw(8) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(35) << "Thêm liên kết thẻ ATM" << setw(10) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "7" << setw(6) << "|" << setw(34) << "Gỡ liên kết thẻ ATM" << setw(12) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "8" << setw(6) << "|" << setw(31) << "Kết thúc giao dịch" << setw(13) << "|" << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t-> Option của bạn: ";
                                cin >> option; fflush(stdin);

                                cout << "\t\t+--------------------------------------------------+" << endl;

                                switch(option){
                                    case 1 :    
                                        cout << "\t\tSố tiền trong ví của bạn = " << to_string(vi.laySoDu()) << endl << endl;
                                        break;
                                    case 2 :
                                        vi.napTien(dsKhachHang);
                                        break;
                                    case 3 :
                                        vi.rutTien(dsKhachHang);
                                        break;
                                    case 4:
                                    {
                                        double soTien;
                                        string nhamang = Phone(soTien);

                                        vi.napTienDT(dsKhachHang,soTien);
                                        cout << endl << "\t\t-> Thẻ cào của bạn:" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl;
                                        cout << "\t\t|" << setw(27) << nhamang << setw(20) <<  "|" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl;
                                        int y = (int)soTien;
                                        if (soTien <= 50000 && soTien >= 10000)
                                        {
                                            cout << "\t\t|  Mệnh giá: " << to_string(y) << setw(30) << "|" << endl;
                                        }
                                        else
                                            cout << "\t\t|  Mệnh giá: " << to_string(y) << setw(29) << "|" << endl;
                                        cout << "\t\t|  Mã thẻ cào: "; MaTheCao(); cout << setw(20) << "|" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl << endl;
                                        break;
                                    }
                                    case 5 : 
                                    {
                                        cout << "\t\tNhập số ví người nhận : ";
                                        getline(cin, IdVi);
                                        tempIndex = dsVi.suDungVi(IdVi);
                                        while (tempIndex == -1)
                                        {
                                            cout << "\t\tKhông tìm thấy ví người nhận !" << endl;
                                            cout << "\t\tXin mời nhập lại số ví người nhận: ";
                                            getline(cin, IdVi);
                                            tempIndex = dsVi.suDungVi(IdVi);
                                        }
                                        ViDienTu& viCanChuyen = dsVi.getListVi()[tempIndex];
                                        string opt;
                                        cout << "\t\t-> Người nhận: " << viCanChuyen.layTaiKhoan() << endl;
                                        cout << "\t\tNhập số tiền cần chuyển : ";
                                        cin >> soTien;
                                        if(soTien > vi.laySoDu()) {
                                            cout << "\t\tSố tiền trong ví không đủ!" << endl;
                                            cout << "\t\tBạn có muốn nạp tiền? (c/n): "; 
                                            fflush(stdin); getline(cin, opt);
                                            if (opt == "c") {
                                                vi.napTien(dsKhachHang);
                                                vi.chuyenTienDenVi(viCanChuyen, soTien);
                                                string noti = "Chuyển tiền thành công!";
                                                goodbye(noti,30);    
                                                cout << "\t\t-> Số tiền hiện tại = " << to_string(vi.laySoDu()) << endl;
                                            }
                                            else {
                                                string noti = "Chuyển tiền không thành công!";
                                                goodbye(noti,30);
                                            } 
                                        }
                                        else {
                                            vi.chuyenTienDenVi(viCanChuyen, soTien);
                                            string noti = "Chuyển tiền thành công!";
                                            goodbye(noti,30);
                                            cout << "\t\t-> Số tiền hiện tại = " << to_string(vi.laySoDu()) << endl;
                                        }
                                        break;
                                    }
                                    case 6 :   
                                    { 
                                        cout << "\t\tNhập mã thẻ ATM muốn liên kết đến ví: "; 
                                        fflush(stdin); getline(cin, IdATM);
                                        size_t index = dsKhachHang.timKiemATM(IdATM);

                                        while (index == -1)
                                        {
                                            cout << "\t\tMã thẻ ATM không hợp lệ!" << endl;
                                            cout << "\t\tNhập lại mã thẻ ATM muốn liên kết đến ví: ";
                                            fflush(stdin); getline(cin, IdATM);
                                            index = dsKhachHang.timKiemATM(IdATM);
                                        }

                                        TheATM &the = (dsKhachHang.getListKhachHang()[index]).layThongTinThe();
                                        vi.themLienKetTheATM(the);
                                        cout << "\t\t-> Liên kết thẻ ATM thành công!" << endl;
                                        break;
                                    }
                                    case 7 :
                                    { 
                                        cout << "\n\t\t--- Danh sách các thẻ đã liên kết với ví điện tử ---" << endl;
                                        cout << vi.getList() << endl;
                                        cout << "\t\tNhập mã thẻ ATM muốn gỡ liên kết: "; 
                                        fflush(stdin); getline(cin, IdATM);
                                        size_t index = dsKhachHang.timKiemATM(IdATM);
                                        int exist = 1; // Thẻ tồn tại

                                        while (vi.getList().findEle(IdATM) == -1 || index == -1)
                                        {
                                            // Khi nhập sai
                                            if(vi.getList().findEle(IdATM) == -1)
                                                cout << "\t\tMã thẻ ATM không hợp lệ!" << endl;
                                            else {
                                                // Khi thẻ không còn tồn tại
                                                vi.goLienKetTheATM(IdATM);
                                                cout << "\t\tMã thẻ ATM không còn tồn tại!" << endl;
                                                cout << "\n\t\t--- Danh sách các thẻ đã liên kết với ví điện tử ---" << endl;
                                                cout << vi.getList() << endl;
                                                exist = 0;
                                            } 
                                            if (exist == 0) break; // Nếu thẻ không tồn tại
                                            else {
                                                cout << "\t\tMời bạn nhập lại mã thẻ ATM muốn gỡ liên kết: ";
                                                fflush(stdin); getline(cin, IdATM);
                                                index = dsKhachHang.timKiemATM(IdATM);
                                            }
                                        } 
                                        if (exist != 0) vi.goLienKetTheATM(IdATM); // Nếu thẻ có tồn tại thì gỡ
                                        cout << "\t\t-> Gỡ liên kết thẻ ATM thành công!" << endl;
                                        break;
                                    }
                                    case 8 :
                                    {
                                        string gb = "Ví META xin kính chào quý khách.....";
                                        goodbye(gb,45);
                                        cout << endl << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        string noti = "Option không hợp lệ. Mời bạn nhập lại.....";
                                        goodbye(noti,30);
                                        cout << "\t\t+-------------------------------------------------+" << endl;
                                    }
                                }
                                if (option == 8) break;
                            }
                        }
                        else {
                            cout << "\t\t------------- Cài đặt ví điện tử META -------------" << endl;
                            dsVi.taoViDienTu();

                            giaoDienDangNhap(tenDangNhap, matKhau);
                            while(!dsVi.kiemTraDangNhap(tenDangNhap, matKhau)){
                                cout << "\t\tTài khoản hoặc mật khẩu bị sai. Vui lòng đăng nhập lại....." << endl << endl;
                                giaoDienDangNhap(tenDangNhap,matKhau);
                            }

                            while(dsVi.kiemTraDangNhap(tenDangNhap, matKhau)){
                                ViDienTu& vi = dsVi.suDungVi(tenDangNhap, matKhau);
                                size_t index = dsVi.suDungVi(tenDangNhap);

                                cout << "\t\t--------------------- VÍ MOMO ----------------------" << endl << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t|" << setw(9) << "Option" << setw(3) << "|" << setw(25) << "Chức năng" << setw(17) << "|" << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t|" << setw(6) << "1" << setw(6) << "|" << setw(33) << "Xem số tiền trong ví" << setw(11) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "2" << setw(6) << "|" << setw(29) << "Nạp tiền vào ví" << setw(16) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "3" << setw(6) << "|" << setw(30) << "Rút tiền về thẻ" << setw(16) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "4" << setw(6) << "|" << setw(38) << "Mua thẻ cào điện thoại" << setw(9) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "5" << setw(6) << "|" << setw(40) << "Chuyển tiền đến ví khác" << setw(8) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "6" << setw(6) << "|" << setw(35) << "Thêm liên kết thẻ ATM" << setw(10) << "|" << endl;
                                cout << "\t\t|" << setw(6) << "7" << setw(6) << "|" << setw(31) << "Kết thúc giao dịch" << setw(13) << "|" << endl;
                                cout << "\t\t+-----------+--------------------------------------+" << endl;
                                cout << "\t\t-> Option của bạn: ";
                                cin >> option; fflush(stdin);

                                cout << "\t\t+--------------------------------------------------+" << endl;

                                switch(option){
                                    case 1 :    
                                        cout << "\t\tSố tiền trong ví của bạn = " << to_string(vi.laySoDu()) << endl << endl;
                                        break;
                                    case 2 :
                                        vi.napTien(dsKhachHang);
                                        break;
                                    case 3 :
                                        vi.rutTien(dsKhachHang);
                                        break;
                                    case 4:
                                    {
                                        double soTien;
                                        string nhamang = Phone(soTien);

                                        vi.napTienDT(dsKhachHang,soTien);
                                        cout << endl << "-> Thẻ cào của bạn:" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl;
                                        cout << "\t\t|" << setw(27) << nhamang << setw(20) <<  "|" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl;
                                        int y = (int)soTien;
                                        if (soTien <= 50000 && soTien >= 10000)
                                        {
                                            cout << "\t\t|  Mệnh giá: " << to_string(y) << setw(30) << "|" << endl;
                                        }
                                        else
                                            cout << "\t\t|  Mệnh giá: " << to_string(y) << setw(29) << "|" << endl;
                                        cout << "\t\t|  Mã thẻ cào: "; MaTheCao(); cout << setw(20) << "|" << endl;
                                        cout << "\t\t+----------------------------------------------+" << endl;
                                        break;
                                    }
                                    case 5 : 
                                    {
                                        cout << "\t\tNhập số ví người nhận: ";
                                        getline(cin, IdVi);
                                        tempIndex = dsVi.suDungVi(IdVi);
                                        while (tempIndex == -1)
                                        {
                                            cout << "\t\tKhông tìm thấy ví người nhận !" << endl;
                                            cout << "\t\tXin mời nhập lại số ví người nhận: ";
                                            getline(cin, IdVi);
                                            tempIndex = dsVi.suDungVi(IdVi);
                                        }
                                        ViDienTu& viCanChuyen = dsVi.getListVi()[tempIndex];
                                        string opt;
                                        cout << "\t\t-> Người nhận: " << viCanChuyen.layTaiKhoan() << endl;
                                        cout << "\t\tNhập số tiền cần chuyển: ";
                                        cin >> soTien;
                                        if(soTien > vi.laySoDu()) {
                                            cout << "\t\tSố tiền trong ví không đủ !" << endl;
                                            cout << "\t\tBạn có muốn nạp tiền? (c/n): "; fflush(stdin); getline(cin, opt);
                                            if (opt == "c") {
                                                vi.napTien(dsKhachHang);
                                                vi.chuyenTienDenVi(viCanChuyen, soTien);
                                                string noti = "Chuyển tiền thành công !";
                                                goodbye(noti,30);
                                                cout << "\t\t-> Số tiền hiện tại = " << to_string(vi.laySoDu()) << endl;
                                            }
                                            else {
                                                string noti = "Chuyển tiền không thành công !";
                                                goodbye(noti,30);
                                            } 
                                        }
                                        else {
                                            vi.chuyenTienDenVi(viCanChuyen, soTien);
                                            string noti = "Chuyển tiền thành công !";
                                            goodbye(noti,30);
                                            cout << "\t\t-> Số tiền hiện tại = " << to_string(vi.laySoDu()) << endl;
                                        }
                                        break;
                                    }
                                    case 6 :   
                                    { 
                                        cout << "\t\tNhập mã thẻ ATM muốn liên kết đến ví: "; 
                                        fflush(stdin); getline(cin, IdATM);
                                        size_t index = dsKhachHang.timKiemATM(IdATM);

                                        while (index == -1)
                                        {
                                            cout << "\t\tMã thẻ ATM không hợp lệ !" << endl;
                                            cout << "\t\tNhập lại mã thẻ ATM muốn liên kết đến ví: ";
                                            fflush(stdin); getline(cin, IdATM);
                                            index = dsKhachHang.timKiemATM(IdATM);
                                        }

                                        TheATM &the = (dsKhachHang.getListKhachHang()[index]).layThongTinThe();
                                        vi.themLienKetTheATM(the);
                                        cout << "\t\t-> Liên kết thẻ ATM thành công !" << endl;
                                        break;
                                    }
                                    case 7 : 
                                    {
                                        string gb = "Ví META xin kính chào quý khách.....";
                                        goodbye(gb,45);
                                        cout << endl << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        string noti = "Option không hợp lệ. Mời bạn nhập lại.....";
                                        goodbye(noti,30);
                                        cout << "\t\t+-------------------------------------------------+" << endl;
                                    }
                                }
                                if (option == 7) break;
                            }
                        }
                        break;
                    }
                
                    case 3 :
                    {
                        srand(time(0));
                        size_t index = rand() % dsNhanVien.getListNhanVien().getCurr();

                        NhanVien& nv = dsNhanVien.getListNhanVien()[index];
                        cout << nv << endl;

                        cout << "\t\tVui lòng nhập các thông tin dưới đây !" << endl;
                        dsKhachHang.taoTaiKhoanKhachHang(); 
                        cout << "\t\t-> Đã tạo tài khoản thành công !" << endl;
                        break;
                    }
                    
                    case 4 :
                    {
                        tempString = "c";
                        string gb = "Tạm biệt quý khách.....";
                        goodbye(gb,40);
                        cout << endl << endl;
                        break;
                    }
                    default:
                    {
                        string noti = "Option không hợp lệ. Mời bạn nhập lại.....";
                        goodbye(noti,30);
                        cout << "\t\t+-------------------------------------------------+" << endl;
                    }    
                    
                }

            }

        } else if (first_choice == "exit") {
            string gb = "XIN CHÀO TẠM BIỆT VÀ HẸN GẶP LẠI QUÝ KHÁCH.....";
            goodbye(gb,35);   
            break;
        }
        else {
            string s = "Option không hợp lệ. Mời bạn chọn lại.....";
            goodbye(s,30); cout << endl;
        }  
        
    }
    return 0;
}
