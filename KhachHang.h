#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"
#include "TheATM.cpp"

using namespace std;

class DanhSachKhachHang;

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
        TheATM *the = new TheATM();
    public :
        KhachHang() = default;
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);
        KhachHang(string id) : idKhachHang(id), ThongTinCaNhan() {};

        ~KhachHang() override{
            delete the;
        }

        KhachHang(const KhachHang &kh);
        KhachHang &operator =(const KhachHang &kh);

        void xoaKhachHang();
        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;

        //Ghi thông tin do người dùng nhập vào file
        void CaiDatThongTin() override;

        string layIdKhachHang(){ return idKhachHang; }
        TheATM& layThongTinThe() { return *the; }

        bool operator ==(const KhachHang& rhs) const;

        friend class DanhSachKhachHang;
};

class DanhSachKhachHang{
    private:
        LinkedList<KhachHang> lsKhachHang;
    public:
        DanhSachKhachHang() = default;
        ~DanhSachKhachHang() = default;
        
        void capNhatDanhSach(){
            lsKhachHang.deleteList();
            CaiDatDanhSach();
        }
        // Đọc dữ liệu ra từ file và lưu vào set
        void CaiDatDanhSach();
        // In danh sách khách hàng
        void InDanhSach();
        // Trong hàm này sẽ gọi caiDatThongTin của ATM và khách hàng để ghi vào file sau đó insert ATM và khách hàng vào set tương ứng
        void taoTaiKhoanKhachHang();
        // Sửa thông tin khách hàng dựa trên id
        void suaThongTinKhachHang(string id);

        // Kiểm tra tài khoản ATM có hợp lệ không
        bool kiemTraTheATM(string, string);
        // Trả về thẻ ATM sử dụng idKhachHang
        TheATM& layThongTinTheATM(string idKhachHang);
        // Trả về thẻ ATM sử dụng tài khoản và mật khẩu
        TheATM& layThongTinTheATM(string tk, string mk);
        // Trả về index trong set dựa trên mã thẻ cung cấp
        size_t timKiemATM(string maThe);
        size_t timKiemATM(string tk, string mk);
        //Tìm kiếm khách hàng theo id
        size_t timKiemKhachHang(string id);

        void caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich&);

        LinkedList<KhachHang>& getListKhachHang(){ return lsKhachHang; }

        friend class KhachHang;
};
#endif
