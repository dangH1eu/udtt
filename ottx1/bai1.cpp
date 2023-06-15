#include <iostream>
using namespace std;

string list[] = {"tung", "truc", "cuc", "mai"};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void view_config(int *x, int n) {
    for(int i = 1; i <= n; i++){
        cout << list[x[i]-1] << "\t";
        }
    cout << endl;
}

void next_config(int *x, int n, int i) {
    int k = n;
    while (x[k] < x[i]) {
        k--;
    }

    swap(x[i],x[k]);
    int j = n;
    i++;
    while(i < j) {
        swap(x[i],x[j]);
        i++;
        j--;
    }
}

void listing_configs(int n) {
    int i;
    int x[n+1] {0};

    for(i = 1; i <= n; i++) {
        x[i] = i;
    }

    do{
        view_config(x,n);

        i = n - 1;

        while(i > 0 && x[i] > x[i+1]) 
            i--;

        if(i > 0){
            next_config(x,n,i);
        }

    }while(i > 0);
}



int main() {

    cout << "A\tB\tC\tD\n";
    listing_configs(4);

    return 0;
}
