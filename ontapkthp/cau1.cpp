#include <bits/stdc++.h>
using namespace std;


double sumOfArray(double *a, int l, int r){
  if(l == r){
    return a[l];
  }
  int m = (l + r)/2;
  double sumLeft = sumOfArray(a,l,m);
  double sumRight = sumOfArray(a,m+1,r);
  return sumLeft + sumRight;
}

int main() {

  double a[8] = {2.3,1.2,3.2,6.4,2.7,8.1,5.8,3.6};
  cout << "Tong cac phan tu cua mang: " << sumOfArray(a,0,7);


  return 0;
}

