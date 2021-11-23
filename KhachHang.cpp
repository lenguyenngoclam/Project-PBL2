#include "KhachHang.h"

using namespace std;

// ----------------------------------------------------------------------------------------------------------------------------------------------
// HAM CHUC NANG

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// KHACH HANG

KhachHang::KhachHang(string id, string ten, string dc, string sdt, string t) : ThongTinCaNhan(ten,dc,sdt,t) {
    idKhachHang = id;
}

KhachHang::KhachHang(const KhachHang &kh) : ThongTinCaNhan(kh) {
    idKhachHang = kh.idKhachHang;
}

KhachHang &KhachHang::operator =(const KhachHang &kh) {
    ThongTinCaNhan::operator =(kh);
    idKhachHang = kh.idKhachHang;
    return *this;
}

string KhachHang::LaySoLuong()
{
    return number_KhachHang;
}


void KhachHang::DoiThongTinCaNhan() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
    ofstream fout;
    fout.open("temp.txt", ios::app);
    this -> ThongTinCaNhan::DoiThongTinCaNhan();
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
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
        if (line == idKhachHang){
            for(int i = 0; i < 4; i++){
                getline(fin, line);
                line.replace(0, line.length(), a[i]);
                b[i] = a[i];
                fout << line << endl;
            }
            count += 4;
        }
    }

    fin.close();
    fout.close();

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");
}

void KhachHang::LayThongTinCaNhan() const{
    cout << "- ID: " << idKhachHang << endl;
    ThongTinCaNhan::LayThongTinCaNhan();
}

void KhachHang::CaiDatThongTin()
{
    ThongTinCaNhan::NhapThongTinCaNhan();
    string temp = "KH";
    int num = stoi(number_KhachHang);
    num++; 
    number_KhachHang = to_string(num);
    idKhachHang = temp + number_KhachHang;

    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file KHACHHANG.txt và đổi tên file temp thành KHACHHANG
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            fout << number_KhachHang << endl;
            count++;
        } else {
            fout << line << endl;
        }
    }

    fout << idKhachHang << endl;
    fout << HoTen << endl;
    fout << Tuoi << endl;
    fout << DiaChi << endl;
    fout << SoDienThoai << endl;

    fin.close();
    fout.close();

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");  
}

bool KhachHang::operator ==(const KhachHang& rhs) const{
    return idKhachHang.compare(rhs.idKhachHang) == 0;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH KHACH HANG 
void DanhSachKhachHang::CaiDatDanhSach(){
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    getline(fin, number_KhachHang);
    khachHang_count_line += 1;
    while(!fin.eof()){
        KhachHang temp;
        getline(fin, temp.idKhachHang);
        getline(fin, temp.HoTen);
        getline(fin, temp.Tuoi);
        getline(fin, temp.DiaChi);
        getline(fin, temp.SoDienThoai);
        
        string tk, mk, soDu;
        getline(fin, tk);
        getline(fin, mk);
        getline(fin, soDu);

        double d = stod(soDu);
        TheATM theAtm = TheATM(tk,mk,d);

        setKhachHang.insert(temp);
        setATM.insert(theAtm);

        khachHang_count_line += 8;
    }
    fin.close();
}

ostream& operator <<(ostream& os, const KhachHang& kh){
    kh.LayThongTinCaNhan();
    return os;
}

void DanhSachKhachHang::InDanhSach(){
    cout << "---------------Danh sach khach hang---------------" << endl;
    for(size_t i = 0; i < setKhachHang.getSize(); i++)
        setKhachHang[i].LayThongTinCaNhan();
}

void DanhSachKhachHang::TimKiemKhachHang(string id) // Tìm kiếm khách hàng theo idKhachHang
{
    cout << "-----------------Khach Hang " << id << "-------------------" << endl;
    KhachHang kh(id);

    int index = setKhachHang.findEle(kh);

    if(index == -1) 
        cout << "-> Khong co nhan vien co ID " << id << "!" << endl;
    else {
        setKhachHang[index].LayThongTinCaNhan();
        setATM[index].layThongTinThe();
    }
}

void DanhSachKhachHang::taoTaiKhoanKhachHang(){
    KhachHang temp;
    temp.CaiDatThongTin();
    setKhachHang.insert(temp);
    TheATM the;
    the.caiDatTheATM();
    setATM.insert(the);
}

void DanhSachKhachHang::suaThongTinKhachHang(string id){
    KhachHang temp(id);
    size_t index = setKhachHang.findEle(temp);
    if(index == -1){
        cout << "Khong tim thay khach hang" << endl;
    } else {
        setKhachHang[index].DoiThongTinCaNhan();
    }
}

bool DanhSachKhachHang::kiemTraTheATM(string tk, string mk){
    TheATM the(tk,mk);
    int index = setATM.findEle(the);
    if(index == -1)
        return false;
    else 
        return true;
}

size_t DanhSachKhachHang::suDungATM(string tk, string mk){
    TheATM the(tk,mk);
    return setATM.findEle(the);
}

TheATM& DanhSachKhachHang::layThongTinTheATM(string idKhachHang){
    KhachHang temp(idKhachHang);
    size_t index = setKhachHang.findEle(temp);
    return setATM[index];
}

size_t DanhSachKhachHang::timKiemATM(string maThe){
    for(size_t i = 0; i != setATM.getCurr(); i++){
        if(setATM[i].layMaThe() == maThe)
            return i;
    }
    return -1;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
// THE ATM
TheATM::TheATM(const TheATM& the) : soDu(the.soDu), MaTaiKhoan(the.MaTaiKhoan), MatKhau(the.MatKhau){}

TheATM& TheATM::operator=(const TheATM& the){
    soDu = the.soDu;
    MaTaiKhoan = the.MaTaiKhoan;
    MatKhau = the.MatKhau;
    return (*this);
}

double TheATM::laySoDu(){
    return soDu;
}

bool TheATM::operator== (const TheATM& the){
    return (the.MaTaiKhoan == MaTaiKhoan && the.MatKhau == MatKhau); 
}

void TheATM::caiDatTheATM(){
    ofstream fout;
    fout.open("KHACHHANG.txt",ios::app);
    string line;

    cout << "Xin moi nhap ma the ATM : "; fflush(stdin);
    getline(cin,MaTaiKhoan);
    fout << MaTaiKhoan << endl;

    cout << "Xin moi nhap mat khau : "; fflush(stdin);
    getline(cin, MatKhau);
    fout << MatKhau << endl;

    cout << "So tien nap vao tai khoan : "; fflush(stdin);
    cin >> soDu;
    fout << to_string(soDu);

}

void TheATM::layThongTinThe(){
    cout << "- Ma so the ATM : " << MaTaiKhoan << endl;
    cout << "- So du trong the : " << to_string(soDu) << endl;
}

void TheATM::suaFile(double (*func)(double, double), double soTien){
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
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
                
                double d = stod(line);
                // Sử dụng con trỏ hàm tìm hàm cộng hoặc trừ hợp lí đối với trường hợp rút tiền hoặc nạp tiền
                d = func(d,soTien);
                soDu = d;
                fout << to_string(d) << endl;
                count += 2;
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

void TheATM::NapTien(double d){
    suaFile(add,d);
}

void TheATM::RutTien(double d){
    suaFile(sub,d);
}

void TheATM::chuyenTien(TheATM& the, double tien){
    suaFile(sub,tien);
    the.suaFile(add,tien);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// ONLINE BANKING

void OnlineBanking::caiDatOnlineBanking(string id){
    ofstream fout;
    fout.open("OnlineBanking.txt", ios::app);
    
    idKhachHang = id;
    fout << endl;
    fout << idKhachHang << endl;

    cout << "Nhap tai khoan : ";
    getline(cin, TenDangNhap);
    fout << TenDangNhap << endl;

    cout << "Nhap mat khau : ";
    getline(cin, MatKhau);
    fout << MatKhau;

 }

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH ONLINE BANKING

void DanhSachOnlineBanking::caiDatDanhSach(){
    ifstream fin;
    fin.open("OnlineBanking.txt", ios::in);
    string line;
    while(!fin.eof()){
        OnlineBanking banking;
        getline(fin, banking.idKhachHang);
        getline(fin,banking.TenDangNhap);
        getline(fin, banking.MatKhau);

        set.insert(banking);
    }  
    fin.close();
}

bool DanhSachOnlineBanking::kiemTraTaiKhoan(string tk, string mk){
    OnlineBanking banking(tk, mk);
    size_t index = set.findEle(banking);
    if(index == -1)
        return false;
    else 
        return true;
}

string DanhSachOnlineBanking::layIDKhachHang(string tk, string mk){
    OnlineBanking banking(tk,mk);
    size_t index = set.findEle(banking);
    return set[index].idKhachHang;
}

void DanhSachOnlineBanking::themOnlineBanking(string id){
    OnlineBanking banking;
    banking.caiDatOnlineBanking(id);
    set.insert(banking);
}

bool DanhSachOnlineBanking::kiemTraOnlineBanking(string id){
    for(size_t i = 0; i != set.getCurr(); i++){
        if(set[i].idKhachHang == id)
            return true;
    }
    return false;
}