#include <bits/stdc++.h>

using namespace std;
class PhanSo {
private:
    int tuSo;
    int mauSo;
public:
    PhanSo Cong(PhanSo a, PhanSo b);
    PhanSo Tru(PhanSo a, PhanSo b);
    PhanSo Nhan(PhanSo a, PhanSo b);
    PhanSo Chia(PhanSo a, PhanSo b);
    void Nhap1();
    void Nhap2();
    void Xuat();

};

void PhanSo::Nhap1(){
cout<<"Nhap Phan So thu nhat: ";
cin>>tuSo>>mauSo;
while(mauSo==0){
    cout<<"Nhap lai Phan So thu nhat: ";
    cin>>tuSo>>mauSo;
}
}

void PhanSo::Nhap2(){
cout<<"Nhap Phan So thu hai: ";
cin>>tuSo>>mauSo;
while(tuSo==0||mauSo==0){
    cout<<"Nhap lai Phan So thu hai: ";
    cin>>tuSo>>mauSo;
}
}

int ucln(int a, int b){
if(b==0) return 0;
int y = abs (a);
while(b!=0){
        int x = b;
        b = y%b;
        y = x;
}
return y;
}


void PhanSo::Xuat(){
if(tuSo==0) {cout<<0<<endl;}
else{
if(mauSo<0){
 tuSo=-tuSo;
 mauSo=-mauSo;
}
 int u = ucln(tuSo,mauSo);
 tuSo/=u;
 mauSo/=u;
 if(tuSo%mauSo==0){
    cout<<tuSo/mauSo<<endl;
 } else{
 cout<<tuSo<<"/"<<mauSo<<endl;
 }
}
}

PhanSo  PhanSo::Cong(PhanSo a, PhanSo b){
PhanSo tong;
tong.tuSo = a.tuSo*b.mauSo + a.mauSo*b.tuSo;
tong.mauSo = a.mauSo*b.mauSo;
return tong;
}

PhanSo  PhanSo::Tru(PhanSo a, PhanSo b){
PhanSo tru;
tru.tuSo = a.tuSo*b.mauSo - a.mauSo*b.tuSo;
tru.mauSo = a.mauSo*b.mauSo;
return tru;
}

PhanSo  PhanSo::Nhan(PhanSo a, PhanSo b){
PhanSo nhan;
nhan.tuSo = a.tuSo*b.tuSo;
nhan.mauSo = a.mauSo*b.mauSo;
return nhan;
}

PhanSo  PhanSo::Chia(PhanSo a, PhanSo b){
PhanSo chia;
chia.tuSo = a.tuSo*b.mauSo;
chia.mauSo = a.mauSo*b.tuSo;
return chia;
}

int main(){
PhanSo p1,p2;
p1.Nhap1();
p2.Nhap2();
PhanSo p3 = p3.Cong(p1,p2);
PhanSo p4 = p4.Tru(p1,p2);
PhanSo p5 = p5.Nhan(p1,p2);
PhanSo p6 = p6.Chia(p1,p2);
cout<<"Ket qua phep tinh cong: "<<endl;
p3.Xuat();
cout<<"Ket qua phep tinh tru: "<<endl;
p4.Xuat();
cout<<"Ket qua phep tinh nhan: "<<endl;
p5.Xuat();
cout<<"Ket qua phep tinh chia: "<<endl;
p6.Xuat();
}
