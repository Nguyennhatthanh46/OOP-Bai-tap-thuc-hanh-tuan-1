#include <bits/stdc++.h>
using namespace std;

vector<int> DuyetViTri(vector<int> &A, vector<int> &B){
vector<int> vitri; //Dùng vecto để lưu kích cỡ và các vị trí xuất hiện của mảng A trong B. 
int n = A.size();
int m = B.size();
// Duyệt qua từng vị trí có thể là điểm bắt đầu của A trong B   
for(int i = 0; i <= m - n; i++){
    bool tim = true;
    for(int j = 0;j<n;j++){
        if(B[j+i]!=A[j]){ // So sánh từng phần tử của A với phần tử tương ứng trong B. Nếu không tìm thấy thì thoát vòng lặp. 
            tim = false;
            break;
        }
    }
    if(tim) vitri.push_back(i);//Nếu tìm thấy thì đánh dấu. 

}
return vitri;
}
// Hàm tìm vị trí xuất hiện của mảng A trong mảng B bằng vecto. Dữ liệu nhập vào là mảng A và B, sau đó xuất ra kết quả của mảng gán giá vị trí. 


int main(){
int n, m;
cout<<"Nhap lan luot so luong cua phan tu A va B: ";
do {
    cin >> n >> m;
    if (n > m) cout << "So phan tu A khong the lon hon B. Vui long nhap lai!"<<endl;
} while (n > m);
 // Nhập số phần tử của mảng A và B, đảm bảo n <= m   
vector<int> A(n), B(m);
cout<<"Nhap cac phan tu mang A: ";
for(vector<int>::iterator it = A.begin(); it!=A.end();it++){
    cin>>*it;
}
cout<<"Nhap cac phan tu mang B: ";
for(vector<int>::iterator it = B.begin(); it!=B.end();it++){
    cin>>*it;
}
//Khai báo mảng A và B rồi nhập các phần tử vào chúng. 

vector<int> vitri = DuyetViTri(A,B);
cout<<"So lan xuat hien: "<<vitri.size()<<endl;
cout<<"Cac chi so bat dau: ";
for(int x : vitri){
    cout<<x<<" ";
}
// Xuất kết quả số lần xuất hiện và chỉ số xuất hiện của mảng A trong B thông qua hàm xử lý lưu vị trí. 
}
