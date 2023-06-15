#include <iostream>
using namespace std;;

float luythua(float a, int n){

    if(n == 1) return a;
    else {
        float temp = luythua(a,n/2);
        if(n % 2 == 0) {
           return temp*temp; 
        }
        else return temp*temp*a;
    }
}

int main() {

    cout << luythua(2,5);


    return 0;
}
