#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    for (int i = -(n-1); i <= n-1; i++) {
        int space = abs(i);
        cout << string(space, ' ') << string(2 * (n - space) - 1, '*') << "\n";
    }

    return 0;
}

// 發現對稱性 --> 嘗試利用絕對值簡化 --> 由數字整理出規律得

// Output:
//    *
//   ***
//  *****
// *******
//*********
// *******
//  *****
//   ***
//    *
