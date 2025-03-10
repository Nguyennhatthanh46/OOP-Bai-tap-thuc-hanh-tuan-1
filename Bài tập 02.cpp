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
void RutgonPhanSo(PhanSo &x){
if(x.MauSo<0){
 x.TuSo=-x.TuSo;
 x.MauSo=-x.MauSo;
}
 int u = ucln(x.TuSo,x.MauSo);
 x.TuSo/=u;
 x.MauSo/=u;
}
void XuatKetQua(PhanSo a,PhanSo b){
int x = a.TuSo*b.MauSo;
int y = b.TuSo*a.MauSo;
if(x>y){
    if(a.TuSo==0){
        cout<<"0";
    } else{
        if(a.TuSo%a.MauSo==0){
           cout<<a.TuSo/a.MauSo;
        }else{
           cout<<a.TuSo<<"/"<<a.MauSo;
        }
    }
}
else{
    if(b.TuSo==0){
        cout<<"0";
    } else{
        if(b.TuSo%b.MauSo==0){
           cout<<b.TuSo/b.MauSo;
        }else{
           cout<<b.TuSo<<"/"<<b.MauSo;
        }
    }
}
}
int main(){
PhanSo a,b;
cout<<"Nhap Phan So a va b: "<<endl;
Nhap(a);
Nhap(b);
RutgonPhanSo(a);
RutgonPhanSo(b);
cout<<"Phan So Lon Nhat: ";
XuatKetQua(a,b);
}
