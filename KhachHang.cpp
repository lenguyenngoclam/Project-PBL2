#include "KhachHang.h"

using namespace std;

// ----------------------------------------------------------------------------------------------------------------------------------------------
// KHACH HANG

KhachHang::KhachHang(string id, string ten, string dc, string sdt, string t) : ThongTinCaNhan(ten,dc,sdt,t) {
    idKhachHang = id;
    the = new TheATM();
}

KhachHang::KhachHang(const KhachHang &kh) : ThongTinCaNhan(kh) {
    idKhachHang = kh.idKhachHang;
    if(the == NULL)
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
            ++count; 
            fout << line << endl;
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

void KhachHang::InThongTin() const{
    cout << "\t\t|" << setw(8) << idKhachHang << setw(6);
    ThongTinCaNhan::InThongTin();
}

void KhachHang::CaiDatThongTin()
{
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file KHACHHANG.txt và đổi tên file temp thành KHACHHANG
    ofstream fout;
    fout.open("temp.txt", ios::app);

    ThongTinCaNhan::CaiDatThongTin(); 
    
    string line;
    string a[] = {HoTen, Tuoi, DiaChi, SoDienThoai};
    string b[] = {this->HoTen, this->Tuoi, this->DiaChi, this->SoDienThoai};
    int count = 1;
    while(getline(fin, line)){
        if (count == 1) {
            string temp = "KH";
            soLuong++; 
            number_KhachHang = to_string(soLuong);
            idKhachHang = temp + number_KhachHang;

            fout << number_KhachHang << endl;
        } else {
            fout << line << endl;
        }
        count++;
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

void KhachHang::xoaKhachHang(){
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    ofstream fout;
    fout.open("temp.txt", ios::app);

    int count = 1;
    string line;
    getline(fin, line);
    fout << line << endl;
    count++;

    khachHang_count_line -= 8;
    string arr[8];
    while(getline(fin,line)){
        arr[0] = line;
        for(int i = 0; i < 7; i++){
            getline(fin,line);
            arr[i + 1] = line;
        }
        if(idKhachHang != arr[0]){
            for(int i = 0; i < 7; i++){
                fout << arr[i] << endl;
                count++;
            }
            if(count == khachHang_count_line)
                fout << arr[7];
            else 
                fout << arr[7] << endl;
            count++;
        }
    }    
    
    fin.close();
    fout.close();

    remove("KHACHHANG.txt");
    rename("temp.txt","KHACHHANG.txt");

    the -> xoaTheATM();
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

        *(temp.the) = theAtm;

        lsKhachHang.insert(temp);

        khachHang_count_line += 8;
    }
    fin.close();
}

ostream& operator <<(ostream& os, const KhachHang& kh){
    kh.InThongTin();
    return os;
}

void DanhSachKhachHang::InDanhSach(){
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Danh sách khách hàng ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    cout << "\t\t+-------------+----------------------------------+--------+---------------------------+-------------------+" << endl;
    cout << "\t\t|" << setw(7) << "ID" << setw(7) << "|" << setw(26) << "Họ và tên" << setw(13) << "|" << setw(8) << "Tuổi" << setw(3) << 
    "|" << setw(23) << "Địa chỉ" << setw(10) << "|" << setw(23) << "Số điện thoại" << setw(4) << "|" << endl;
    cout << "\t\t+-------------+----------------------------------+--------+---------------------------+-------------------+" << endl;
    for(size_t i = 0; i < lsKhachHang.getCurr(); i++)
        lsKhachHang[i].InThongTin();
}

void DanhSachKhachHang::taoTaiKhoanKhachHang(){

    KhachHang temp;
    temp.CaiDatThongTin();

    TheATM the;
    the.caiDatTheATM();
    themVaoFile("TenTheATM.txt",the.MaTaiKhoan);

    khachHang_count_line += 8;

    the.idKhachHang = temp.idKhachHang;
    temp.the = new TheATM();
    *(temp.the) = the;

    lsKhachHang.insert(temp);
}

void DanhSachKhachHang::suaThongTinKhachHang(string id){
    KhachHang temp(id);
    size_t index = lsKhachHang.findEle(temp);
    if(index == -1){
        cout << "\t\t-> Không tìm thấy khách hàng" << endl;
    } else {
        lsKhachHang[index].DoiThongTinCaNhan();
    }
}

bool DanhSachKhachHang::kiemTraTheATM(string tk, string mk){
    size_t index = timKiemATM(tk,mk);
    if(index == -1)
        return false;
    else 
        return true;
}

// Lấy thông tin theo stk & mk
TheATM& DanhSachKhachHang::layThongTinTheATM(string tk, string mk){
    size_t index = timKiemATM(tk,mk);

    return *(lsKhachHang[index].the);
}

// Lấy thông tin theo idKhachHang
TheATM& DanhSachKhachHang::layThongTinTheATM(string idKhachHang){
    KhachHang temp(idKhachHang);
    size_t index = lsKhachHang.findEle(temp);
    return *(lsKhachHang[index].the);
}

// Tìm kiếm theo stk & mk
size_t DanhSachKhachHang::timKiemATM(string tk, string mk){
    TheATM the(tk,mk);
    size_t index;
    for(index = 0; index < lsKhachHang.getCurr(); index++){
        if(*(lsKhachHang[index].the) == the)
            return index;
    }
    return -1;
}

// Tìm kiếm theo mã thẻ
size_t DanhSachKhachHang::timKiemATM(string maThe){
    for(size_t index = 0; index < lsKhachHang.getCurr(); index++){
        if(lsKhachHang[index].the->layMaThe() == maThe)
            return index;
    }
    return -1;
}

size_t DanhSachKhachHang::timKiemKhachHang(string id){
    KhachHang temp(id);
    size_t index = lsKhachHang.findEle(temp);
    return index;
}

void DanhSachKhachHang::caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich& ds){
    for(size_t i = 0; i < lsKhachHang.getCurr(); i++){
        lsKhachHang[i].the -> caiDatLichSuGiaoDich(ds);
    }
}
