#include <iostream>
using namespace std;
int x[100];
int n; 
void show(){
    for(int i = 0; i < n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k) {
    for(int i = 0; i <= 1; i++) {
        x[k] = i;
        if(k == n) {
            show();
        }
        else {
            Try(k+1);
        }
    }
}

// void Try(int k) {
//     if(k == n) {
//         show();
//     }
//     else {
//         for(int i = 0; i <= 1; i++){
//             x[k] = i;
//             Try(k+1);
//         }
//     }
// }

int main() {
    cout << "n: ";
    cin >> n;

    Try(0);

    return 0;
}
