#include <bits/stdc++.h>
using namespace std;

struct LopHocPhan {
  string maLop;
  int soHs;
  int soHsN;

  LopHocPhan() {}
  LopHocPhan(string maLop, int soHs, int soHsN) {
    this->maLop = maLop;
    this->soHs = soHs;
    this->soHsN = soHsN;
  }
};

int n = 8;
LopHocPhan *ds;

void khoiTaoDs() {
  ds = new LopHocPhan[n];

  ds[0] = LopHocPhan("it6020", 73, 12);
  ds[1] = LopHocPhan("qtlh6021", 71, 2);
  ds[2] = LopHocPhan("kt6022", 70, 22);
  ds[3] = LopHocPhan("qtkd6023", 68, 30);
  ds[4] = LopHocPhan("lh6024", 66, 6);
  ds[5] = LopHocPhan("it6025", 62, 1);
  ds[6] = LopHocPhan("cnot6026", 60, 15);
  ds[7] = LopHocPhan("cdt6027", 54, 10);
}

void hienThiDs(LopHocPhan *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << setw(10) << a[i].maLop;
    cout << setw(10) << a[i].soHs;
    cout << setw(10) << a[i].soHsN << endl;
  }
  cout << endl;
}

int soLopItNhat(int m) {
  int dem = 0;

  for (int i = 0; i < m; i++) {
    if (m >= ds[i].soHs) {
      m -= ds[i].soHs;
      dem++;
    }
  }
  return dem;
}

int kq[100][500];

int soHsNLonNhat(int n, int k) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (ds[i - 1].soHs <= j) {
        int a = kq[i - 1][j - ds[i - 1].soHs] + ds[i - 1].soHsN;
        int b = kq[i - 1][j];

        if (a > b)
          kq[i][j] = a;
        else
          kq[i][j] = b;
      } else {
        kq[i][j] = kq[i - 1][j];
      }
    }
  }
  return kq[n][k];
}

void truyVetLopHocPhan(int n, int k) {
  int i = n, j = k;
  while (i > 0) {
    if (kq[i][j] != kq[i - 1][j]) {
      cout << setw(10) << ds[i - 1].maLop;
      cout << setw(10) << ds[i - 1].soHs;
      cout << setw(10) << ds[i - 1].soHsN << endl;
      j -= ds[i - 1].soHs;
    }
    i--;
  }
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
  khoiTaoDs();

  hienThiDs(ds, n);

  int m = 200;
  cout << "so lop it nhat can lay lon hon " << m << " la " << soLopItNhat(m)
       << endl;

  int k = 200;
  cout << "k = " << k << endl;
  cout << "so lop hoc co nhieu hoc sinh nu nhat la: " << soHsNLonNhat(n, k)
       << endl;
  cout << "danh sach cac lop hoc" << endl;
  truyVetLopHocPhan(n, k);

  cout << "\nCac lop hoc phan cntt\n";
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (boyer_moore_horspool(ds[i].maLop, "it") > 0) {
      cout << setw(10) << ds[i].maLop;
      cout << setw(10) << ds[i].soHs;
      cout << setw(10) << ds[i].soHsN << endl;
    }
  }

  return 0;
}
