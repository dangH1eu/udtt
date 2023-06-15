#include <iostream>
using namespace std;

int weight[] = {5, 10, 6, 3, 7, 8};
int value[] = {15, 61, 20, 10, 50, 23};

int a[100][100];

void hienThiMang(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << "  ";
  }
  cout << endl;
}

int timMax(int n, int max) {
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= max; w++) {
      a[i][w] = a[i - 1][w];
      if (weight[i - 1] <= w) {
        int x = value[i - 1] + a[i - 1][w - weight[i - 1]];
        int y = a[i - 1][w];

        if (x > y)
          a[i][w] = x;
        else
          a[i][w] = y;
      }
    }
  }

  return a[n][max];
}

void hienThiGoiHangDaLay(int n, int max) {
  cout << "Cac goi hang da lay: \n";
  int i = n, j = max;
  while(i > 0){
      if(a[i][j] != a[i-1][j]){
          cout << " Goi hang thu " << i << ", w = " << weight[i-1]
              << ", v = " << value[i-1] << endl;
          j -= weight[i-1];
      }
      i--;
  }
}

int main() {
  int n = sizeof(weight) / sizeof(int), max = 20;

  cout << "So goi hang: " << n << endl;
  cout << "Trong luong toi da cua tui: " << max << endl;
  cout << "Thong so cac goi hang lan luot:\n";
  cout << " Weight:\t";
  hienThiMang(weight, n);
  cout << " Value: \t";
  hienThiMang(value, n);

  cout << "\nTong gia tri max lay duoc: " << timMax(n, max) << endl;

  hienThiGoiHangDaLay(n, max);

  return 0;
}
