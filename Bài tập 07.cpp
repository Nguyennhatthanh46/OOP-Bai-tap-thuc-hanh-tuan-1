#include <bits/stdc++.h>
using namespace std;

class ChuyenBay { 
    friend class QuanLyChuyenBay; // Cho phép lớp QuanLyChuyenBay truy cập các thành viên private
private:
    string maCB, noiDi, noiDen;
    int ngay, thang, nam, gio, phut;
public:
    void Nhap();
    void Xuat();
    bool KiemTraNgayHopLe(int ngay, int thang, int nam);
    bool KiemTraMaCB(string ma);
    bool KiemTraNoi(string noi);
};
// Lớp ChuyenBay lưu trữ thông tin về một chuyến bay

bool ChuyenBay::KiemTraNgayHopLe(int ngay, int thang, int nam) {
    vector<int> ngayThang = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
        ngayThang[1] = 29;
    }
    return ((thang >= 1 && thang <= 12) && (ngay >= 1 && ngay <= ngayThang[thang - 1]) && (nam >=1));
}

bool ChuyenBay::KiemTraMaCB(string ma) {
    if(ma.size()>5) return false;
    for(char c : ma){
        if(!isalnum(c)) return false;
    }
    return true;
}

bool ChuyenBay::KiemTraNoi(string noi) {
    if (noi.size() > 20) return false;
    for (char c : noi) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}


void ChuyenBay::Nhap() {

    do {
        cout << "Nhap ma chuyen bay: ";
        getline(cin, maCB);
        if (!KiemTraMaCB(maCB)) {
            cout << "Ma chuyen bay khong hop le. Vui long nhap lai!\n";
        }
    } while (!KiemTraMaCB(maCB));

    do {
        cout << "Nhap ngay, thang, nam khoi hanh: ";
        cin >> ngay >> thang >> nam;
        if (!KiemTraNgayHopLe(ngay, thang, nam)) {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!\n";
        }
    } while (!KiemTraNgayHopLe(ngay, thang, nam));

    do {
        cout << "Nhap gio, phut khoi hanh: ";
        cin >> gio >> phut;
        if (gio < 0 || gio >= 24 || phut < 0 || phut >= 60) {
            cout << "Gio hoac phut khong hop le. Vui long nhap lai!\n";
        }
    } while (gio < 0 || gio >= 24 || phut < 0 || phut >= 60);

    cin.ignore();

    do {
        cout << "Nhap noi di: ";
        getline(cin, noiDi);
        if (!KiemTraNoi(noiDi)) {
            cout << "Noi di khong hop le. Vui long nhap lai!\n";
        }
    } while (!KiemTraNoi(noiDi));

    do {
        cout << "Nhap noi den: ";
        getline(cin, noiDen);
        if (!KiemTraNoi(noiDen)) {
            cout << "Noi den khong hop le. Vui long nhap lai!\n";
        }
    } while (!KiemTraNoi(noiDen));

}

void ChuyenBay::Xuat() {
    cout << "Ma CB: " << maCB << " | " << ngay << "/" << thang << "/" << nam;
    cout << " | " << gio << ":";
    if(phut<10){
        cout<<"0"<<phut;
    }else cout<<phut;
    cout << " | Noi di: " << noiDi << " | Noi den: " << noiDen << endl;
}

class QuanLyChuyenBay {
private:
    int n;
    ChuyenBay *ds;
public:
    void Nhap();
    void Xuat();
    void TimKiem();
    void SapXep();
    void HienThiTheoNgay();
    void DemChuyenBay();
    ~QuanLyChuyenBay();
};

void QuanLyChuyenBay::Nhap() {
    cout << "Nhap so luong chuyen bay: "; cin >> n;
    cin.ignore();
    ds = new ChuyenBay[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void QuanLyChuyenBay::Xuat() {
    cout << "\nDanh sach chuyen bay:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

void ChuanHoa(string& a){
for(char &c : a){
    c = tolower(c);
}
}

void QuanLyChuyenBay::TimKiem() {
    cin.ignore();
    cout << "\nNhap tu khoa tim kiem (ma CB, noi di, noi den): ";
    string tuKhoa;
    getline(cin, tuKhoa);
    ChuanHoa(tuKhoa);
    bool KT = false;
    for (int i = 0; i < n; i++) {
            string ma = ds[i].maCB, noidi = ds[i].noiDi, noiden = ds[i].noiDen;
            ChuanHoa(ma);
            ChuanHoa(noidi);
            ChuanHoa(noiden);
        if ((ma == tuKhoa) || (noidi == tuKhoa) || (noiden == tuKhoa)) {
            ds[i].Xuat();
            KT = true;
        }
    }
    if (!KT) cout << "Khong tim thay!\n";
}

void QuanLyChuyenBay::SapXep() {
    sort(ds, ds + n, [](ChuyenBay a, ChuyenBay b) {
        if (a.nam != b.nam) return a.nam < b.nam;
        if (a.thang != b.thang) return a.thang < b.thang;
        if (a.ngay != b.ngay) return a.ngay < b.ngay;
        if (a.gio != b.gio) return a.gio < b.gio;
        return a.phut < b.phut;
    });
    cout << "\nDanh sach sau khi sap xep:\n";
    Xuat();
}

void QuanLyChuyenBay::HienThiTheoNgay() {
    int ngay, thang, nam;
    cout << "\nNhap ngay thang nam can tim: ";
    cin >> ngay >> thang >> nam;
    cin.ignore();
    string noi;
    cout << "Nhap noi di hoac noi den: ";
    getline(cin, noi);
    ChuanHoa(noi);
    bool KT = false;
    for (int i = 0; i < n; i++) {
        string Di = ds[i].noiDi, Den = ds[i].noiDen;
        ChuanHoa(Di);
        ChuanHoa(Den);

        if (ds[i].ngay == ngay && ds[i].thang == thang && ds[i].nam == nam &&
            (Di == noi || Den == noi)) {
            ds[i].Xuat();
            KT = true;
        }
    }
    if (!KT) cout << "Khong co chuyen bay phu hop!\n";
}

void QuanLyChuyenBay::DemChuyenBay() {
    cin.ignore();
    cout << "\nNhap noi di: ";
    string NoiDi;
    getline(cin, NoiDi);
    ChuanHoa(NoiDi);

    cout << "Nhap noi den: ";
    string NoiDen;
    getline(cin, NoiDen);
    ChuanHoa(NoiDen);

    int dem = 0;
    int i;
    for (int i = 0; i < n; i++) {
        string Di = ds[i].noiDi, Den = ds[i].noiDen;
        ChuanHoa(Di);
        ChuanHoa(Den);
        if (Di == NoiDi && Den == NoiDen) dem++;
    }
    cout << "So chuyen bay tu " << NoiDi << " den " << NoiDen << ": " << dem << "\n";
}


QuanLyChuyenBay::~QuanLyChuyenBay() {
    delete[] ds;
}

int main() {
    QuanLyChuyenBay ql;
    ql.Nhap();
    ql.Xuat();
    ql.SapXep();
    ql.TimKiem();
    ql.HienThiTheoNgay();
    ql.DemChuyenBay();
    return 0;
}
