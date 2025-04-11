#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 200005;
string s[N];

int found_diffs(int &n, int &m) {
	unordered_map<string, int> count;
	int diff_count = 0;
	int res = 0;
	
	int l = 0, r = 0;
	while (r < n)  {
		
		if (count[s[r]] == 0) {
			diff_count++;
		}
		count[s[r]]++;
		
		while (r - l + 1 == m) {
			if (diff_count == m) res++;
			
			count[s[l]]--;
			if (count[s[l]] == 0) {
				diff_count--;
			}
			l++;
		}
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
	}
	
	// 計算每個區間有幾個不同數字
	cout << found_diffs(n, m) << "\n";
	return 0;
}
