#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;
string s[N], temp[N];
int diffs[N] = {0}; // 紀錄區間內不同的數字數量

int cal(int l, int r, const string &a, const string &b) {
	int mid = (l+r)/2;
	bool found_a = false, found_b = false;
	
	while (l < r) {
		if (temp[mid] == a) {
			found_a = true;
			break;
		}
		else if (temp[mid] > a) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	
	mid = (l+r)/2;
	while (l < r) {
		if (temp[mid] == b) {
			found_b = true;
			break;
		}
		else if (temp[mid] > b) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	
	int res = 0;
	if (!found_a) {
		res--;
	}
	if (!found_b) {
		res++;
	}
	
	return res;
}

int found_diffs(int &n, int &m) {
	// 先排序第一組
	sort(s, s+m);
	// 再計算不同的數字
	for (int i=1; i<m; i++) {
		if (s[i] != s[i-1]) diffs[0]++;
	}
	
	int res = 0;
	int l = 1, r = m;
	while (r < n) {
		if (s[l-1] == s[r] && s[l-1] == s[l]) {
			diffs[l] = diffs[l-1];
		}
		else {
			sort(temp+l, temp+r);
			int dif = cal(l, r, s[l-1], s[r]);
			// 當不等於時, 有三種情況
			// -1 若區間內沒有 s[l-1]
			// +1 若區間內沒有 s[r]
			diffs[l] = diffs[l-1] + dif;
		}
		
		if (diffs[l] == m) res++;
		
		l++;
		r++;
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	for (int i=0; i<n; i++) {
		cin >> s[i];
		temp[i] = s[i];
	}
	
	// 計算每個區間有幾個不同數字
	cout << found_diffs(n, m) << "\n";
	return 0;
}
