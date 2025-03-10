#include <bits/stdc++.h>
using namespace std;
struct PhanSo {
int TuSo;
int MauSo;
};

//Khai báo kiểu cấu trúc với thuộc tính là tử và mẫu của phân số. 

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

//Hàm tính ước chung lớn nhất với đầu vào tử và mẫu của phân số. Thực hiện phép chia liên tục và hoán đổi giá trị để đạt đến giá trị của a và b. 

void Nhap(PhanSo &a){
cin>>a.TuSo>>a.MauSo;
while(a.MauSo==0){
    cout<<"Nhap lai Phan So:"<<endl;
    cin>>a.TuSo>>a.MauSo;
}
}

//Hàm nhập phân số với đầu vào là tử và mẫu của phân số. Cách thức là triển khai nhập từng thuộc tính. Nếu như mẫu sai thì phải nhập lại.

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

//Hàm xử lý tử và mẫu của phân số khi thực hiện hàm nhập xong, quá trình xử lý sẽ đưa mẫu số về số dương và rút gọn bằng cách chia cho ước chung của tử và mẫu số.

int main(){
PhanSo x;
cout<<"Nhap Phan So:"<<endl; 
Nhap(x);
cout<<"Ket Qua Rut Gon Phan So:"<<endl;
Xuat(x); 
        //Khai báo biến có kiểu dữ liệu Phân Số. Sau đó gọi hàm Nhập và Xuất. 
}
