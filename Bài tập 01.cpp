#include <bits/stdc++.h>
using namespace std;
struct PhanSo {
int TuSo;
int MauSo;
};

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
void Nhap(PhanSo &a){
cin>>a.TuSo>>a.MauSo;
while(a.MauSo==0){
    cout<<"Nhap lai Phan So:"<<endl;
    cin>>a.TuSo>>a.MauSo;
}
}
void Xuat(PhanSo &x){
if(x.TuSo ==0) {cout<<0;}
else{
if(x.MauSo<0){
 x.TuSo=-x.TuSo;
 x.MauSo=-x.MauSo;
}
 int u = ucln(x.TuSo,x.MauSo);
 x.TuSo/=u;
 x.MauSo/=u;
 if(x.TuSo%x.MauSo==0){
    cout<<x.TuSo/x.MauSo;
 } else{
 cout<<x.TuSo<<"/"<<x.MauSo;
 }
}
}
int main(){
PhanSo x;
cout<<"Nhap Phan So:"<<endl;
Nhap(x);
cout<<"Ket Qua Rut Gon Phan So:"<<endl;
Xuat(x);
}
