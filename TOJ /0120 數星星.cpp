#include<iostream>
using namespace std;

long long stars[200069], sum[200069] = {0}; // 留意long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> stars[i];
		sum[i] = sum[i-1] + stars[i];
	}
	
	int q; cin >> q;
	int a, b;
	for (int i=1; i<=q; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b); // a b 大小未知
		cout << sum[b] - sum[a-1] << "\n";
	}
	
	return 0;
}
