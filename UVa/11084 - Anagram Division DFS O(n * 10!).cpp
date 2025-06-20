#include <iostream>
using namespace std;

int tbl[10];
char path[128];
int d;
long long cnt;

void dfs(int depth, int len) {
	if (depth == len) {
		long long res = 0;
		for (int i = 0; i < len; i++) {
			res = res * 10 + (path[i] - '0');
		}
		if (res % d == 0) cnt++;
		return;
	}
	
	bool used[10] = {0}; // 每層記錄用過的數字，防止重複
	for (int i = 0; i < 10; i++) {
		if (tbl[i] && !used[i]) {
			used[i] = true;
			tbl[i]--;
			path[depth] = i + '0';
			dfs(depth + 1, len);
			tbl[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s >> d;

		for (int i = 0; i < 10; i++) {
			tbl[i] = 0;
		}
		
		for (char c : s) {
			tbl[c - '0']++;
		}
		
		cnt = 0;
		dfs(0, s.size());
		cout << cnt << "\n";
	}
	return 0;
}
