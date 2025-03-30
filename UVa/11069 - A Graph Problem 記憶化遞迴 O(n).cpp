#include <iostream>
#include <cstring>
using namespace std;

const int N = 77;
int dp[N];

int countSubs(int i, int n) {
	if (i > n) return 0;
	if (i == n || i == n-1) return 1;
	if (dp[i] != -1) return dp[i];
	return dp[i] = countSubs(i+2, n) + countSubs(i+3, n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n) {
		memset(dp, -1, sizeof(dp));
		cout << countSubs(1, n) + countSubs(2, n) << "\n";
	}
	return 0;
} // 題外, 考量到這題的 n 只有到 76, 其實也可以把每個算出來後存起來, 到時候直接查表就好
