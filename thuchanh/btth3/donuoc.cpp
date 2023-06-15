#include <iostream>
using namespace std;


void bubbleSort(int *a, int n) {
    bool flag;
    do {
        flag = false;
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;

                flag = true;
            }
        }
    }while(flag == true);
}

int pourWater(int n, int *a, int m) {

    bubbleSort(a,m);

    int count = 0;
    
    for(int i = 0; i < m; i++) {
        if(n >= a[i]) {
            n -= a[i];
            count++;
        }
    }
    return count;
}


int main() {
    int a[8]{5, 40, 60, 10, 20, 30, 15, 25};
    int n = 100;
    cout <<"so chai toi da do duoc la " << pourWater(n,a,8);

    return 0;
}
