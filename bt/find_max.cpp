#include <iostream>
using namespace std;

// int findMax(int *x, int low, int high) {
//     if(low == high) return x[low];
//     else {
//         int mid = (low + high)/2;
//         int maxLeft = findMax(x,low,mid);
//         int maxRight = findMax(x,mid+1,high);
//         if(maxLeft > maxRight)
//             return maxLeft;
//         else return maxRight;
//     }
// }

int findMax(int *x, int low, int high) {
  if (low == high)
    return x[low];
  int mid = (low + high) / 2;
  int maxLeft = findMax(x, low, mid);
  int maxRight = findMax(x, mid + 1, high);
  if (maxLeft > maxRight)
    return maxLeft;
  else
    return maxRight;
}

int main() {

  int a[10]{1, 2, 4, 23, 4, 6, 2, 3, 3, 2};

  cout << findMax(a, 0, 9);

  return 0;
}
