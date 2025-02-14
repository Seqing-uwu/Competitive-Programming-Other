#include <iostream>
using namespace std;

const long long INF = 1e18; // 防止溢位
long long len[169420];

char fk(int n, long long k) {
    if (n == 1) return 'N';
    if (n == 2) return 'A';
    
    if (k <= len[n-2]) return fk(n-2, k); // 在 S(n-2) 裡
    return fk(n-1, k - len[n-2]); // 在 S(n-1) 裡
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long k;
    cin >> n >> k;

    len[1] = 1;
    len[2] = 1;
    for (int i=3; i<=n; i++) {
        len[i] = min(INF, len[i-2] + len[i-1]);
    }

    cout << fk(n, k) << "\n";
    return 0;
}
