#include <bits/stdc++.h>
using namespace std;

struct NgayThangNam{
 int ngay, thang, nam;
};

bool XetNamNhuan(int nam){
if((nam%4==0&&nam%100!=0)||nam % 400 == 0){
    return true;
}
else return false;
}

int NgaytrongNam(int thang, int nam){
switch(thang){
case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
case 4: case 6: case 9: case 11: return 30;
case 2: return XetNamNhuan(nam)? 29:28;
default: return 0;
}
}

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

int NgayThuTrongNam(NgayThangNam a){
int NgayThu = 0;
for(int i = 0; i < a.thang;i++){
    NgayThu += NgaytrongNam(i,a.nam);
} NgayThu+=a.ngay;
return NgayThu;
}

int main(){
NgayThangNam HomNay;
NhapNgayThangNam(HomNay);
NgayThangNam x = HomNay;
NgayTiepTheo(x);
cout<<"Ngay tiep theo: "<<x.ngay<<"/"<<x.thang<<"/"<<x.nam<<endl;
NgayThangNam y = HomNay;
NgayTruocDo(y);
cout<<"Ngay truoc do: "<<y.ngay<<"/"<<y.thang<<"/"<<y.nam<<endl;
int c = NgayThuTrongNam(HomNay);
cout<<"Hom nay la ngay thu: "<<c<<" trong nam "<<HomNay.nam<<endl;
}
