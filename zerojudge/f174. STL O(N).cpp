#include <iostream>
#include <deque>
using namespace std;

const int N = 1e5+5;
int a[N], pre[N];

int getmaxsum(int n, int k) {
	// prefix_sum
	pre[0] = 0;
	for (int i=1; i<=n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	
	deque<int> dq; // save pre's idx
	dq.push_back(0);
	int ans = 0;
	
	// Monotonic Queue (to find max sum whose length <= k)
	for (int i=1; i<=n; i++) {
		// ensure len <= k
		while (!dq.empty() && dq.front() < i - k) dq.pop_front();
		// trying update ans
		if (!dq.empty()) {
			ans = max(ans, pre[i] - pre[dq.front()]);
		}
		// maintaining monotonicity
		while (!dq.empty() && pre[dq.back()] >= pre[i]) dq.pop_back();
		// add new idx
		dq.push_back(i);
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	cout << getmaxsum(n, k) << "\n";
	return 0;
}
