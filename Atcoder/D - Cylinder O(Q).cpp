#include <iostream>
#include <deque>
using namespace std;

using ll = long long;
deque<pair<ll, ll> > dq;

// 計算從左邊取球的值總和
ll popsum(ll &c) {
	ll sum = 0;
	while (c > 0) {
		ll diff = min(c, dq.front().second);
		c -= diff;
		sum += diff * dq.front().first;
		
		if (diff == dq.front().second) dq.pop_front();
		else dq.front().second -= diff;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int Q;
	cin >> Q;
	
	
	while (Q--) {
		int n;
		cin >> n;
		
		if (n == 1) {
			int x, c;
			cin >> x >> c;
			dq.push_back({x, c});
		}
		else if (n == 2) {
			ll c;
			cin >> c;
			// 從左邊取球並且輸出總和
			cout << popsum(c) << "\n";
		}
	}
	return 0;
}
