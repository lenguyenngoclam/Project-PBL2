#ifndef KhachHang_h
#define KhachHang_h

#include <iostream>
#include <fstream>
#include <string>

#include "include.h"

using namespace std;

class KhachHang;
class DanhSachKhachHang;
class DanhSachLichSuGiaoDich;
class TheATM;

string LaySoLuongKhachHang() {
    ifstream fin;
    fin.open("KHACHHANG.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}
string LaySoLuongGiaoDich() {
    ifstream fin;
    fin.open("LichSuGiaoDich.txt", ios::in);
    string line;
    getline(fin, line);
    fin.close();
    return line;
}

string number_KhachHang = LaySoLuongKhachHang();
int soLuong = stoi(number_KhachHang);
string number_lichsu = LaySoLuongGiaoDich();
int soLuongGiaoDich = stoi(number_lichsu);

class LichSuGiaoDich{
    private :
        string maGiaoDich;
        string noiDung;
        string maTaiKhoan;
    public :
        LichSuGiaoDich(string ma = "", string nd = "", string mtk = "") : maGiaoDich(ma), noiDung(nd), maTaiKhoan(mtk){}
        LichSuGiaoDich(const LichSuGiaoDich& ls) : maGiaoDich(ls.maGiaoDich), noiDung(ls.noiDung), maTaiKhoan(ls.maTaiKhoan) {};

        ~LichSuGiaoDich() = default;

        LichSuGiaoDich& operator= (const LichSuGiaoDich& ls){
            maGiaoDich = ls.maGiaoDich;
            noiDung = ls.noiDung;
            maTaiKhoan = ls.maTaiKhoan;
            return (*this);
        } 

        bool operator==(const LichSuGiaoDich& rhs){
            return (maGiaoDich == rhs.maGiaoDich);
        }

        string layMaGiaoDich(){ return maGiaoDich; }
        string layMaTaiKhoan(){ return maTaiKhoan; }
        string layNoiDung() { return noiDung; }

        friend ostream& operator<<(ostream&, const LichSuGiaoDich&);
        friend class DanhSachLichSuGiaoDich;

};

class DanhSachLichSuGiaoDich{
    private :
        Set<LichSuGiaoDich> set;
    public :
        DanhSachLichSuGiaoDich() : set(soLuongGiaoDich) {};

        DanhSachLichSuGiaoDich& operator=(const DanhSachLichSuGiaoDich& rhs){
            set = rhs.set;
            return (*this);
        }

        void caiDatDanhSach();
        void themLichSuGiaoDich(LichSuGiaoDich& lsu){
            set.insert(lsu);
        }

        friend class TheATM;
};

class TheATM{
    private :
        string MaTaiKhoan;
        string MatKhau;
        double soDu;
        string idKhachHang;
        Set<LichSuGiaoDich> set;
    public :    
        TheATM(string tk, string mk) : MaTaiKhoan(tk), MatKhau(mk), soDu(0), idKhachHang("") {};
        TheATM(string tk, string mk, double d, string id) : soDu(d), MatKhau(mk), MaTaiKhoan(tk), idKhachHang(id){};
        TheATM() : soDu(0), MatKhau(""), MaTaiKhoan(""), idKhachHang("") {};

        TheATM(const TheATM&);

        TheATM& operator=(const TheATM& the);

        void NapTien(double soTien);
        void RutTien(double );
        double laySoDu();

        string layMaThe() { return MaTaiKhoan; }
        string layIDKhachHang() { return idKhachHang; }

        // Hàm thành viên có tác dụng ghi lại tất cả các dòng trong file KHACHHANG.txt nhưng thay đổi số dư của thẻ dựa trên con trỏ hàm
        void suaFile(double (*func)(double, double), double soTien);
        //Ghi lịch sử giao dịch vào file
        void ghiFile(LichSuGiaoDich& lsu);

        // Ghi dữ liệu người dùng nhập vào file 
        void caiDatTheATM();
        // Hiển thị mã tài khoản và số dư của thẻ
        void layThongTinThe();
        // Chuyển tiền cho thẻ ATM khác
        void chuyenTien(TheATM& maThe, double tien);
        //In lịch sử giao dịch
        void inLichSuGiaoDich();
        //Thêm lịch sử giao dịch tử file
        void caiDatLichSuGiaoDich(DanhSachLichSuGiaoDich&);

        friend class KhachHang;
        friend class DanhSachKhachHang;

        bool operator==(const TheATM& the);
};

class KhachHang : public ThongTinCaNhan{
    private :
        string idKhachHang;
        TheATM *the;
    public :
        KhachHang() {
            ThongTinCaNhan();
        }
        KhachHang(string id, string hoten, string diachi, string sodienthoai, string tuoi);
        KhachHang(string id) : idKhachHang(id), ThongTinCaNhan() {};

        ~KhachHang() override{
            delete the;
        }

        KhachHang(const KhachHang &kh);
        KhachHang &operator =(const KhachHang &kh);

        string LaySoLuong();

        void LayThongTinCaNhan() const override;
        void DoiThongTinCaNhan() override;

        //Ghi thông tin do người dùng nhập vào file
        void CaiDatThongTin();

        string layIdKhachHang(){ return idKhachHang; }
        TheATM& layThongTinThe() { return *the; }

        bool operator ==(const KhachHang& rhs) const;

        friend class DanhSachKhachHang;
};

class DanhSachKhachHang{
    private:
        // Cùng 1 index sẽ là khách hàng ứng với thẻ ATM của người đó
        Set<KhachHang> setKhachHang;
    public:
        DanhSachKhachHang() {
            setKhachHang = Set<KhachHang>(soLuong);
        }
        ~DanhSachKhachHang() = default;
        
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

        Set<KhachHang>& getSetKhachHang(){ return setKhachHang; }

        friend class KhachHang;
};
#endif
