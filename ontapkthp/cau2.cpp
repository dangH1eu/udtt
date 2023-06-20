#include <bits/stdc++.h>
using namespace std;

int soPhanTuNn(double *a, int n, double c) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= c) {
      count++;
      c -= a[i];
    }
  }
  return count;
}

int char_in_string(char x, string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == x) {
      return i;
    }
  }
  return -1;
}

int boyer_moore_horspool(string T, string P) {
  int count = 0;
  int i = P.size();
  int v = P.size();

  while (i <= T.size()) {
    int j = i - 1;
    int x = v - 1;

    while (P[x] == T[j] && x > -1) {
      x--;
      j--;
    }

    if (x < 0) {
      count++;
      i += v;
    } else {
      int k = char_in_string(T[j], P);
      if (k < 0) {
        i += v;
      } else {
        i += v - k - 1;
      }
    }
  }
  return count;
}

int main() {

  double a[9] = {1.3, 2.2, 3.2, 4.4, 4.7, 5.1, 5.8, 7.6, 8.2};
  double *s;

  // 1
  double c = 8.5;
  cout << "c = " << c;
  int spt = soPhanTuNn(a, 9, c);
  cout << "\nSo phan tu lay duoc trong mang ko vuot qua c la: " << spt;

  // 2

  return 0;
}
