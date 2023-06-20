#include <iostream>
using namespace std;

int a[100];
int dem = 0;
// dung de quy
int dem_chu_so_chan(int n) {
  if(n <= 0) {
    return 0;
  }
  if(n < 10) {
    if(n % 2 == 0) {
      a[dem++] = n;
      return 1;
    }
    else {
      return 0;
    }
  }

  int x;
  if((n % 10) % 2 == 0) {
    a[dem++] = n % 10;
    x = 1;
  }
  else {
    x = 0;
  }

  return x + dem_chu_so_chan(n / 10);
}


int main(){

    return 0;
}
