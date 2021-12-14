#include <iostream>
#include "ViDienTu.h"

using namespace std;

ViDienTu& ViDienTu::operator =(const ViDienTu& vi){
    TaiKhoan::operator=(vi);
    lsID = vi.lsID;
    tongSoDu = vi.tongSoDu;
    return (*this);
}

void ViDienTu::suaFile(double (*func)(double, double), double soTien){
    ifstream fin;
    fin.open("ViDienTu.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file ViDienTu.txt và đổi tên file temp thành ViDienTu
    ofstream fout;
    fout.open("temp.txt", ios::app);
    
    string line;
    int count = 1;
    while(getline(fin, line)){
        if(count == vi_count_line) fout << line;
        else {
            fout << line << endl;
            count++;
        }

        if(line == TenDangNhap){
            getline(fin,line);
            fout << line << endl;
            count++;

            getline(fin,line);
            int soLuongATM = stoi(line);
            fout << to_string(soLuongATM) << endl;
            count++;

            for(int i = 1; i <= soLuongATM; i++){
                getline(fin,line);
                fout << line << endl;
                count++;
            }
            
            getline(fin,line);
            double temp = (*func)(stod(line),soTien);

            if(count == vi_count_line) fout << to_string(temp);
            else fout << to_string(temp) << endl;
            count++;
        }
    }

    fin.close();
    fout.close();

    remove("ViDienTu.txt");
    rename("temp.txt","ViDienTu.txt"); 
}

void ViDienTu::themLienKetTheATM(TheATM& the){
    ifstream fin;
    fin.open("ViDienTu.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file ViDienTu.txt và đổi tên file temp thành ViDienTu
    ofstream fout;
    fout.open("temp.txt", ios::app);

    lsID.insert(the.layMaThe());
    vi_count_line++;

    string line;
    int count = 1;
    while(getline(fin,line)){
        if(count == vi_count_line) 
            fout << line;
        else {
            fout << line << endl;
            count++;
        }

        if(line == TenDangNhap){
            getline(fin,line);
            fout << line << endl;
            count++;
            getline(fin,line);
            int soLuongATM = stoi(line);
            soLuongATM++;
            fout << to_string(soLuongATM) << endl;
            count++;

            for(int i = 1; i <= soLuongATM - 1; i++){
                getline(fin,line);
                fout << line << endl;
                count++;
            }

            fout << the.layMaThe() << endl;
            count++;

            getline(fin,line);
            if(count == vi_count_line) 
                fout << line;
            else 
                fout << line << endl;
            count++;
        }
    }

    fin.close();
    fout.close();

    remove("ViDienTu.txt");
    rename("temp.txt","ViDienTu.txt"); 

}

void ViDienTu::rutTien(DanhSachKhachHang& ds){
    cout << lsID << endl;
    string choice;
    cout << "\t\tChọn thẻ muốn rút tiền về (Nhập mã thẻ) : "; cin >> choice;
    size_t index = ds.timKiemATM(choice);
    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();
    string soTien;
    cout << "\t\tSố tiền muốn rút = "; cin >> soTien;
    if(stod(soTien) > tongSoDu)
        cout << "\t\tSố dư quý khách không đủ!" << endl;
    else {
        the.NapTien(stod(soTien), "\t\tRút tiền về tài khoản từ ví điện tử với số tiền : " + soTien);
        suaFile(sub,stod(soTien));
    }
}

void ViDienTu::napTien(DanhSachKhachHang& ds){
    cout << lsID << endl;
    string choice;
    cout << "\t\tChọn thẻ muốn sử dụng để nạp tiền vào ví (Nhập mã thẻ) : "; cin >> choice; 
    size_t index = ds.timKiemATM(choice);
    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();

    string soTien;
    cout << "\t\tSố tiền muốn nạp = "; cin >> soTien;
    if(stod(soTien) > the.laySoDu())
        cout << "Không đủ số dư trong thẻ" << endl;
    else {
        the.RutTien(stod(soTien), "\t\tNạp tiền vào ví điện tử từ tài khoản với số tiền : " + soTien);
        suaFile(add,stod(soTien));
    }    
}

void ViDienTu::chuyenTienDenThe(TheATM& the, double soTien){
    the.NapTien(soTien, "\t\tTiền được chuyển từ ví điện tử " + TenDangNhap + " với số tiền : " + to_string(soTien));
    suaFile(sub,soTien);
}

void ViDienTu::chuyenTienDenVi(ViDienTu& vi, double soTien){
    vi.suaFile(add,soTien);
    suaFile(sub,soTien);
}

void ViDienTu::caiDatVi(){
    ofstream fout;
    fout.open("ViDienTu.txt",ios::app);
    string line;
    
    fout << endl;

    cout << "\t\tNhập tên đăng nhập : "; fflush(stdin);
    getline(cin, TenDangNhap);
    fout << TenDangNhap << endl;

    cout << "\t\tNhập mật khẩu : "; fflush(stdin);
    getline(cin, MatKhau);
    fout << MatKhau << endl;

    fout << "0" << endl;
    fout << "0.0";

    fout.close();
}

bool ViDienTu::operator ==(const ViDienTu& rhs){
    return (rhs.TenDangNhap == TenDangNhap && rhs.MatKhau == MatKhau);
}

// ------------------------------------------------------------------------------------------------------------------------------
// DANH SACH VI DIEN TU

void DanhSachViDienTu::caiDatDanhSach(){
    ifstream fin;
    fin.open("ViDienTu.txt", ios::in);

    string line;

    while(!fin.eof()){
        string tk, mk;
        getline(fin, tk);
        getline(fin, mk);

        ViDienTu vi(tk,mk);

        getline(fin,line);
        string number_of_atm = line;
        vi_count_line++;

        for(int i = 1; i <= stoi(number_of_atm); i++){
            string idATM;
            getline(fin,idATM);
            vi.lsID.insert(idATM);
        }

        getline(fin,line);
        vi.tongSoDu = stod(line);

        lsViDienTu.insert(vi);

        vi_count_line += 2 + stoi(number_of_atm) + 1;
    }

    fin.close();
}

void DanhSachViDienTu::taoTaiKhoan(){
    ViDienTu vi;
    vi.caiDatVi();
    lsViDienTu.insert(vi);
}

bool DanhSachViDienTu::kiemTraDangNhap(string tk, string mk){
    ViDienTu vi(tk,mk);
    size_t index = lsViDienTu.findEle(vi);
    if(index == -1)
        return false;
    else
        return true;
}

ViDienTu& DanhSachViDienTu::suDungVi(string tk, string mk){
    ViDienTu vi(tk,mk);
    size_t index = lsViDienTu.findEle(vi);
    return lsViDienTu[index];
}

size_t DanhSachViDienTu::suDungVi(string id){
    int index = 0;
    for(index = 0; index < lsViDienTu.getCurr(); index++){
        if(lsViDienTu[index].layTaiKhoan() == id)
            break;
    }

    if(index < lsViDienTu.getCurr())
        return index;
    else 
        return -1;
}
