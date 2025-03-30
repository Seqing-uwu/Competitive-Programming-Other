#include <iostream>
#include <cstring>
using namespace std;

const int N = 77;
int dp[N];

int countSubsDP(int n) {
	dp[n+1] = 0;
	dp[n] = dp[n-1] = 1;
	for (int i=n-2; i>=1; i--) {
		dp[i] = dp[i+2] + dp[i+3];
	}
	return dp[1] + dp[2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while (cin >> n) {
		memset(dp, -1, sizeof(dp));
		cout << countSubsDP(n) << "\n";
	}
	return 0;
}
