#include <iostream>
#include "NhanVien.cpp"
#include "KhachHang.cpp"


using namespace std;
/*
void giaoDienDangNhap(string &tk, string &mk){
    cout << "Xin mời đăng nhập : " << endl;
    cout << "Tài khoản : "; getline(cin,tk);
    cout << "Mật khẩu : "; getline(cin, mk);
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
        getline(cin,choice);

        // Mã tài khoản ATM
        string tenDangNhap, matKhau, maTaiKhoan;

        if(choice == "1"){

            giaoDienDangNhap(tenDangNhap, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);

            if(dsTaiKhoan.kiemTraTaiKhoan(tk)){
                TaiKhoanNhanVien tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
                cout << "------ Xin chào -------" << endl;
                tk.layNhanVien().LayThongTinCaNhan();
                cout << "Bạn muốn : " << endl;
                cout << "1. Xem danh sách khách hàng" << endl;
                cout << "2. Tạo tài khoản cho khách hàng" << endl;
                cout << "3. Sửa thông tin khách hàng" << endl;
                cout << "4. Lấy thông tin của khách hàng" << endl;
                getline(cin, choice);

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
                        cout << "\tNhập ID của khách hàng muốn sửa đổi thông tin : ";
                        getline(cin, tempID); 
                        
                        dsKhachHang.suaThongTinKhachHang(tempID);
                        break;
                    case 4:
                        cout << "\tNhập ID của khách hàng muốn lấy thông tin :  ";
                        getline(cin, tempID);

                        dsKhachHang.TimKiemKhachHang(tempID);
                        break;
                }
                break;
            }
            else 
                cout << "Not OK";

        } else {

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
                    if(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
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
                                cout << "Số tiền muốn rút = " << endl;
                                cin >> d;
                                if(the.laySoDu() < d)
                                    cout << "Số tiền cần rút không hợp lệ";
                                else {
                                    the.RutTien(d);
                                    cout << "Số dư hiện tại = " << to_string(the.laySoDu());
                                }
                                break;
                            case 3 :
                                cout << "Số tiền muốn nạp = ";
                                cin >> d;
                                the.NapTien(d);
                                cout << "Số dư hiện tại = " << to_string(the.laySoDu());
                                break;
                        }
                    } else 
                        cout << "Not OK";
                    break;
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
                                    cout << "Thẻ ATM này đã có tài khoản online banking" << endl;
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
        }
    }

    system("pause");
    return 0;
}*/

void giaoDienDangNhap(string &tk, string &mk){
    cout << "Xin moi dang nhap : " << endl;
    cout << "Tai khoan : "; getline(cin,tk);
    cout << "Mat khau : "; getline(cin, mk);
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

        cout << "Ban la " << endl;
        cout << "1. Nhan vien" << endl;
        cout << "2. Khach hang" << endl;
        string choice;
        getline(cin,choice);

        // Mã tài khoản ATM
        string tenDangNhap, matKhau, maTaiKhoan;

        if(choice == "1"){

            giaoDienDangNhap(tenDangNhap, matKhau);
            tenDangNhap = "NV" + tenDangNhap;

            TaiKhoanNhanVien tk(tenDangNhap,matKhau);

            if(dsTaiKhoan.kiemTraTaiKhoan(tk)){
                TaiKhoanNhanVien tk = dsTaiKhoan.suDungTaiKhoan(tenDangNhap, matKhau);
                cout << "------ Xin chao -------" << endl;
                tk.layNhanVien().LayThongTinCaNhan();
                cout << "Ban muon : " << endl;
                cout << "1. Xem danh sach khach hang" << endl;
                cout << "2. Tao tai khoan cho khách hang" << endl;
                cout << "3. Sua thong tin khach hang" << endl;
                cout << "4. Lay thong tin của khach hang" << endl;
                getline(cin, choice);

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
                        cout << "\tNhap ID cua khach hang muon sua doi thong tin : ";
                        getline(cin, tempID); 
                        
                        dsKhachHang.suaThongTinKhachHang(tempID);
                        break;
                    case 4:
                        cout << "\tNhap ID cua khach hang muon lay thong tin :  ";
                        getline(cin, tempID);

                        dsKhachHang.TimKiemKhachHang(tempID);
                        break;
                }
                break;
            }
            else 
                cout << "Not OK";

        } else {

            size_t tempIndex;
            double soTien;
            // temp dùng để lưu idKhachHang, ...
            string temp;

            cout << "1. Su dung the ATM" << endl;
            cout << "2. Su dung online banking" << endl;
            cout << "3. Muon dang ki la thanh vien của ngan hang hoac dang ki online banking" << endl;

            getline(cin,choice);

            switch(stoi(choice)){
                case 1 :
                    giaoDienDangNhap(tenDangNhap, matKhau);
                    if(dsKhachHang.kiemTraTheATM(tenDangNhap, matKhau)){
                        size_t viTriKhachHang = dsKhachHang.suDungATM(tenDangNhap, matKhau);
                        TheATM& the = dsKhachHang.getSetATM()[viTriKhachHang];

                        cout << "\t1. Xem so du" << endl;
                        cout << "\t2. Rut tien" << endl;
                        cout << "\t3. Nap tien" << endl;
                        getline(cin, choice);
                        double d;
                        switch(stoi(choice)){
                            case 1 :    
                                cout << "So du = " << to_string(the.laySoDu()) << endl;
                                break;
                            case 2 :
                                cout << "So tien muon rut = " << endl;
                                cin >> d;
                                if(the.laySoDu() < d)
                                    cout << "So tien can rut khong hop le";
                                else {
                                    the.RutTien(d);
                                    cout << "So du hien tai = " << to_string(the.laySoDu());
                                }
                                break;
                            case 3 :
                                cout << "So tien muon nap = ";
                                cin >> d;
                                the.NapTien(d);
                                cout << "So du hien tai = " << to_string(the.laySoDu());
                                break;
                        }
                    } else 
                        cout << "Not OK";
                    break;
                case 2 :

                    giaoDienDangNhap(tenDangNhap, matKhau);

                    if(dsOnlineBanking.kiemTraTaiKhoan(tenDangNhap, matKhau)){
                        cout << "\t1. Xem so dd" << endl;
                        cout << "\t2. Chuyen tien" << endl;
                        getline(cin, choice);
                        string idKhachHang = dsOnlineBanking.layIDKhachHang(tenDangNhap,matKhau);

                        TheATM& the = dsKhachHang.layThongTinTheATM(idKhachHang);

                        switch(stoi(choice)){
                            case 1:   
                                cout << "So du = " << to_string(the.laySoDu()) << endl; 
                                break;
                            case 2: 
                                cout << "Nhap so tai khoan ATM nguoi nhan : ";
                                getline(cin, maTaiKhoan);
                                tempIndex = dsKhachHang.timKiemATM(maTaiKhoan);
                                if(tempIndex == -1)
                                    cout << "Khong tim thay ma tai khoan" << endl;
                                else {
                                    cout << "Thong tin nguoi nhan : " << endl;
                                    (dsKhachHang.getSetKhachHang())[tempIndex].LayThongTinCaNhan();
                                    TheATM& nguoiNhan = dsKhachHang.getSetATM()[tempIndex];
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
                    cout << "1. Dang ki online banking" << endl;
                    cout << "2. Dang ki thanh vien moi cua ngan hang" << endl;
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
                                    cout << "Tha ATM nay da co tai khoan online banking" << endl;
                            } else {
                                cout << "Dang nhap sai" << endl;
                            }
                            break;
                        case 2 :
                            cout << "Vui long nhap cac thong tin duoi day !" << endl;
                            dsKhachHang.taoTaiKhoanKhachHang();
                            break;
                    }
                    

                    break;
            }
            break;
        }
    }

    system("pause");
    return 0;
}