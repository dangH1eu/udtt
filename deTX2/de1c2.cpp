#include <iostream>
using namespace std;

struct ManHinh {
  string hangSx;
  int kichThuoc;
  int khoiLuong;

  ManHinh() {}
  ManHinh(string hangSx, int kichThuoc, int khoiLuong) {
    this->hangSx = hangSx;
    this->kichThuoc = kichThuoc;
    this->khoiLuong = khoiLuong;
  }
};

int n;
ManHinh *ds;

int m;

void khoiTaoDs() {
  n = 7;
  ds = new ManHinh[n];

  ds[0] = ManHinh("DELL", 14, 3);
  ds[1] = ManHinh("LG", 15, 4);
  ds[2] = ManHinh("ASUS", 32, 5);
  ds[3] = ManHinh("SAMSUNG", 24, 4);
  ds[4] = ManHinh("HP", 27, 5);
  ds[5] = ManHinh("Lenovo", 24, 5);
  ds[6] = ManHinh("Acer", 17, 4);
}

void hienThiDs() {
  for (int i = 0; i < n; i++) {
    cout << ds[i].hangSx << "\t";
    cout << ds[i].kichThuoc << "\t";
    cout << ds[i].khoiLuong << "\n";
  }
  cout << endl;
}

void timKichThuocMax(int left, int right, ManHinh &max, int &viTri) {
  ManHinh max1, max2;

  if (left == right) {
    max = ds[left];
    viTri = left;
  }

  else {
    int mid = (left + right) / 2;
    max1 = ds[mid];
    max2 = ds[right];

    int v1, v2;
    timKichThuocMax(left, mid, max1, v1);
    timKichThuocMax(mid + 1, right, max2, v2);

    if (max1.kichThuoc > max2.kichThuoc) {
      max = max1;
      viTri = v1;
    } else {
      max = max2;
      viTri = v2;
    }
  }
}

int kq[100][21];

int xepManHinh(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= m; w++) {
      if (ds[i - 1].khoiLuong <= w) {
        int a = kq[i - 1][w - ds[i - 1].khoiLuong] + ds[i - 1].kichThuoc;
        int b = kq[i - 1][w];

        if (a > b)
          kq[i][w] = a;
        else
          kq[i][w] = b;
      }else {
      kq[i][w] = kq[i - 1][w];

      }
    }
  }
  return kq[n][m];
}

void truyVetManHinh(){

    int i = n, j = m;
    while(i != 0) {
        if(kq[i][j] != kq[i-1][j]){
            cout << "Man hinh thu " << i-1 << "HangSX: " << ds[i-1].hangSx;
            cout << "Kich thuoc: " << ds[i-1].kichThuoc;
            cout << "Khoi luong: " << ds[i-1].khoiLuong << endl;
            j -= ds[i-1].khoiLuong;
        }
        i--;
    }
}


int main() {

  khoiTaoDs();
  hienThiDs();

  ManHinh max = ds[n - 1];
  int viTri = n - 1;
  timKichThuocMax(0, n - 1, max, viTri);
  cout << "Man hinh co kich thuoc lon nhat la \n";
  cout << "Hang SX: " << max.hangSx << endl;
  cout << "Kich thuoc: " << max.kichThuoc << endl;
  cout << "khoi luong: " << max.khoiLuong << endl;

  cout << "Vi tri thu: " << viTri + 1 << endl;
  
	m = 15;
  cout << "\nTai trong m cua xe: " << m << endl;

  int kichThuocMax = xepManHinh(n, m);
  cout << "Kich thuoc man hinh xep duoc lon nhat la: " << kichThuocMax << endl;
  cout << "Thong tin cac man hinh duoc xep len xe:\n";

  truyVetManHinh();

  return 0;
}
