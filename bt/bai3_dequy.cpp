#include <iostream>
using namespace std;


void thn(int n, char c1, char c2, char c3){
    if(n == 1) cout << c1 << " -> " << c3 << endl;
    else {
        thn(n - 1, c1, c3, c2);
        thn(1, c1, c2, c3);
        thn(n - 1, c2, c1, c3);
    }
}

int main() {

    thn(3, 'a', 'b', 'c');
    
    return 0;
}
