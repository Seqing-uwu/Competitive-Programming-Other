#include<iostream>
using namespace std;

const int N = 2000000;
const int END = -1;
const int HEAD = 0;

char a[N];
int nxt[N], pre[N];
int pt, cursor;

void init() {
	pt = 1;
	nxt[HEAD] = END;
	pre[HEAD] = END;
	cursor = HEAD;
}

void remove() {
	if (cursor == HEAD) return;
	
	int cur = cursor;
	cursor = pre[cur];
	
	nxt[cursor] = nxt[cur];
	if (nxt[cur] != END) pre[nxt[cur]] = cursor;
}

void insert(const char c) {
	int cur = pt++;
	a[cur] = c;
	
	nxt[cur] = nxt[cursor];
	pre[cur] = cursor;
	if (nxt[cursor] != END) pre[nxt[cursor]] = cur;
	nxt[cursor] = cur;
	
	cursor = cur;
}

string process(const string &s) {
	init();
	
	for (char c : s) {
		if (c == 'L') {
			cursor = pre[cursor];
		} else if (c == 'R') {
			cursor = nxt[cursor];
		} else if (c == 'B') {
			remove();
		} else {
			insert(c);
		}
	}
	
	string res = "";
	for (int cur = nxt[HEAD]; cur != END; cur = nxt[cur]) {
		res += a[cur];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s; cin >> s;
	cout << process(s) << "\n";
	return 0;
}
