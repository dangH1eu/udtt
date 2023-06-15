#include <iostream>
using namespace std;

int n;
int x[100];
bool check[100] {false};

void show(){
    for(int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void action(int k) {
    for(int i = 1; i <= n; i++) {
        if(!check[i]) {
            x[k] = i;
            check[i] = true;

            if(k == n)
                show();
            else
             action(k+1);

            check[i] = false;
        }
    }
}

int main() {

    n = 5;
    action(1);
}

