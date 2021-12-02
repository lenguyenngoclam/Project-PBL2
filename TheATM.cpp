#include <iostream>
#include <fstream>
#include <string>

#include "include.h"
#include "LichSuGiaoDich.cpp"

using namespace std;

class TheATM{
    private :
        string MaTaiKhoan;
        string MatKhau;
        double soDu;
        string idKhachHang;
        size_t default_count = 0;
        Set<LichSuGiaoDich> set;
    public :    
        TheATM(string tk, string mk) : MaTaiKhoan(tk), MatKhau(mk), soDu(0), idKhachHang(""), default_count(0) {};
        TheATM(string tk, string mk, double d, string id) : soDu(d), MatKhau(mk), MaTaiKhoan(tk), idKhachHang(id), default_count(0){};
        TheATM() : soDu(0), MatKhau(""), MaTaiKhoan(""), idKhachHang(""), default_count(0) {};

        TheATM(const TheATM&);

        TheATM& operator =(const TheATM& the);

        void NapTien(double soTien);
        void RutTien(double );
        double laySoDu();

        string layMaThe() { return MaTaiKhoan; }
        string layIDKhachHang() { return idKhachHang; }

        // Hàm thành viên có tác dụng ghi lại tất cả các dòng trong file KHACHHANG.txt nhưng thay đổi số dư của thẻ dựa trên con trỏ hàm
        void suaFile(double (*func)(double, double), double soTien);
        // Ghi lịch sử giao dịch vào file
        void ghiFile(LichSuGiaoDich& lsu);

        // Ghi dữ liệu người dùng nhập vào file 
        void caiDatTheATM();
        // Hiển thị mã tài khoản và số dư của thẻ
        void layThongTinThe();
        // Chuyển tiền cho thẻ ATM khác
        void chuyenTien(TheATM& maThe, double tien);
        // In lịch sử giao dịch
        void inLichSuGiaoDich();
        // Thêm lịch sử giao dịch tử file
        void caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich&);

        friend class KhachHang;
        friend class DanhSachKhachHang;

        bool operator==(const TheATM& the);
};


// ----------------------------------------------------------------------------------------------------------------------------------------------
// HAM CHUC NANG

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
// THE ATM

TheATM::TheATM(const TheATM& the) : soDu(the.soDu), MaTaiKhoan(the.MaTaiKhoan), 
                                    MatKhau(the.MatKhau), idKhachHang(the.idKhachHang), default_count(the.default_count), set(the.set){}

TheATM& TheATM::operator =(const TheATM& the){
    soDu = the.soDu;
    MaTaiKhoan = the.MaTaiKhoan;
    MatKhau = the.MatKhau;
    idKhachHang = the.idKhachHang;
    default_count = the.default_count;
    set = the.set;
    return (*this);
}

double TheATM::laySoDu(){
    return soDu;
}

bool TheATM::operator ==(const TheATM& the){
    return (the.MaTaiKhoan == MaTaiKhoan && the.MatKhau == MatKhau); 
}

void TheATM::caiDatTheATM(){
    ofstream fout;
    fout.open("KHACHHANG.txt",ios::app);
    string line;

    cout << "\t\t- Xin moi nhap ma the ATM : "; fflush(stdin);
    getline(cin,MaTaiKhoan);
    fout << MaTaiKhoan << endl;

    char s[50];
    cout << "\t\t- Xin moi nhap mat khau : "; fflush(stdin);
    getpassword(s,50); MatKhau = s;
    fout << MatKhau << endl;

    cout << "\t\t-> So tien nap vao tai khoan : "; fflush(stdin);
    cin >> soDu;
    fout << to_string(soDu);

}

void TheATM::layThongTinThe(){
    cout << "\t\t- Ma so the ATM : " << MaTaiKhoan << endl;
    cout << "\t\t- So du trong the : " << to_string(soDu) << endl;
}

void TheATM::suaFile(double (*func)(double, double), double soTien){
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file KHACHHANG.txt và đổi tên file temp thành KHACHHANG
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            number_KhachHang = line.substr(0,line.size()-1); // Cắt kí tự "\n" cuối line
            ++count; fout << line << endl;
        }
        else if (count == khachHang_count_line) fout << line; 
        else { 
            ++count; 
            fout << line << endl; 
        }
        if (line == MaTaiKhoan){
            // Lấy dòng chứa mật khẩu thẻ atm trong NHANVIEN.txt
            getline(fin, line);
            if(line == MatKhau){
                fout << line << endl;
                // Lấy dòng chứa số dư trong thẻ
                getline(fin,line);
                ++count;
                
                double d = stod(line);
                // Sử dụng con trỏ hàm tìm hàm cộng hoặc trừ hợp lí đối với trường hợp rút tiền hoặc nạp tiền
                d = func(d,soTien);
                soDu = d;

                if(count != khachHang_count_line)
                    fout << to_string(d) << endl;
                else    
                    fout << to_string(d);
                count++;
            } else {
                fout << line << endl;
                count++;
            }
        }
    }

    fin.close();
    fout.close();

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt"); 
}

void TheATM::ghiFile(LichSuGiaoDich& lsu){
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file LichSuGiaoDich.txt và đổi tên file temp thành LichSuGiaoDich
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            ++count;
            soLuongGiaoDich++;
            fout << to_string(soLuongGiaoDich) << endl;
        }
        else { 
            ++count; 
            fout << line << endl; 
        }
    }

    fout << lsu.layMaGiaoDich() << endl;
    fout << lsu.layNoiDung() << endl;
    fout << lsu.layMaTaiKhoan();

    fin.close();
    fout.close();

    remove("LichSuGiaoDich.txt");
    rename("temp.txt","LichSuGiaoDich.txt");  
}

void TheATM::NapTien(double d){
    suaFile(add,d);
    string maGD = "#" + to_string(soLuongGiaoDich);
    string nd = "Nạp tiền vào tài khoản với số tiền : " + to_string(d);
    LichSuGiaoDich ls(maGD,nd,MaTaiKhoan);
    ghiFile(ls);
    set.insert(ls);
}

void TheATM::RutTien(double d){
    suaFile(sub,d);
    string maGD = "#" + to_string(soLuongGiaoDich);
    string nd = "Rút tiền từ tài khoản với số tiền : " + to_string(d);
    LichSuGiaoDich ls(maGD,nd,MaTaiKhoan);
    ghiFile(ls);
    set.insert(ls);
}

void TheATM::chuyenTien(TheATM& the, double tien){
    suaFile(sub,tien);
    the.suaFile(add,tien);
    string maGD = "#" + to_string(soLuongGiaoDich);
    string maThe = the.layMaThe();

    string nd = "Chuyển tiền sang tài khoản có mã thẻ " + maThe + " với số tiền : " + to_string(tien);
    string nd2 = "Nhận tiền từ tài khoản có mã thẻ " + MaTaiKhoan + " với số tiền : " + to_string(tien);

    LichSuGiaoDich ls(maGD,nd,MaTaiKhoan);
    ghiFile(ls);
    set.insert(ls);

    maGD = "#" + to_string(soLuongGiaoDich);
    LichSuGiaoDich ls1(maGD, nd2, maThe);
    ghiFile(ls1);
    the.set.insert(ls1);
}

void TheATM::inLichSuGiaoDich(){
    for(int i = 0; i < set.getCurr(); i++)
        cout << set[i] << endl;
}

void TheATM::caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich& ds){
    set = Set<LichSuGiaoDich>(default_count);
    for(int i = 0; i < ds.set.getCurr(); i++){
        if(ds.set[i].layMaTaiKhoan() == MaTaiKhoan){
            set.insert(ds.set[i]);
        }
    }
}