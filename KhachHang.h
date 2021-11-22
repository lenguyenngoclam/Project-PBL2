#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"

using namespace std;

class KhachHang;

string LaySoLuongKhachHang() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_KhachHang = LaySoLuongKhachHang();
int soLuong = stoi(number_KhachHang);

class TheATM{
    private :
        string MaTaiKhoan;
        string MatKhau;
        double soDu;
    public :    
        TheATM(string tk, string mk) : MaTaiKhoan(tk), MatKhau(mk) {};
        TheATM(string tk, string mk, double d) : soDu(d), MatKhau(mk), MaTaiKhoan(tk){};
        TheATM() : soDu(0), MatKhau(""), MaTaiKhoan("") {};

        TheATM(const TheATM&);

        TheATM& operator=(const TheATM& the);

        void NapTien(double soTien);
        void RutTien(double );
        double laySoDu();
        string layMaThe() { return MaTaiKhoan; }

        //Hàm thành viên có tác dụng ghi lại tất cả các dòng trong file KHACHHANG.txt nhưng thay đổi số dư của thẻ dựa trên con trỏ hàm
        void suaFile(double (*func)(double, double), double soTien);

        //Ghi dữ liệu người dùng nhập vào file 
        void caiDatTheATM();
        //Hiển thị mã tài khoản và số dư của thẻ
        void layThongTinThe();
        //Chuyển tiền cho thẻ ATM khác
        void chuyenTien(TheATM& maThe, double tien);

        friend class KhachHang;

        bool operator==(const TheATM& the);
};

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
    public :
        KhachHang() {
            ThongTinCaNhan();
        }
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);
        KhachHang(string id) : idKhachHang(id), ThongTinCaNhan() {};

        ~KhachHang() override = default;

        KhachHang(const KhachHang &kh);
        KhachHang &operator =(const KhachHang &kh);

        string LaySoLuong();

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;

        //Ghi thông tin do người dùng nhập vào file
        void CaiDatThongTin();

        string layIdKhachHang(){ return idKhachHang; }

        bool operator ==(const KhachHang& rhs) const;

        friend class DanhSachKhachHang;
};

class DanhSachKhachHang{
    private:
        //Cùng 1 index sẽ là khách hàng ứng với thẻ ATM của người đó
        Set<KhachHang> setKhachHang;
        Set<TheATM> setATM;
    public:
        DanhSachKhachHang() {
            setKhachHang = Set<KhachHang>(soLuong);
            setATM = Set<TheATM>(soLuong);
        }
        ~DanhSachKhachHang() = default;
        
        //Đọc dữ liệu ra từ file và lưu vào set
        void CaiDatDanhSach();
        //In danh sách khách hàng
        void InDanhSach();
        //Tìm kiếm khách hàng dựa trên id của khách hàng
        void TimKiemKhachHang(string id);
        //Trong hàm này sẽ gọi caiDatThongTin của ATM và khách hàng để ghi vào file sau đó insert ATM và khách hàng vào set tương ứng
        void taoTaiKhoanKhachHang();
        //Sửa thông tin khách hàng dựa trên id
        void suaThongTinKhachHang(string id);

        //Kiểm tra tài khoản ATM có hợp lệ không
        bool kiemTraTheATM(string, string);
        //Sử dụng tài khoản và mật khẩu và trả về index của ATM đó trong setATM
        size_t suDungATM(string, string);
        //Trả về thẻ ATM sử dụng idKhachHang
        TheATM& layThongTinTheATM(string idKhachHang);
        //Trả về index trong set dựa trên mã thẻ cung cấp
        size_t timKiemATM(string maThe);

        Set<TheATM>& getSetATM(){ return setATM; }
        Set<KhachHang>& getSetKhachHang(){ return setKhachHang; }

        friend class KhachHang;
};

class OnlineBanking : public TaiKhoan{
    private :   
        string idKhachHang;
    public :
        OnlineBanking() : TaiKhoan(), idKhachHang("") {};
        OnlineBanking(string tk, string mk) : TaiKhoan(tk,mk), idKhachHang("") {}
        OnlineBanking(string id, string tk, string mk) : TaiKhoan(tk,mk), idKhachHang(id) {}

        OnlineBanking(const OnlineBanking& rhs) : TaiKhoan(rhs.TenDangNhap, rhs.MatKhau), idKhachHang(rhs.idKhachHang) {}

        OnlineBanking& operator=(const OnlineBanking& rhs){
            idKhachHang = rhs.idKhachHang;
            TenDangNhap = rhs.TenDangNhap;
            MatKhau = rhs.MatKhau;
            return (*this);
        }

        ~OnlineBanking() override = default;

        bool operator==(const OnlineBanking& rhs){
            return (TenDangNhap == rhs.TenDangNhap && MatKhau == rhs.MatKhau);
        }

        void caiDatOnlineBanking(string id);

        friend class DanhSachOnlineBanking;
};

class DanhSachOnlineBanking{
    private :
        Set<OnlineBanking> set;
    public :
        DanhSachOnlineBanking() : set(1) {};

        ~DanhSachOnlineBanking() = default;

        void caiDatDanhSach();
        bool kiemTraTaiKhoan(string , string);
        //Lấy idkhachhang dựa trển tài khoản mật khẩu của online banking
        string layIDKhachHang(string, string);
        //Kiểm tra idKhachHang này đã có online banking hay chưa
        bool kiemTraOnlineBanking(string id);
        
        void themOnlineBanking(string id);
};  

#endif
