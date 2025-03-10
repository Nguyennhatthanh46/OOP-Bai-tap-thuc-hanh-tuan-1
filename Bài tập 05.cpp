#include <bits/stdc++.h>
using namespace std;

struct NgayThangNam{
 int ngay, thang, nam;
};
// Khai báo kiểu cấu trúc thông tin ngày, tháng, năm

bool XetNamNhuan(int nam){
if((nam%4==0&&nam%100!=0)||nam % 400 == 0){
    return true;
}
else return false;
}
//Hàm kiểm tra năm nhuận. Một năm là năm nhuận nếu chia hết cho 4 nhưng không chia hết cho 100, hoặc chia hết cho 400

int NgaytrongNam(int thang, int nam){
switch(thang){
case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
case 4: case 6: case 9: case 11: return 30;
case 2: return XetNamNhuan(nam)? 29:28;
default: return 0;
}
}
// Hàm lấy số ngày trong một tháng của một năm cụ thể. Chia các trường hợp thành các tháng 30 ngày, 31 ngày và trường hợp của tháng 2. 

void NhapNgayThangNam(NgayThangNam &a){
do{
  cout<<"Nhap lan luot Ngay, Thang, Nam: ";
  cin>>a.ngay>>a.thang>>a.nam;
  if(a.nam<1){
    cout<<"Nam khong hop le. Vui long nhap lai!"<<endl;
    continue;
  }
  if(a.thang<1||a.thang>12){
    cout<<"Thang khong hop le. Vui long nhap lai!"<<endl;
    continue;
  }
  if(a.ngay<1||a.ngay>NgaytrongNam(a.thang,a.nam)){
    cout<<"Ngay khong hop le. Vui long nhap lai!"<<endl;
    continue;
  }
  break;
}while(1);
}
// Hàm nhập thông tin ngày tháng năm, kiểm tra tính hợp lệ. Nếu vi phạm các yêu cầu thì phải nhập lại. Nhập đúng mới thoát khỏi vòng lặp để thõa mãn yêu cầu đề bài cho. 

void NgayTiepTheo(NgayThangNam &a){
a.ngay++;
if(a.ngay > NgaytrongNam(a.thang,a.nam)){
    a.ngay=1;
    a.thang++;
    if(a.thang>12){
        a.thang=1;
        a.nam++;
    }
}
}
// Hàm tính ngày tiếp theo của một ngày cụ thể. Nếu số ngày vượt quá 1 tháng thì tăng tháng, đưa ngày về 1. Còn hết tháng 12 thì sẽ tăng năm và đưa tháng về 1. 

void NgayTruocDo(NgayThangNam &a){
a.ngay--;
if(a.ngay==0){
    a.thang--;
    if(a.thang==0){
        a.thang=12;
        a.nam--;
    }
    a.ngay = NgaytrongNam(a.thang,a.nam);
}
}
// Hàm tính ngày trước đó của một ngày cụ thể. Nếu ngày giảm về 0 ta sẽ lùi tháng đi. Còn tháng bằng 0 thì lùi năm. Ngày khi đó sẽ lấy ngày cuối tháng đã giảm.

int NgayThuTrongNam(NgayThangNam a){
int NgayThu = 0;
for(int i = 0; i < a.thang;i++){
    NgayThu += NgaytrongNam(i,a.nam);
} NgayThu+=a.ngay;
return NgayThu;
}
// Hàm tính xem một ngày là ngày thứ bao nhiêu trong năm. Duyệt qua các tháng từ 1 đến tháng trước tháng hiện tại. 
//Cộng dồn số ngày của từng tháng rồi cộng cho số ngày hiện tại và trả về kết quả. 

int main(){
NgayThangNam HomNay;
NhapNgayThangNam(HomNay); // Nhập ngày tháng năm 
NgayThangNam x = HomNay;
NgayTiepTheo(x);
cout<<"Ngay tiep theo: "<<x.ngay<<"/"<<x.thang<<"/"<<x.nam<<endl;
 // Tính ngày tiếp theo và in ra kết quả
 
NgayThangNam y = HomNay;
NgayTruocDo(y);
cout<<"Ngay truoc do: "<<y.ngay<<"/"<<y.thang<<"/"<<y.nam<<endl;
  // Tính ngày trước đó và in ra kết quả
 
int c = NgayThuTrongNam(HomNay);
cout<<"Hom nay la ngay thu: "<<c<<" trong nam "<<HomNay.nam<<endl;
 // Tính ngày thứ bao nhiêu trong năm và in ra kết quả
}
