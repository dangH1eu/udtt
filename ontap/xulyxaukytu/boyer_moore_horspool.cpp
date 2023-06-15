#include <iostream>
using namespace std;

// int char_in_string(char c, string s) {
//     for(int i = 0; i < s.size(); i++) {
//         if(s[i] == c) {
//             return 1;
//         }
//     }
//     return -1;
// }
//

int char_in_string(char c, string s) {
    int i = 0;
    while(i<s.size()) {
        if(s[i] == c){
            return 1;
        }
        i++;
    }
    return -1;
}

int boyer_moore_horspool(string T, string P) {
    int count = 0;
    int i = P.size();
    int v = P.size();

    while(i <= T.size()){
        int j = i - 1;
        int x = v - 1;

        while(P[x] == T[j] && x > -1) {
            x--;
            j--;
        }

        if(x < 0) {
            count++;
            i += v;
        } else {
            int k = char_in_string(T[j],P);
            if(k < 0){
                i += v;
            } else {
                i += v - k - 1;
            }
        }

    }
    return count;
}



int main() {

    string T = "cest la vie, say the old folk, cest la vie";
    string P = "cest la vie";

    cout << T << endl << P << endl;

    cout << boyer_moore_horspool(T,P) << endl;

    return 0;
}
