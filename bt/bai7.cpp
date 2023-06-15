#include <iostream>
#include <iomanip>

using namespace std;
struct XeTai {
    string bienSo;
    float taiTrong;

    XeTai(){}
    XeTai(string bienSo, float taiTrong) {
        this->bienSo = bienSo;
        this->taiTrong = taiTrong;
    }
};

template <typename T> struct List {
    int count;
    T  e[100];
};

void create(List<XeTai> &L) {
    L.count = -1;
}

int full(List<XeTai> &L){
    return L.count == 99;
} 

int push_back(List<XeTai> &L, XeTai x) {
    if(full(L)) return 0;
    else {
        L.count++;
        L.e[L.count] = x;
        return 1;
    }
}
void hien_thi(List<XeTai> L) {

    for(int i = 0; i < L.count; i++) {
    cout << setw(10) << i+1;
    cout << setw(10) << L.e[i].bienSo;
    cout << setw(10) << L.e[i].taiTrong << endl;
    }
}

int main() {
    List<XeTai> L;
    create(L);
    XeTai x1 = {"123sajf", 2};push_back(L, x1);
    XeTai x2 = {"123sajf", 2};push_back(L, x2);
    XeTai x3 = {"123sajf", 2};push_back(L, x3);
    XeTai x4 = {"123sajf", 2};push_back(L, x4);
    XeTai x5 = {"123sajf", 2};push_back(L, x5);
    XeTai x6 = {"123sajf", 2};push_back(L, x6);
    hien_thi(L);



    return 0;
}
