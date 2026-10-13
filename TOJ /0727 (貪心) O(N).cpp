#include <iostream>
using namespace std;

const int N = 1e6+5;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, M;
	cin >> n >> M;
	
	for (int i=0; i<n; i++) cin >> a[i];
	
	long long total = 0;
	for (int i=0; i<n-1; i++) {
		int sum = a[i] + a[i+1];
		if (sum > M) {
			// 超過 M 的量 / 要拿走的量
			int excess = sum - M;
			
			// 先從 右邊 拿
			int take = min(excess, a[i+1]);
			a[i+1] -= take;
			excess -= take;
			total += take;
			
			// 拿不夠的再從 左邊 拿
			a[i] -= excess;
			total += excess;
		}
	}
	
	cout << total << "\n";
	return 0;
}
