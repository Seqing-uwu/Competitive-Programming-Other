#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000069;
int a[N];

// 找到小於 k 的最大值
int left(int l, int r, int k) {
	while (l < r) {
		int m = (l+r)/2;
		if (a[m] >= k) r = m;
		else l = m+1;
	}
	return l;
}
// 找大於 k 的最小值
int right(int l, int r, int k) {
	while (l < r) {
		int m = (l+r)/2;
		if (a[m] <= k) l = m+1;
		else r = m;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	sort(a, a+n);
	
	int m; cin >> m;
	int k;
	
	for (int i=0; i<m; i++) {
		cin >> k;
		int count = right(0, n, k) - left(0, n, k);
		cout << count << "\n";
	}
	
	return 0;
}
