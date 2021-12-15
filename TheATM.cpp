#ifndef THEATM_CPP
#define THEATM_CPP

#include "TheATM.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------
// THE ATM

TheATM::TheATM(const TheATM& the) : soDu(the.soDu), MaTaiKhoan(the.MaTaiKhoan), 
                                    MatKhau(the.MatKhau), idKhachHang(the.idKhachHang), ls(the.ls){}

TheATM& TheATM::operator =(const TheATM& the){
    soDu = the.soDu;
    MaTaiKhoan = the.MaTaiKhoan;
    MatKhau = the.MatKhau;
    idKhachHang = the.idKhachHang;
    ls = the.ls;
    return (*this);
}

double TheATM::laySoDu(){
    return soDu;
}

bool TheATM::operator ==(const TheATM& the){
    return (the.MaTaiKhoan == MaTaiKhoan && the.MatKhau == MatKhau); 
}

void TheATM::xoaTheATM(){
    for(int i = 0; i < ls.getCurr(); i++){
        ls[i].xoaLichSuGiaoDich();
    }
    ls.deleteList();
}

void TheATM::caiDatTheATM(){
    ofstream fout;
    fout.open("KHACHHANG.txt",ios::app);
    string line;

    cout << "\t\tXin mời nhập mã thẻ ATM: "; fflush(stdin);
    getline(cin,MaTaiKhoan);
    fout << MaTaiKhoan << endl;

    char s[50];
    cout << "\t\tXin mời nhập mật khẩu: "; fflush(stdin);
    getpassword(s,50); MatKhau = s; fflush(stdin);
    fout << MatKhau << endl;

    cout << "\t\tSố tiền nạp vào tài khoản: "; fflush(stdin);
    cin >> soDu;
    fout << to_string(soDu);

}

void TheATM::layThongTinThe() const{
    cout << "\t\t- Mã thẻ ATM: " << MaTaiKhoan << endl;
    cout << "-\t\t Số dư trong thẻ: " << to_string(soDu) << endl;
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

void TheATM::NapTien(double d, string nd){
    suaFile(add,d);
    string maGD = "#" + to_string(soLuongGiaoDich);
    LichSuGiaoDich lsu(maGD,nd,MaTaiKhoan);
    ghiFile(lsu);
    ls.insert(lsu);
}

void TheATM::RutTien(double d, string nd){
    suaFile(sub,d);
    string maGD = "#" + to_string(soLuongGiaoDich);
    LichSuGiaoDich lsu(maGD,nd,MaTaiKhoan);
    ghiFile(lsu);
    ls.insert(lsu);
}

void TheATM::chuyenTien(TheATM& the, double tien){
    suaFile(sub,tien);
    the.suaFile(add,tien);
    string maGD = "#" + to_string(soLuongGiaoDich);
    string maThe = the.layMaThe();

    string nd = "Chuyển tiền sang tài khoản có mã thẻ " + maThe + " với số tiền : " + to_string(tien);
    string nd2 = "Nhận tiền từ tài khoản có mã thẻ " + MaTaiKhoan + " với số tiền : " + to_string(tien);

    LichSuGiaoDich lsu(maGD,nd,MaTaiKhoan);
    ghiFile(lsu);
    ls.insert(lsu);

    maGD = "#" + to_string(soLuongGiaoDich);
    LichSuGiaoDich ls1(maGD, nd2, maThe);
    ghiFile(ls1);
    the.ls.insert(ls1);
}

void TheATM::inLichSuGiaoDich(){
    for(int i = 0; i < ls.getCurr(); i++)
        cout << ls[i] << endl;
}

void TheATM::caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich& ds){
    for(int i = 0; i < ds.ls.getCurr(); i++){
        if(ds.ls[i].layMaTaiKhoan() == MaTaiKhoan){
            ls.insert(ds.ls[i]);
        }
    }
}

#endif
