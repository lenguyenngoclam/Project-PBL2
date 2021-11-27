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
    the = new TheATM();
}

KhachHang::KhachHang(const KhachHang &kh) : ThongTinCaNhan(kh) {
    idKhachHang = kh.idKhachHang;
    the = new TheATM();
    (*the) = *(kh.the);
}

KhachHang &KhachHang::operator =(const KhachHang &kh) {
    if(*this == kh)
        return *this;
    ThongTinCaNhan::operator =(kh);
    idKhachHang = kh.idKhachHang;
    delete the;
    the = new TheATM();
    *the = *(kh.the);
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
        TheATM theAtm = TheATM(tk,mk,d,temp.idKhachHang);

        temp.the = new TheATM();
        *(temp.the) = theAtm;

        setKhachHang.insert(temp);

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

void DanhSachKhachHang::taoTaiKhoanKhachHang(){

    KhachHang temp;
    temp.CaiDatThongTin();

    TheATM the;
    the.caiDatTheATM();

    the.idKhachHang = temp.idKhachHang;
    temp.the = new TheATM();
    *(temp.the) = the;

    setKhachHang.insert(temp);

    khachHang_count_line += 8;
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
    size_t index = timKiemATM(tk,mk);
    if(index == -1)
        return false;
    else 
        return true;
}

TheATM& DanhSachKhachHang::layThongTinTheATM(string idKhachHang){
    KhachHang temp(idKhachHang);
    size_t index = setKhachHang.findEle(temp);
    return *(setKhachHang[index].the);
}

TheATM& DanhSachKhachHang::layThongTinTheATM(string tk, string mk){
    size_t index = timKiemATM(tk,mk);

    return *(setKhachHang[index].the);
}

size_t DanhSachKhachHang::timKiemATM(string tk, string mk){
    TheATM the(tk,mk);
    size_t index;
    for(index = 0; index < setKhachHang.getCurr(); index++){
        if(*(setKhachHang[index].the) == the)
            return index;
    }
    return -1;
}

size_t DanhSachKhachHang::timKiemATM(string maThe){
    for(size_t index = 0; index < setKhachHang.getCurr(); index++){
        if(setKhachHang[index].the->layMaThe() == maThe)
            return index;
    }
    return -1;
}

size_t DanhSachKhachHang::timKiemKhachHang(string id){
    KhachHang temp(id);
    size_t index = setKhachHang.findEle(temp);
    return index;
}

void DanhSachKhachHang::caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich& ds){
    for(size_t i = 0; i < setKhachHang.getCurr(); i++){
        setKhachHang[i].the -> caiDatLichSuGiaoDich(ds);
    }
}


// ----------------------------------------------------------------------------------------------------------------------------------------------
// THE ATM
TheATM::TheATM(const TheATM& the) : soDu(the.soDu), MaTaiKhoan(the.MaTaiKhoan), 
                                    MatKhau(the.MatKhau), idKhachHang(the.idKhachHang), set(the.set){}

TheATM& TheATM::operator=(const TheATM& the){
    soDu = the.soDu;
    MaTaiKhoan = the.MaTaiKhoan;
    MatKhau = the.MatKhau;
    idKhachHang = the.idKhachHang;
    set = the.set;
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
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file NHANVIEN.txt và đổi tên file temp thành NHANVIEN
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
    for(int i = 0; i < ds.set.getCurr(); i++){
        if(ds.set[i].layMaTaiKhoan() == MaTaiKhoan)
            set.insert(ds.set[i]);
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// LICH SU GIAO DICH

ostream& operator<<(ostream& os, const LichSuGiaoDich& ls){
    cout << "Mã giao dịch : " << ls.maGiaoDich << endl;
    cout << "Nội dung giao dịch : " << ls.noiDung;
    return os;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------
// DANH SACH LICH SU GIAO DICH

void DanhSachLichSuGiaoDich::caiDatDanhSach(){
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);

    string line;
    lichsu_count_line++;
    getline(fin, line);
    while(getline(fin, line)){
        LichSuGiaoDich temp;
        temp.maGiaoDich = line;
        getline(fin, temp.noiDung);
        getline(fin, temp.maTaiKhoan);

        set.insert(temp);
        lichsu_count_line += 3;
    }

    fin.close();
}

