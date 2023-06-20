#include <bits/stdc++.h>
using namespace std;

struct SanPham {
  string maSp;
  string tenSp;
  int khoiLuong;
  int giaTri;
  SanPham() {}
  SanPham(string a, string b, int c, int d) {
    maSp = a;
    tenSp = b;
    khoiLuong = c;
    giaTri = d;
  }
};

// 1

int n = 7;
SanPham *ds;

void khoiTaoDs() {
  ds = new SanPham[n + 1];

  ds[0] = SanPham("SP01", "ban lam viec", 20, 100);
  ds[1] = SanPham("SP02", "choi lau nha", 10, 10);
  ds[2] = SanPham("SP03", "dien thoai", 7, 30);
  ds[3] = SanPham("SP04", "dieu hoa", 26, 42);
  ds[4] = SanPham("SP05", "may tinh", 8, 60);
  ds[5] = SanPham("SP06", "ti vi", 2, 120);
  ds[6] = SanPham("SP07", "tu lanh", 15, 1);
}
void hienThiSp(int i) {
  cout << setw(10) << ds[i].maSp;
  cout << setw(10) << ds[i].tenSp;
  cout << setw(10) << ds[i].khoiLuong;
  cout << setw(10) << ds[i].giaTri << endl;
}

void hienThiDs() {
  for (int i = 0; i < n; i++) {
    hienThiSp(i);
  }
}

// 2

int timViTriChen(SanPham sp, int l, int r) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) / 2;
  if (sp.tenSp.compare(ds[mid].tenSp) > 0) {
    return timViTriChen(sp, mid + 1, r);
  } else if (sp.tenSp.compare(ds[mid].tenSp) < 0) {
    return timViTriChen(sp, l, mid - 1);
  } else
    return mid;
}

void chenSp(SanPham sp, int l, int r) {
  int viTri = timViTriChen(sp, 0, n - 1);

  for (int j = n; j > viTri; j--) {
    ds[j] = ds[j - 1];
  }

  ds[viTri] = sp;
}

// 3

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

void timSpTenTivi(string ten) {
  int flag = 0;
  for (int i = 0; i < n; i++) {
    if (boyer_moore_horspool(ds[i].tenSp, ten) > 0) {
      flag = 1;
      hienThiSp(i);
    }
  }
  if (flag == 0)
    cout << "\nkhong co san pham";
}

int main() {

  khoiTaoDs();
  hienThiDs();

  SanPham sp = {"SP09", "may giat", 20, 12};
  cout << "Danh sach sau khi chen sp:\n";
  chenSp(sp, 0, n - 1);
  hienThiDs();

  cout << "\nDanh sach san pham tivi \n";
  timSpTenTivi("ti vi");

  return 0;
}
