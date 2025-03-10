#include <bits/stdc++.h>
using namespace std;

// Hàm tính giá trị của biểu thức dựa trên chuỗi số
long double tinh(long double x){
long double tong = x; // Khởi tạo tổng bằng giá trị x
long double a = -1; //Hệ số đan dấu
long double b = x; //Gán x cho b để chuyển thành dạng lũy thừa
long double y; //Khai báo y giữ từng chỉ số
long double c = 1; //Biến được khai báo để giữ giai thừa. 
for (int i = 1;;i++){
b*=x*x; // Tính lũy thừa tiếp theo của x
c*= (2*i)*(2*i+1); // Tính giai thừa tương ứng
y = a*(b/c); // Tính số hạng mới
tong+=y; // Cộng vào tổng
 if (abs(y) < 0.00001) break; //Dừng vòng lặp khi nó vượt quá độ chính xác
   a*=-1; //Đổi dấu chỉ số
   }
return tong;
}
int main(){
long double x;
cout<<"Nhap x: "; //Khai báo biến x
cin >> x;
    cout <<fixed << setprecision(5) << tinh(x); //gọi hàm tính Sin(x) để thực hiện tính toán và xuất kết quả và làm tròn thành 5 chữ số sau dấu thập phân.
    return 0;
}
