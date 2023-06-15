#include <iostream>
using namespace std;;

int tsl(int *x, int low, int high) {
    if(low == high){
        if(x[low] % 2 != 0) return x[low];
        else return 0;
    }
    else {
        int mid = (low + high)/2;
        int sumLeft = tsl(x,low,mid);
        int sumRight = tsl(x,mid+1,high);
        return sumLeft + sumRight;
    }
}

int main() {

    int a[10]{1,2,3,2,13,12,21,4,1,9};
    cout << tsl(a,0,9);

    return 0;
}
