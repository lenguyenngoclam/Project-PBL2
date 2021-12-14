#include <iostream>
#include <fstream>

using namespace std;

#include "NhanVien.cpp"
#include "ViDienTu.cpp"
#include "include.h"

int main(){

    DanhSachTaiKhoanNhanVien dsTaiKhoan;
    DanhSachKhachHang dsKhachHang;
    DanhSachNhanVien dsNhanVien;
    DanhSachLichSuGiaoDich dsLichSu;
    DanhSachViDienTu dsVi;
    dsLichSu.caiDatDanhSach();
    dsNhanVien.CaiDatDanhSach();
    dsKhachHang.CaiDatDanhSach();
    dsTaiKhoan.caiDatDanhSach();
    dsVi.caiDatDanhSach();

    dsKhachHang.caiDatLichSuGiaoDich(dsLichSu);

    string tk = "0962814899";
    string mk = "123456";

    cout << vi_count_line << endl;

    // Kiểm tra đăng nhập
    /*
    while(dsVi.kiemTraDangNhap(tk,mk)){
        string choice;
        cin >> choice;
        fflush(stdin);
        if(choice == "c")
            break;
        else {

        }
    }
    

    // Chức năng thêm liên kết cho ví
    
    ViDienTu& vi = dsVi.suDungVi(tk,mk);
    string IDAtm = "102200267";
    size_t index = dsKhachHang.timKiemATM(IDAtm);
    TheATM& the = dsKhachHang.getListKhachHang()[index].layThongTinThe();
    vi.themLienKetTheATM(the);
    


    // Rút tiền và chuyển tiền
    
    ViDienTu& vi = dsVi.suDungVi(tk,mk);
    vi.napTien(dsKhachHang);
    vi.rutTien(dsKhachHang);
    

    // Nạp tiền vào ví
    
    ViDienTu& vi = dsVi.suDungVi(tk,mk);
    string IDVi = "0357751719";
    size_t index = dsVi.suDungVi(IDVi);
    if(index != -1){
        ViDienTu& viCanChuyen = dsVi.getListVi()[index];
        vi.chuyenTienDenVi(viCanChuyen, 10000);
    }
    */

    //Chuyển tiền vào thẻ
    /*
    string IDAtm = "111";
    ViDienTu& vi = dsVi.suDungVi(tk,mk);
    size_t index = dsKhachHang.timKiemATM(IDAtm);
    TheATM& the = dsKhachHang.getListKhachHang()[index].layThongTinThe();
    vi.chuyenTienDenThe(the, 10000); 
    */


    //Xoá khách hàng
    /*
    string idKhachHang = "KH7";
    size_t index = dsKhachHang.timKiemKhachHang(idKhachHang);
    dsKhachHang.getListKhachHang()[index].xoaKhachHang();
    dsLichSu.capNhatDanhSach();
    dsKhachHang.capNhatDanhSach();
    dsKhachHang.caiDatLichSuGiaoDich(dsLichSu);
    */

    //Gỡ liên kết ATM
    /*
    string choice;
    ViDienTu& vi = dsVi.suDungVi(tk,mk);
    cout << vi.getList();
    cout << "Chọn thẻ muốn gỡ : " ; fflush(stdin); 
    getline(cin,choice);
    vi.goLienKetTheATM(choice);
    */


    return 0;
}