
#include <iostream>
using namespace std;
int n, k;
int x[100];

void show(){
    for(int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void action(int p) {
    for(int i = x[p-1]+1; i <= n-k+p; i++) {
        x[p] = i;

        if(p == k)
            show();
        else
         action(p+1);
    }
}


int main() {
    n = 8;
    k = 3;
    action(1);
    return 0;
}
