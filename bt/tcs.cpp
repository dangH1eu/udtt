#include <iostream>
using namespace std;

int tcs(int n) {
  if (n < 10)
    return n;
  else
    return n % 10 + tcs(n / 10);
}

int main() {

  int n;
  cout << "nhap so n: ";
  cin >> n;
  cout << "tcs cua n: " << tcs(n);

  return 0;
}
