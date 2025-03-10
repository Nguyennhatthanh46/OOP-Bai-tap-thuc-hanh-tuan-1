#include <bits/stdc++.h>

using namespace std;
class SinhVien{
    friend class KiemTraSinhVien;
private:
    string HovaTen;
    double diemToan,diemVan,diemAnh;
public:
    void Nhap();
    void Xuat();
    double DiemTB();
    double getdiemToan(){
     return diemToan;
    }
};
// Lớp Sinh Viên đại diện cho một sinh viên với thông tin về tên và điểm các môn học. Với thuộc tính private là tên, điểm các môn học.
//Thuộc tính public nhập, xuất, tính toán điểm sinh viên. 

double SinhVien::DiemTB() {
    return (2 * diemToan + diemVan + diemAnh) / 4;
}
// Hàm tính điểm trung bình theo công thức: (2 * Toán + Văn + Anh) / 4

void SinhVien::Nhap(){
cin.ignore();
cout<<"Vui long nhap Ho va Ten: ";
while(1){
getline(cin,HovaTen);
bool xet = true;
for(char c : HovaTen){
    if(c>='0'&&c<='9'){
        xet = false;
        break;
    }
}
 if(xet) break;
 cout<<"Ten khong hop le. Vui long nhap lai."<<endl;
}
cout<<"Vui long nhap lan luot diem Toan, Van, Anh: ";
cin>>diemToan>>diemVan>>diemAnh;
while(diemToan<0||diemToan>10){
    cout<<"Diem Toan khong hop le. Vui long nhap lai!";
    cin>>diemToan;
}
while(diemVan<0||diemVan>10){
    cout<<"Diem Van khong hop le. Vui long nhap lai!";
    cin>>diemVan;
}
while(diemAnh<0||diemAnh>10){
    cout<<"Diem Anh khong hop le. Vui long nhap lai!";
    cin>>diemAnh;
}
}
// Hàm nhập thông tin sinh viên, kiểm tra hợp lệ cho họ tên và điểm. Phải đúng các yêu cầu từ điểm. Kiểu dữ liệu tên, nếu sai thì phải nhập lại. 

void SinhVien::Xuat() {
    cout << "Ho va Ten: " << HovaTen << endl;
    cout << "Diem Toan: " << diemToan << ", Diem Van: " << diemVan << ", Diem Anh: " << diemAnh << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << DiemTB() << endl;
    cout<<"Hoc luc: ";
     if(DiemTB()>=9){
        cout<<"Xuat xac"<<endl;
     }else if(DiemTB()>=8){
        cout<<"Gioi"<<endl;
     }else if(DiemTB()>=6.5){
        cout<<"Kha"<<endl;
     }else if(DiemTB()>=5){
        cout<<"Trung binh"<<endl;
     }else{
        cout<<"Yeu"<<endl;
     }
     cout<<endl;
}
// Hàm xuất thông tin sinh viên, bao gồm họ tên, điểm và học lực. Trong đó so sánh điểm học lực của sinh viên theo thang điểm và xếp loại sinh viên theo điểm TB đó. 

class KiemTraSinhVien{
private:
    int n; //Số lượng sinh viên
    SinhVien *a; // Con trỏ mảng động để lưu danh sách sinh viên
public:
    void Nhap();
    void Xuat();
    void TimKiem();
    void ToanThapNhat();
    void TuKhoa();
    ~KiemTraSinhVien();
};
// Định nghĩa lớp KiemTraSinhVien để quản lý danh sách sinh viên. Tạo các thao tác nhập, xuất, so sánh. 

void KiemTraSinhVien::Nhap() {
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    a = new SinhVien[n]; // Cấp phát bộ nhớ động cho mảng sinh viên

    for (int i = 0; i < n; i++) {
        cout << "\nThi Sinh thu " << i + 1 << ":" << endl;
        a[i].Nhap();
    }
}
// Hàm nhập danh sách sinh viên. Tạo mảng Sinh viên. 

void KiemTraSinhVien::Xuat() {
    cout << "\nDanh Sach Thi Sinh: " << endl;
    for (int i = 0; i < n; i++) {
        a[i].Xuat();
    }
}
// Hàm xuất danh sách sinh viên. 

void KiemTraSinhVien::TimKiem(){
    cout<<"\nThi Sinh co diem TB cao nhat: "<<endl;
    double xet = 0;
    for(int i = 0; i < n;i++){
        if (xet < a[i].DiemTB()){
            xet = a[i].DiemTB();
        }

   }
   for(int i =0;i<n;i++){
    if(xet==a[i].DiemTB()){
        a[i].Xuat();
    }
   }
}
// Hàm tìm sinh viên có điểm trung bình cao nhất. Duyệt các phần tử gán, xem phần tử nào có điểm trung bình lớn hơn thì xuất phần tử đó. 

void KiemTraSinhVien::ToanThapNhat(){
cout<<"\nThi Sinh co diem Toan thap nhat: "<<endl;
    double xet =  a[0].getdiemToan();
    for(int i = 0; i < n;i++){
        if (xet > a[i].getdiemToan()){
            xet = a[i].getdiemToan();
        }

   }
   for(int i =0;i<n;i++){
    if(xet==a[i].getdiemToan()){
        a[i].Xuat();
    }
   }
}
// Tìm sinh viên có điểm Toán thấp nhất. Duyệt các phần tử gán, phần tử nào có điểm toán thấp nhất thì xuất phần tử đó. 

void KiemTraSinhVien::TuKhoa(){
cin.ignore();
cout<<"\nNhap tu khoa can tim: ";
string tuKhoa;
getline(cin,tuKhoa);
for(int i = 0; i < tuKhoa.length();i++){
    if(tuKhoa[i]>='A'&&tuKhoa[i]<='Z'){
        tuKhoa[i]+=32;
    }
}
int kq = 0;
cout<<"Muc tim kiem"<<endl;
for(int i = 0; i<n;i++){
    string Ten = a[i].HovaTen;
     for(int j = 0; j < Ten.length(); j++){
        if(Ten[j]>='A'&&Ten[j]<='Z'){
        Ten[j]+=32;
    }
}
for(int j = 0; j <= Ten.length() - tuKhoa.length(); j++) {
            int KT = 1;
            for (int k = 0; k < tuKhoa.length(); k++) {
                if (Ten[j + k] != tuKhoa[k]) {
                    KT = 0;
                    break;
                }
            }
            if (KT == 1) {
                a[i].Xuat();
                kq++;
            }
        }
    }

    if (kq == 0) {
        cout << "Khong tim thay!"<<endl;
    }
}
// Tìm kiếm sinh viên theo từ khóa trong tên. Chuyển từ khóa về kiểu in thường, và chuyển các tên sinh viên về kiểu in thường để dễ so sánh.
// So sánh bằng cách duyệt 2 vòng lặp và lưu kết quả vào biến KT, nếu đúng thì xuất kết quả. Sai thì xuất "Không tìm thấy."

KiemTraSinhVien::~KiemTraSinhVien() {
    delete[] a;
}
// Hàm hủy giải phóng bộ nhớ động

int main(){
KiemTraSinhVien ds;
    ds.Nhap();
    ds.Xuat();
    ds.TimKiem();
    ds.ToanThapNhat();
    ds.TuKhoa();
    return 0;
}
//Gọi biến, các hàm để tiến hành, nhập xuất và xử lý dữ liệu của chương trình quản lý sinh viên
