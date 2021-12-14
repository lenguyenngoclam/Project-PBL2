#include <iostream>
#include "ViDienTu.h"

using namespace std;

ViDienTu& ViDienTu::operator=(const ViDienTu& vi){
    TaiKhoan::operator=(vi);
    lsID = vi.lsID;
    tongSoDu = vi.tongSoDu;
    return (*this);
}

void ViDienTu::suaFile(double (*func)(double, double), double soTien){
    ifstream fin;
    fin.open("ViDienTu.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file KHACHHANG.txt và đổi tên file temp thành KHACHHANG
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
            tongSoDu = temp;

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

void ViDienTu::goLienKetTheATM(string maThe){
    ifstream fin;
    fin.open("ViDienTu.txt", ios::in);
    // Viết vào một file tạm là temp.txt sau đó sẽ xoá file ViDienTu.txt và đổi tên file temp thành ViDienTu
    ofstream fout;
    fout.open("temp.txt", ios::app);

    lsID.erase(maThe);

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

            string number_atm;
            getline(fin,number_atm);
            int soLuongATM = stoi(number_atm);
            string arr[soLuongATM];

            for(int i = 1; i <= stoi(number_atm); i++){
                getline(fin,line);
                arr[i - 1] = line;
                if(line == maThe){
                    vi_count_line--;
                    soLuongATM--;
                }
            }

            fout << to_string(soLuongATM) << endl;
            count++;
            for(int i = 1; i <= stoi(number_atm); i++){
                if(arr[i - 1] != maThe){
                    fout << arr[i - 1] << endl;
                    count++;
                }
            }

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
    cout << "Chọn thẻ muốn rút tiền về (Nhập mã thẻ) : "; cin >> choice;
    size_t index = ds.timKiemATM(choice);
    if(index == -1){
        cout << "Thẻ không còn tồn tại";
        goLienKetTheATM(choice);
        return;
    }
    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();
    string soTien;
    cout << "Số tiền muốn rút = "; cin >> soTien;
    if(stod(soTien) > tongSoDu)
        cout << "Không đủ số dư" << endl;
    else {
        the.NapTien(stod(soTien), "Nạp tiền vào tài khoản từ ví điện tử với số tiền : " + soTien);
        suaFile(sub,stod(soTien));
    }
}

void ViDienTu::napTien(DanhSachKhachHang& ds){
    cout << lsID << endl;
    string choice;
    cout << "Chọn thẻ muốn sử dụng để nạp tiền vào ví (Nhập mã thẻ) : "; cin >> choice; 
    size_t index = ds.timKiemATM(choice);
    if(index == -1){
        cout << "Thẻ không còn tồn tại";
        goLienKetTheATM(choice);
        return;
    }
    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();

    string soTien;
    cout << "Số tiền muốn nạp = "; cin >> soTien;
    if(stod(soTien) > the.laySoDu())
        cout << "Không đủ số dư trong thẻ" << endl;
    else {
        the.RutTien(stod(soTien), "Rút tiền từ tài khoản để nạp vào ví điện tử với số tiền : " + soTien);
        suaFile(add,stod(soTien));
    }    
}

void ViDienTu::chuyenTienDenThe(TheATM& the, double soTien){
    the.NapTien(soTien, "Tiền được chuyển từ ví điện tử " + TenDangNhap + " với số tiền : " + to_string(soTien));
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

    cout << "Nhập tên đăng nhập : "; fflush(stdin);
    getline(cin, TenDangNhap);
    fout << TenDangNhap << endl;

    cout << "Nhập mật khẩu : "; fflush(stdin);
    getline(cin, MatKhau);
    fout << MatKhau << endl;

    fout << "0" << endl;
    fout << "0.0";

    fout.close();
}

bool ViDienTu::operator==(const ViDienTu& rhs){
    return (rhs.TenDangNhap == TenDangNhap && rhs.MatKhau == MatKhau);
}

// ------------------------------------------------------------------------------------------------------------------------------
// DANH SACH VI DIEN TU

void DanhSachViDienTu::capNhatDanhSach(){
    ls.deleteList();
    caiDatDanhSach();
}

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

        ls.insert(vi);

        vi_count_line += 2 + stoi(number_of_atm) + 1;
    }

    fin.close();
}

void DanhSachViDienTu::taoTaiKhoan(){
    ViDienTu vi;
    vi.caiDatVi();
    ls.insert(vi);
}

bool DanhSachViDienTu::kiemTraDangNhap(string tk, string mk){
    ViDienTu vi(tk,mk);
    size_t index = ls.findEle(vi);
    if(index == -1)
        return false;
    else
        return true;
}

ViDienTu& DanhSachViDienTu::suDungVi(string tk, string mk){
    ViDienTu vi(tk,mk);
    size_t index = ls.findEle(vi);
    return ls[index];
}

size_t DanhSachViDienTu::suDungVi(string id){
    int index = 0;
    for(index = 0; index < ls.getCurr(); index++){
        if(ls[index].layTaiKhoan() == id)
            break;
    }

    if(index < ls.getCurr())
        return index;
    else 
        return -1;
}
