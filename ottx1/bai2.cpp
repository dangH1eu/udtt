
#include <iostream>
using namespace std;

char list[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void view_config(int *x, int n){
    for(int i = 1; i <= n; i++){
        cout << list[x[i]-1] << "\t";
        }
    cout << endl;
}

void next_config(int *x, int k, int i) {
    x[i] += 1;
    i++;

    while(i <= k) {
        x[i] = x[i-1] + 1;
        i++;
    }
}

void listing_configs(int k, int n) {
    int i;
    int x[k+1] {0};
    for(i = 1; i <= k; i++) {
        x[i] = i;
    }

    do{
        view_config(x, k);

        i = k;
        while(i > 0 && x[i] == n - k + i)
            i--;
        if(i > 0) {
            next_config(x,k,i);
        }
    }while(i > 0);

}


int main() {

    listing_configs(6, 7);

    
    return 0;
}
