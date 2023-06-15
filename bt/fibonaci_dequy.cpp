#include <iostream>
using namespace std;

long fibonaci(int n) {
    if(n < 3) return 1;
    else return fibonaci(n - 1) + fibonaci(n - 2);

}

long fibonaci2(int n) {
    int fn, fn1 = 1, fn2 = 1;
    for(int i = 3; i <= n; i++) {
        fn = fn1 + fn2;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}
long f[100]{0};
long fibonaci3(int n) {

    if(n < 3) {
        return 1;
    } else {
        if(f[n] != 0)
            return f[n];
        else return f[n] = fibonaci3(n-1) + fibonaci3(n-2);
    }
}

int main() {

    cout << fibonaci(7) << endl;
    cout << fibonaci2(25) << endl;
    cout << fibonaci3(7) << endl;
    return 0;
}
