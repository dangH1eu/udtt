
#include <iostream>
#include <string>
using namespace std;

struct CongViec {
    string maCv;
    string tgbd;
    string tgth;
    CongViec(string maCv, string tgbd, string tgth) {
        this->maCv = maCv;
        this->tgbd = tgbd;
        this->tgth = tgth;
    }

};

void hienthi(CongViec *a, int i) {
        cout << a[i].maCv << "\t";
        cout << a[i].tgbd << "\t";
        cout << a[i].tgth << "\t" << endl;
}
void hienthicv(CongViec *x, int n) {
    hienthi(x,n-1);
    hienthicv(x, n-1);
}
// void hienthicv(CongViec *x, int n) {
//     int i = 0;
//     if(i<n)
//         hienthicv(x,i+1);
//     hienthi(x,i);
// }

int main() {
    CongViec a[7] = {
        {"CV01", "7h00", "17h30"},
        {"CV02", "7h00", "17h30"},
        {"CV03", "7h00", "17h30"},
        {"CV04", "7h00", "17h30"},
        {"CV05", "7h00", "17h30"},
        {"CV06", "7h00", "17h30"},
        {"CV07", "7h00", "17h30"},
    };


    hienthicv(a,7);


    return 0;
}
