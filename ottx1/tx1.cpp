#include <iostream>
#include <string>
using namespace std;

struct MyPham {
    string hangSx;
    float dungTich;
    string dtsd;

    MyPham(){}
    MyPham(string hangSx, float dungTich, string dtsd){
        this->hangSx = hangSx;
        this->dungTich = dungTich;
        this->dtsd = dtsd;
    }
};

void hienthi(MyPham *x, int i){
    cout << x[i].hangSx << "\t";
    cout << x[i].dungTich << "\t";
    cout << x[i].dtsd << "\t\n";
}

void hienthiMp(MyPham *x, int n, int i){
    if(i<n) {
        hienthi(x,i);
        i++;
    }else return;
    hienthiMp(x,n,i);
}


float tongDungTich(MyPham *x, int l, int r) {
    if(l == r) {
        if(x[l].dtsd == "nam")
            return x[l].dungTich;
        else return 0;
    }else {
        int m = (l + r)/2;
        float tTrai = tongDungTich(x,l,m);
        float tPhai = tongDungTich(x,m+1,r);
        return tTrai + tPhai;
    }
}



void show(MyPham *a, int *x, int k){
    for(int i = 1; i <= k; i++) {
        cout << a[x[i]-1].hangSx << "\t";
    }
    cout << endl;
}

void action(MyPham *a, int *x, int k, int n, int p){
    for(int i = x[p-1]+1; i <= n-k+p; i++){
        x[p] = i;

        if(p == k)
            show(a,x,k);
        else
         	action(a,x,k,n,p+1);
    }
}

int main() {

    MyPham a[8] = {
        {"H1", 0.3, "nam"},
        {"H2", 0.1, "nu"},
        {"H3", 0.2, "nu"},
        {"H4", 0.8, "nam"},
        {"H5", 0.5, "nam"},
        {"H6", 0.9, "nu"},
        {"H7", 0.6, "nu"},
        {"H8", 0.7, "nam"},
    };
    hienthiMp(a,8,0);

    cout << "Tong dung tich my pham nam: " << tongDungTich(a,0,7) << endl;

	int x[100];

    action(a,x,3,8,1);



    return 0;
}
