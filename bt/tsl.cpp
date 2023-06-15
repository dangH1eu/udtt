#include <iostream>
using namespace std;


int tsl(int *a, int l, int r, int& count) {
    if(l == r) {
        if(a[l] % 2 != 0) {
            count++;
            return a[l];
        } else return 0;
    } else {
        int m = (l + r) / 2;
        int tslt = tsl(a,l,m,count);
        int tslp = tsl(a,m+1,r,count);
        return tslt + tslp; 
    }
}



int main() {

    int a[10] {1,3,1,2,5,6,2,3,4,9};
    int count = 0;
    int sum = tsl(a,0,9,count);
    cout << sum << endl;
    cout << (double)sum / count << endl;

    return 0;
}
