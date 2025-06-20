#include <iostream>
using namespace std;

int tbl[128];
char path[128];
string a = {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};

void dfs(int depth, int len) {
	if (depth == len) {
		path[depth] = 0; // 刪掉多的
		cout << path << "\n";
		return;
	}
	
	for (char c : a) {
		int i = int(c);
		if (tbl[i]) {
			tbl[i]--;
			path[depth] = i;
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
	
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		
		for (int i='A'; i<='z'; i++) {
			tbl[i] = 0;
		}
		
		int len = s.size();
		for (int i=0; i<len; i++) {
			tbl[s[i]]++;
		}
		
		dfs(0, len);
	}
	return 0;
}
