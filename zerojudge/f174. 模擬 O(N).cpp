#include <iostream>
using namespace std;

const int N = 1e5+5;
int a[N], pre[N];
int dq[N]; // 存 pre 的 idx
int front = 0, back = -1;

int prefix_sum(int n, int k) {
	// 計算前綴和
	pre[0] = 0;
	for (int i=1; i<=n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	
	int ans = 0;
	for (int i=1; i<=n; i++) {
		// 移除超出 k 範圍的
		while (front <= back && dq[front] < i-k) front++;
		// 計算最大值
		if (front <= back) {
			ans = max(ans, pre[i] - pre[dq[front]]);
		}
		// 維持單調性
		while (front <= back && pre[dq[back]] >= pre[i]) back--;
		// 更新 dq
		back++;
		dq[back] = i;
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
	
	cout << prefix_sum(n, k) << "\n";
	return 0;
}
