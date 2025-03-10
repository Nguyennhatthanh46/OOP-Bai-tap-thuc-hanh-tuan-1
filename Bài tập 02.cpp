#include <bits/stdc++.h>
using namespace std;
struct PhanSo {
int TuSo;
int MauSo;
};

//Chương trình gọi thuộc tính tử và mẫu của kiểu Phân Số. 

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

//Hàm gọi ước chung lớn nhất để xử lý tử và mẫu của phân số. 

void Nhap(PhanSo &a){
cin>>a.TuSo>>a.MauSo;
while(a.MauSo==0){
    cout<<"Nhap lai Phan So:"<<endl;
    cin>>a.TuSo>>a.MauSo;
}
}

//Hàm nhập biến kiểu phân số. Nếu tử số sai thì nhập lại. 

void RutgonPhanSo(PhanSo &x){
if(x.MauSo<0){
 x.TuSo=-x.TuSo;
 x.MauSo=-x.MauSo;
}
 int u = ucln(x.TuSo,x.MauSo);
 x.TuSo/=u;
 x.MauSo/=u;
}

//Gọi hàm rút gọn để đưa về phân số tối giản để dễ so sánh. Hàm này chia tử và mẫu cho ước chung lớn nhất của chúng. 

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

//Hàm xuất xử lý tử và mẫu sau khi rút gọn. Sau đó tiến hành so sánh chung và xuất phân số lớn hơn ra, đồng thời định dạng đưa mẫu số về dương. 

int main(){
PhanSo a,b;
cout<<"Nhap Phan So a va b: "<<endl;
Nhap(a);
Nhap(b); //Gọi hàm nhập cho biến a, b
RutgonPhanSo(a);
RutgonPhanSo(b); //Xử lý rút gọn a,b
cout<<"Phan So Lon Nhat: ";
XuatKetQua(a,b); //Xử lý và xuất phân số lớn nhất.
}
