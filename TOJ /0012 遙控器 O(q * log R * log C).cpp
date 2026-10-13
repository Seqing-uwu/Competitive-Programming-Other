#include <iostream>
using namespace std;

const int N = 3005;
int a[N][N], BIT[N][N];
int R, C;

int lowbit(int x) {
	return x & -x;
}

// 單點更新
void update(int x, int y, int diff) {
	for (int i = x; i <= R; i += lowbit(i)) {
		for (int j = y; j <= C; j += lowbit(j)) {
			BIT[i][j] += diff;
		}
	}
}

// 計算前綴和 sum(1, 1) ~ sum(x, y)
int sum(int x, int y) {
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			res += BIT[i][j];
		}
	}
	return res;
}

int range_sum(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}

void operate() {
	int q;
	cin >> q;
	
	for (int i=0; i<q; i++) {
		char ch;
		cin >> ch;
		
		if (ch == 'C') { // 單點修改
			
			int r, c, k;
			cin >> r >> c >> k;
			
			int diff = k - a[r][c];
			a[r][c] = k;
			
			update(r, c, diff);
		}
		else if (ch == 'Q') { // 區間查詢
			
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << range_sum(x1, y1, x2, y2) << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> a[i][j];
			update(i, j, a[i][j]); // 建立BIT
		}
	}
	
	operate();
	
	return 0;
}
