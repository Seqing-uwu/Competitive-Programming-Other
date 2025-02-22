#include<iostream>
using namespace std;

const int N = 169420;
const int END = -1, HEAD = 0;

string elem[N]; // 每個節點的字串
int nxt[N]; // 每個節點的下一個節點
int head[N], tail[N]; // 每個串列的頭尾
int pt; // 目前可用的心結點

void init(int n) {
	pt = 1;
	for (int i=1; i<=n; i++) {
		head[i] = tail[i] = pt;
		nxt[pt] = END;
		cin >> elem[pt++];
	}
}

// 連接 b 到 a 尾，然後清空 b
void link(int a, int b) {
	nxt[tail[a]] = head[b]; // a 尾指向 b 頭
	tail[a] = tail[b]; // 更新 a 的尾為 b 的尾巴
	head[b] = END;
}

// output
void letsgogogogogogogogo(int n) {
	for (int i=1; i<=n; i++) {
		if (head[i] != END) { // 找到還存活的串列
			for (int cur = head[i]; cur != END; cur = nxt[cur]) {
				cout << elem[cur];
			}
			cout << "\n";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	init(n);
	
	for (int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		link(a, b);
	}
	
	letsgogogogogogogogo(n);
	return 0;
}
