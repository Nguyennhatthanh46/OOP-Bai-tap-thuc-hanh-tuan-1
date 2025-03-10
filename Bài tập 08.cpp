#include <bits/stdc++.h>
using namespace std;

class SoTietKiem {
    friend class QuanLySoTietKiem; // Cho phép lớp QuanLySoTietKiem truy cập trực tiếp vào các thành viên private
private:
    string maSo, loaiTietKiem, hoTenKH;
    int ngay, thang, nam;
    string CMND;
    double soTienGui;
public:
    void Nhap();
    void Xuat();
    bool KiemTramaSo(string ma);
    bool KiemTraLoaiTietKiem(string loai);
    bool KiemTraHoTen(string HoTen);
    bool KiemTraCMND(string cmnd);
    bool KiemTraNgayHopLe(int ngay, int thang, int nam);
};
//Khai báo lớp SoTietKiem để quản lý thông tin sổ tiết kiểm của người dùng. 
//Các thuộc tính riêng tư như mã sổ, loại tiết kiệm, họ tên khách hàng, ngày mở sổ, số CMND, số tiền gửi. 
//Các hàm theo tác nhập xuất và các hàm kiểm tra tính hợp lệ. 

bool SoTietKiem::KiemTramaSo(string ma) {
    if(ma.size()>5) return false;
    for(char c : ma){
        if(!isalnum(c)) return false;
    }
    return true;
}
// Hàm kiểm tra mã số hợp lệ (tối đa 5 ký tự, chỉ chứa chữ cái và số). Dùng string để xét các kí tự trong xâu. 

bool SoTietKiem::KiemTraLoaiTietKiem(string loai) {
    vector<string> loaiHopLe = {"ngan han", "dai han", "khong ky han"};
    for (auto i : loaiHopLe) {
        if (loai == i) {
            return true;
        }
    }
    return false;
}
// Hàm kiểm tra loại tiết kiệm hợp lệ (chỉ chấp nhận 3 loại). Dùng vecto kiểu string lưu giữ các loại tiêt kiệm. 

bool SoTietKiem::KiemTraHoTen(string HoTen) {
    if (HoTen.size() > 30) return false;
    for (char c : HoTen) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}
// Hàm kiểm tra họ tên hợp lệ (tối đa 30 ký tự, chỉ có chữ cái và dấu cách). Dùng string để xét các kí tự trong xâu.

bool SoTietKiem::KiemTraCMND(string cmnd){
    if(cmnd.size()!=9 && cmnd.size()!=12) return false;
    for(char c : cmnd){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}
// Hàm kiểm tra CMND hợp lệ (phải có 9 hoặc 12 chữ số). Và cũng duyệt string để kiểm tra điều kiện toàn số trong xâu kí tự. 

bool SoTietKiem::KiemTraNgayHopLe(int ngay, int thang, int nam) {
    vector<int> ngayThang = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
        ngayThang[1] = 29;//Xét năm nhuận, cả tháng 2. 
    }
    return ((thang >= 1 && thang <= 12) && (ngay >= 1 && ngay <= ngayThang[thang - 1]) && (nam >=1));
}
// Hàm kiểm tra ngày tháng năm hợp lệ (xét cả năm nhuận)

void SoTietKiem::Nhap() {
    cin.ignore();
    do {
        cout << "Nhap Ma So: ";
        getline(cin, maSo);
    } while (!KiemTramaSo(maSo));

    do {
        cout << "Nhap loai tiet kiem (ngan han, dai han, khong ky han): ";
        getline(cin, loaiTietKiem);
    } while (!KiemTraLoaiTietKiem(loaiTietKiem));

    do {
        cout << "Nhap ho Ten: ";
        getline(cin, hoTenKH);
    } while (!KiemTraHoTen(hoTenKH));


    do {
        cout << "Nhap CMND: ";
        cin >> CMND;
    } while (!KiemTraCMND(CMND));

    do {
        cout << "Nhap ngay mo so: ";
        cin >> ngay >> thang >> nam;
    } while (!KiemTraNgayHopLe(ngay, thang, nam));

    do {
        cout << "Nhap so tien gui: ";
        cin >> soTienGui;
    } while (soTienGui <= 0);
}
// Hàm nhập thông tin sổ tiết kiệm. Nếu sai thì phải nhập lại thông qua vòng lặp. 
// Vòng lặp kiểm tra các hàm kiểm dữ kiện bên trên. Vòng lặp dừng khi điều kiện các hàm là đúng.

void SoTietKiem::Xuat() {
    cout << "Ma so: " << maSo << " | Loai: " << loaiTietKiem << " | Ho ten: " << hoTenKH;
    cout << " | CMND: " << CMND << " | Ngay mo so: " << ngay <<"/"<< thang <<"/"<<nam;
    cout << " | So tien gui: " << fixed << setprecision(2) << soTienGui << endl;
}
// Hàm xuất thông tin sổ tiết kiệm theo khung. 

class QuanLySoTietKiem {
private:
    int n; //Số phần tử của lớp SoTietKiem
    SoTietKiem *ds; //Mảng động danh sách lớp SoTietKiem
public:
    void Nhap();
    void Xuat();
    void SapXep(bool theoNgay = false);
    void TimKiem(string key);
    void LietKe(int tuNgay, int tuThang, int tuNam, int denNgay, int denThang, int denNam);
    ~QuanLySoTietKiem();
};
// Lớp quản lý danh sách sổ tiết kiệm. Chứ các hàm nhập, xuất, sắp xếp , tìm kiếm và liệt kê theo yêu cầu của khách hàng. 

void QuanLySoTietKiem::Nhap() {
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    ds = new SoTietKiem[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}
// Hàm nhập danh sách sổ tiết kiệm theo mảng. 

void QuanLySoTietKiem::Xuat() {
    cout << "\nDanh sach so tiet kiem:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
// Hàm xuất danh sách sổ tiết kiệm

void QuanLySoTietKiem::SapXep(bool theoNgay) {
    if (theoNgay)
        cout << "\nSap xep theo ngay mo so: \n";
    else
        cout << "\nSap xep theo so tien gui giam dan: \n";

    sort(ds, ds + n, [theoNgay](SoTietKiem a, SoTietKiem b) {
        return theoNgay ? (a.nam < b.nam || (a.nam == b.nam && (a.thang < b.thang || (a.thang == b.thang && a.ngay < b.ngay))))
                        : a.soTienGui > b.soTienGui;
    });
    Xuat();
}
// Hàm sắp xếp danh sách sổ tiết kiệm. Có thể lựa chọn theo 1 trong 2 cách hoặc cả 2 cách tùy theo người dùng.
// Dùng hàm sort để sắp xếp các thuộc tính theo ngày mở sổ, hoặc theo số tiền gửi. 
            
void QuanLySoTietKiem::TimKiem(string key) {
    cout << "\nKet qua tim kiem:\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].maSo == key || ds[i].CMND == key) {
            ds[i].Xuat();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay so tiet kiem nao voi tu khoa: " << key << endl;
    }
}
// Hàm tìm kiếm sổ tiết kiệm theo mã số hoặc CMND. Bằng cách duyệt chỉ số trong xâu kí tự. 

void QuanLySoTietKiem::LietKe(int tuNgay, int tuThang, int tuNam, int denNgay, int denThang, int denNam) {
    cout << "\nCac so tiet kiem mo tu " << tuNgay << "/" << tuThang << "/" << tuNam;
    cout << " den " << denNgay << "/" << denThang << "/" << denNam << ":\n";
    for (int i = 0; i < n; i++) {
        if ((ds[i].nam > tuNam || (ds[i].nam == tuNam && (ds[i].thang > tuThang || (ds[i].thang == tuThang && ds[i].ngay >= tuNgay)))) &&
            (ds[i].nam < denNam || (ds[i].nam == denNam && (ds[i].thang < denThang || (ds[i].thang == denThang && ds[i].ngay <= denNgay))))) {
            ds[i].Xuat();
        }

    }
}
// Hàm liệt kê các sổ tiết kiệm trong khoảng thời gian. Có mốc thời gian trước sau. Nếu có thì xuất ra kết quả của các lớp SoTietKiem trong khoang thoi gian do. 
// Hàm dùng vòng lặp và so sánh theo năm, tháng, ngày.

QuanLySoTietKiem::~QuanLySoTietKiem() {
    delete[] ds;
}
// Hàm hủy giải phóng bộ nhớ

int main() {
    QuanLySoTietKiem qlstk;
    qlstk.Nhap();
    qlstk.Xuat();
//Nhạp, xuất các thuộc tính của sổ tiết kiệm
    
    qlstk.SapXep(false);
    qlstk.SapXep(true);
//Thực hiện việc sắp xếp các sổ tiết kiệm
    string key;
    cout << "Nhap ma so hoac CMND can tim: ";
    cin >> key;
    qlstk.TimKiem(key);
//Tìm kiếm từ khóa để tìm sổ tiết kiệm tương ứng.
    
    int tuNgay, tuThang, tuNam, denNgay, denThang, denNam;
    cout << "Nhap khoang thoi gian (tu ngay/thang/nam den ngay/thang/nam): ";
    cin >> tuNgay >> tuThang >> tuNam >> denNgay >> denThang >> denNam;
    qlstk.LietKe(tuNgay, tuThang, tuNam, denNgay, denThang, denNam);
//Nhập các mốc thời gian trước và sau để xét xem có phù với với các lớp trong khoảng đó hay không. Nếu có thì xuất danh sách các lớp ra. 
    return 0;
}
