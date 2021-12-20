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
    string choice;

    cout << "\t\tBạn muốn đổi ý? (c/n): "; fflush(stdin); getline(cin, choice);
    if (choice == "c") return;
    system("cls");

    kiemTraLienKetATM(ds);
    cout << "\n\t\t---- Danh sách thẻ ATM liên kết với ví điện tử ----" << endl;
    cout << lsID << endl;

    cout << "\t\tNhập mã thẻ muốn rút tiền về: ";
    fflush(stdin); getline(cin, choice);
    size_t index = ds.timKiemATM(choice);

    while (lsID.findEle(choice) == -1 || index == -1)
    {
        // Khi nhập sai
        if(lsID.findEle(choice) == -1)
            cout << "\t\tMã thẻ ATM không hợp lệ!" << endl;
        else {
            // Khi thẻ không còn tồn tại
            goLienKetTheATM(choice);
            cout << "\t\tMã thẻ ATM không còn tồn tại!" << endl;
            cout << "\n\t\t---- Danh sách các thẻ liên kết với ví điện tử ----" << endl;
            cout << lsID << endl;
        } 
        cout << "\t\tNhập lại mã thẻ ATM muốn nạp tiền: ";
        fflush(stdin); getline(cin, choice);
        index = ds.timKiemATM(choice);
    } 

    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();

    string soTien;
    cout << "\t\tSố tiền muốn rút = "; cin >> soTien;
    if(stod(soTien) > tongSoDu)
    {
        cout << "\t\tSố tiền quý khách không đủ!" << endl;
        cout << "\n\t\t"; system("pause"); system("cls");
    }
    else {
        the.NapTien(stod(soTien), "Rút tiền về tài khoản từ ví điện tử với số tiền : " + soTien);
        suaFile(sub,stod(soTien));
        string tmp = "Rút tiền thành công!";
        goodbye(tmp,30); cout << endl;
        cout << "\t\t-> Số tiền trong ví của bạn = " << to_string(laySoDu()) << endl << endl;
        cout << "\n\t\t"; system("pause"); system("cls");
    }
}

void ViDienTu::napTien(DanhSachKhachHang& ds){
    string choice;

    cout << "\t\tBạn muốn đổi ý? (c/n): "; fflush(stdin); getline(cin, choice);
    if (choice == "c") return;
    
    kiemTraLienKetATM(ds);
    cout << "\n\t\t---- Danh sách các thẻ liên kết với ví điện tử ----" << endl;
    cout << lsID << endl;

    cout << "\t\tNhập mã thẻ để nạp tiền vào ví: ";
    fflush(stdin); getline(cin, choice); 
    size_t index = ds.timKiemATM(choice);

    while (lsID.findEle(choice) == -1 || index == -1)
    {
        // Khi nhập sai
        if(lsID.findEle(choice) == -1)
            cout << "\t\tMã thẻ ATM không hợp lệ!" << endl;
        else {
            // Khi thẻ không còn tồn tại
            goLienKetTheATM(choice);
            cout << "\t\tMã thẻ ATM không còn tồn tại!" << endl;
            cout << "\n\t\t---- Danh sách các thẻ liên kết với ví điện tử ----" << endl;
            cout << lsID << endl;
        } 
        cout << "\t\tNhập lại mã thẻ ATM muốn nạp tiền: ";
        fflush(stdin); getline(cin, choice);
        index = ds.timKiemATM(choice);
    }

    TheATM& the = ds.getListKhachHang()[index].layThongTinThe();
    
    string soTien;
    cout << "\t\tSố tiền muốn nạp = "; cin >> soTien;
    suaFile(add,stod(soTien));
    the.RutTien(stod(soTien), "Rút tiền từ thẻ để nạp vào ví điện tử " + TenDangNhap + " với số tiền : " + soTien);
    string tmp = "Nạp tiền thành công!";
    goodbye(tmp,30); cout << endl;
    cout << "\t\t-> Số tiền trong ví của bạn = " << to_string(laySoDu()) << endl << endl;
    cout << "\n\t\t"; system("pause"); system("cls");
}    

void ViDienTu::chuyenTienDenThe(TheATM& the, double soTien){
    the.NapTien(soTien, "Tiền được chuyển từ ví điện tử " + TenDangNhap + " với số tiền : " + to_string(soTien));
    suaFile(sub,soTien);
}

void ViDienTu::chuyenTienDenVi(ViDienTu& vi, double soTien){
    vi.suaFile(add,soTien);
    suaFile(sub,soTien);
}

void ViDienTu::kiemTraLienKetATM(DanhSachKhachHang &ds)
{
    string IdATM;
    if (lsID.getCurr() == 0)
    {
        string noti = "(!) Ví của bạn chưa liên kết với thẻ ATM....."; goodbye(noti,30);

        cout << "\t\tNhập mã thẻ ATM muốn liên kết đến ví: "; 
        fflush(stdin); getline(cin, IdATM);
        size_t index = ds.timKiemATM(IdATM);

        while (index == -1)
        {
            cout << "\t\tMã thẻ ATM không hợp lệ !" << endl;
            cout << "\t\tNhập lại mã thẻ ATM muốn liên kết đến ví: ";
            fflush(stdin); getline(cin, IdATM);
            index = ds.timKiemATM(IdATM);
        }

        TheATM &the = (ds.getListKhachHang()[index]).layThongTinThe();
        themLienKetTheATM(the);
        cout << "\t\t-> Liên kết thẻ ATM thành công !" << endl;
    }
}

void ViDienTu::napTienDT(DanhSachKhachHang &ds,double soTien)
{
    string opt, choice, IdATM;
    size_t index = ds.timKiemATM(choice);

    cout << "\t\tBạn muốn đổi ý? (c/n): "; fflush(stdin); getline(cin, choice);
    if (choice == "c") return;
    system("cls");

    if (soTien < tongSoDu)
    {
        suaFile(sub,soTien);
        cout << "\t\tThanh toán thành công !" << endl;
        cout << "\t\tSố tiền trong ví của bạn = " << to_string(laySoDu()) << endl;
        cout << "\n\t\t"; system("pause"); system("cls");
    }
    else {
        string noti = "(!) Thẻ của bạn không đủ tiền....."; goodbye(noti,30);
        cout << "\t\t-> Bạn có muốn thanh toán bằng thẻ ATM? (c/n): ";
        fflush(stdin); getline(cin,opt);
        while (opt != "c" || opt != "n")
        {
            if (opt == "c") {
                kiemTraLienKetATM(ds);
                cout << "\n\t\t---- Danh sách các thẻ liên kết với ví điện tử ----" << endl;
                cout << lsID;
                cout << "\t\tNhập mã thẻ để thanh toán: ";
                fflush(stdin); getline(cin, choice); 
                size_t index = ds.timKiemATM(choice);
                
                while (lsID.findEle(choice) == -1 || index == -1)
                {
                    // Khi nhập sai
                    if(lsID.findEle(choice) == -1)
                        cout << "\t\tMã thẻ ATM không hợp lệ!" << endl;
                    else {
                        // Khi thẻ không còn tồn tại
                        goLienKetTheATM(choice);
                        cout << "\t\tMã thẻ ATM không còn tồn tại!" << endl;
                        cout << "\n\t\t---- Danh sách các thẻ liên kết với ví điện tử ----" << endl;
                        cout << lsID << endl;
                    } 
                    cout << "\t\tNhập lại mã thẻ ATM để thanh toán: ";
                    fflush(stdin); getline(cin, choice);
                    index = ds.timKiemATM(choice);
                }
                
                TheATM& the = ds.getListKhachHang()[index].layThongTinThe();
                the.RutTien(soTien, "Rút tiền từ thẻ để mua thẻ cào có giá: " + to_string(soTien));
                cout << "\n\t\t"; system("pause"); system("cls");
                break;
            }
            else if (opt == "n") {
                napTien(ds);
                suaFile(sub,soTien);
                cout << "\t\tThanh toán thành công !" << endl;
                cout << "\t\tSố tiền trong ví của bạn = " << to_string(laySoDu()) << endl;
                cout << "\n\t\t"; system("pause"); system("cls");
                break;
            }
            else {
                string noti = "Mời bạn chọn lại....."; 
                goodbye(noti,30);
                cout << "\n\t\t"; system("pause"); system("cls");
            }
        }
    }
}

void ViDienTu::caiDatVi(){
    ofstream fout;
    fout.open("ViDienTu.txt",ios::app);
    string line;
    
    fout << endl;

    cout << "\t\tNhập tên đăng nhập : "; fflush(stdin);
    getline(cin, TenDangNhap);

    while(timKiemTrongFile("TenViDienTu.txt",TenDangNhap) == true)
    {
        string noti = "Tên đăng nhập đã tồn tại....";
        goodbye(noti,30); cout << endl;
        cout << "\t\t~~~~~~~~~ Mời bạn nhập lại ~~~~~~~~~" << endl;
        cout << "\t\tNhập tên đăng nhập : "; 
        fflush(stdin); getline(cin, TenDangNhap);
    }

    fout << TenDangNhap << endl;
    themVaoFile("TenViDienTu.txt",TenDangNhap);

    char s[50];
    cout << "\t\tNhập mật khẩu : "; fflush(stdin);
    getpassword(s,50); MatKhau = s; fflush(stdin);
    fout << MatKhau << endl;

    fout << "0" << endl;
    tongSoDu = 0;
    fout << "0.0";

    vi_count_line += 4;
}

bool ViDienTu::operator ==(const ViDienTu& rhs){
    return (rhs.TenDangNhap == TenDangNhap && rhs.MatKhau == MatKhau);
}

// ------------------------------------------------------------------------------------------------------------------------------
// DANH SACH VI DIEN TU

void DanhSachViDienTu::capNhatDanhSach(){
    lsViDienTu.deleteList();
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

        lsViDienTu.insert(vi);

        vi_count_line += 2 + stoi(number_of_atm) + 1;
    }

    fin.close();
}

void DanhSachViDienTu::taoViDienTu(){
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
