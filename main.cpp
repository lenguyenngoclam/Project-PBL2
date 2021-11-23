#include <iostream>
#include "NhanVien.cpp"
#include "KhachHang.cpp"

using namespace std;

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
        getline(cin,choice);

        //Mã tài khoản ATM
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

                cout << "Đăng xuất ? (c/n)";
                getline(cin, tempString);
            }
        } else if(choice == "kh"){

            size_t tempIndex;
            double soTien;
            //temp dùng để lưu idKhachHang, ...
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
                                cout << "Số tiền muốn rút = " << endl;
                                cin >> d;
                                if(the.laySoDu() < d)
                                    cout << "Số tiền cần rút không hợp lệ";
                                else {
                                    the.RutTien(d);
                                    cout << "Số dư còn lại = " << to_string(the.laySoDu());
                                }
                                break;
                            case 3 :
                                cout << "Số tiền muốn nạp = ";
                                cin >> d;
                                the.NapTien(d);
                                cout << "Số dư còn lại = " << to_string(the.laySoDu());
                                break;
                        }
                        cout << "Đăng xuất ? (c/n)";
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
                                        cout << "Số dư còn lại = " << to_string(the.laySoDu()) << endl;
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
                    cout << "2. Đang kí thành viên mới của ngân hàng" << endl;
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
        } else {
            cout << "Error";
        }
    }

    
   return 0;
}