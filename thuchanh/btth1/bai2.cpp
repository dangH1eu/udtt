#include <iostream>
using namespace std;

int n;
char x[100];
char data[] = {'a','b'};

void show(){
    for(int i = 0; i < n; i++) {
        cout << x[i];
    }
    cout << endl;
}


void Try(int k) {
    for(int i = 0; i <= 1; i++) {
        x[k] = data[i];
        if(k == n) {
            show();
        }
        else {
            Try(k+1);
        }
    }
}

int main() {

    cout << "n = ";
    cin >> n;
    Try(0);
    return 0;
}
