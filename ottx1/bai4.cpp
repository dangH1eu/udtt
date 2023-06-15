
#include <iostream>
#include <string>
using namespace std;

struct ChuyenBay {
    string soHieu;
    double giaVe;
    int soGhe;

    ChuyenBay(){};
    ChuyenBay(string soHieu, double giaVe, int soGhe) {
        this->soHieu = soHieu;
        this->giaVe = giaVe;
        this->soGhe = soGhe;
    }
};
void hienthi(ChuyenBay *a, int i) {
        cout << a[i].soHieu << "\t";
        cout << a[i].giaVe << "\t";
        cout << a[i].soGhe << "\t" << endl;
}

// void hienthive(ChuyenBay *x, int n) {
//     if(n == 1){
//         if(x[n-1].giaVe > 700000)
//             hienthi(x,n-1);
//     }else {
//         if(x[n-1].giaVe > 700000)
//             hienthi(x,n-1);
//         hienthive(x,n - 1);
//     }
// }
//

void hienthive(ChuyenBay *x, int l, int r) {
    if(l == r) {
        if(x[l].giaVe > 700000)
            hienthi(x, l);
    }else {
        int m = (l + r)/2;
        hienthive(x,l,m);
        hienthive(x,m+1,r);
    }
}
double findmin(ChuyenBay *x, int l, int r) {
    if(l == r) {
        return x[l].giaVe;
    } else {
        int m = (l + r) / 2;
        double minLeft = findmin(x,l,m);
        double minRight = findmin(x,m+1,r);
        if(minLeft < minRight)
            return minLeft;
        else return minRight;
    }
}

int main() {
    ChuyenBay a[6]  = {{"VN001",700000,40},
        {"VN002",800000,60},
        {"VN003",900000,70},
        {"VN004",1200000,45},
        {"VN005",1000000,85},
        {"VN006",600000,55}};
    // a[0] = {"VN001",500000,40};
    // a[1] = {"VN001",500000,40};
    // a[2] = {"VN001",500000,40};
    // a[3] = {"VN001",500000,40};
    // a[4] = {"VN001",500000,40};
    // a[5] = {"VN001",500000,40};


    for(int i = 0; i < 6; i++) {
        hienthi(a,i);
    }
    cout << "chuyen bay co gia ve tren 700000" << endl;
    hienthive(a,0,5);

    cout << "chuyen bay co gia ve nho nhat la" << endl;
    cout << findmin(a,0,5);

    return 0;
}
