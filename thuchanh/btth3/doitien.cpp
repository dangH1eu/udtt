#include <iostream>
using namespace std;

int n = 5;

int a[5] = {100,25,10,5,1};

int coin_changing(long m) {
    int count = 0;
    int i = 0;

    while(m != 0 && i < 5) {
        if(m >= a[i]) {
            m -= a[i];
            count++;
        }
        else {
            i++;
        }
    }

    return count;
}

int main() {

    long m = 61;
    cout << "can lay " << coin_changing(m) << " to tien";

}
