#include <bits/stdc++.h>
using namespace std;

long double tinh(long double x){
long double tong = x;
long double a = -1;
long double b = x;
long double y;
long double c = 1;
for (int i = 1;;i++){
b*=x*x;
c*= (2*i)*(2*i+1);
y = a*(b/c);
tong+=y;
 if (abs(y) < 0.00001) break;
   a*=-1;
   }
return tong;
}
int main(){
long double x;
cout<<"Nhap x: ";
cin >> x;
    cout <<fixed << setprecision(5) << tinh(x);
    return 0;
}
