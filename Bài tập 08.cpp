#include <bits/stdc++.h>
using namespace std;

class SoTietKiem {
    friend class QuanLySoTietKiem;
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

bool SoTietKiem::KiemTramaSo(string ma) {
    if(ma.size()>5) return false;
    for(char c : ma){
        if(!isalnum(c)) return false;
    }
    return true;
}

bool SoTietKiem::KiemTraLoaiTietKiem(string loai) {
    vector<string> loaiHopLe = {"ngan han", "dai han", "khong ky han"};
    for (auto i : loaiHopLe) {
        if (loai == i) {
            return true;
        }
    }
    return false;
}

bool SoTietKiem::KiemTraHoTen(string HoTen) {
    if (HoTen.size() > 30) return false;
    for (char c : HoTen) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool SoTietKiem::KiemTraCMND(string cmnd){
    if(cmnd.size()!=9 && cmnd.size()!=12) return false;
    for(char c : cmnd){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

bool SoTietKiem::KiemTraNgayHopLe(int ngay, int thang, int nam) {
    vector<int> ngayThang = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
        ngayThang[1] = 29;
    }
    return ((thang >= 1 && thang <= 12) && (ngay >= 1 && ngay <= ngayThang[thang - 1]) && (nam >=1));
}

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

void SoTietKiem::Xuat() {
    cout << "Ma so: " << maSo << " | Loai: " << loaiTietKiem << " | Ho ten: " << hoTenKH;
    cout << " | CMND: " << CMND << " | Ngay mo so: " << ngay <<"/"<< thang <<"/"<<nam;
    cout << " | So tien gui: " << fixed << setprecision(2) << soTienGui << endl;
}

class QuanLySoTietKiem {
private:
    int n;
    SoTietKiem *ds;
public:
    void Nhap();
    void Xuat();
    void SapXep(bool theoNgay = false);
    void TimKiem(string key);
    void LietKe(int tuNgay, int tuThang, int tuNam, int denNgay, int denThang, int denNam);
    ~QuanLySoTietKiem();
};

void QuanLySoTietKiem::Nhap() {
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    ds = new SoTietKiem[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void QuanLySoTietKiem::Xuat() {
    cout << "\nDanh sach so tiet kiem:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

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

QuanLySoTietKiem::~QuanLySoTietKiem() {
    delete[] ds;
}

int main() {
    QuanLySoTietKiem qlstk;
    qlstk.Nhap();
    qlstk.Xuat();

    qlstk.SapXep(false);
    qlstk.SapXep(true);
    string key;
    cout << "Nhap ma so hoac CMND can tim: ";
    cin >> key;
    qlstk.TimKiem(key);

    int tuNgay, tuThang, tuNam, denNgay, denThang, denNam;
    cout << "Nhap khoang thoi gian (tu ngay/thang/nam den ngay/thang/nam): ";
    cin >> tuNgay >> tuThang >> tuNam >> denNgay >> denThang >> denNam;
    qlstk.LietKe(tuNgay, tuThang, tuNam, denNgay, denThang, denNam);
    return 0;
}
