#include <bits/stdc++.h>
using namespace std;

vector<int> DuyetViTri(vector<int> &A, vector<int> &B){
vector<int> vitri;
int n = A.size();
int m = B.size();
for(int i = 0; i <= m - n; i++){
    bool tim = true;
    for(int j = 0;j<n;j++){
        if(B[j+i]!=A[j]){
            tim = false;
            break;
        }
    }
    if(tim) vitri.push_back(i);

}
return vitri;
}

int main(){
int n, m;
cout<<"Nhap lan luot so luong cua phan tu A va B: ";
do {
    cin >> n >> m;
    if (n > m) cout << "So phan tu A khong the lon hon B. Vui long nhap lai!"<<endl;
} while (n > m);
vector<int> A(n), B(m);
cout<<"Nhap cac phan tu mang A: ";
for(vector<int>::iterator it = A.begin(); it!=A.end();it++){
    cin>>*it;
}
cout<<"Nhap cac phan tu mang B: ";
for(vector<int>::iterator it = B.begin(); it!=B.end();it++){
    cin>>*it;
}

vector<int> vitri = DuyetViTri(A,B);
cout<<"So lan xuat hien: "<<vitri.size()<<endl;
cout<<"Cac chi so bat dau: ";
for(int x : vitri){
    cout<<x<<" ";
}
}
