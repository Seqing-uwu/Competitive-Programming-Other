#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 15;

char chs[MAX][MAX]; // 存輸入
string cols[MAX]; // 抽 chs[] 的列 作字串

bool comp(const string &a, const string &b) {
	int n = a.size();
	for (int i=0; i<n; i++) {
		// 統一化為小寫
		char ca = tolower(a[i]);
		char cb = tolower(b[i]);
		
		if (ca < cb) return true;
		if (ca > cb) return false;
	}
	// 相同則維持穩定排序
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	while (cin >> R >> C && (R != 0 && C != 0)) {
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				cin >> chs[r][c];
			}
		}
		
		// 把 col 抽出來作字串
		for (int c=0; c<C; c++) {
			cols[c] = "";
			for (int r=0; r<R; r++) {
				cols[c] += chs[r][c];
			}
		}
		
		// 橫列排序
		stable_sort(cols, cols+C, comp);
		
		// 橫向輸出
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				cout << cols[c][r];
			}
			cout << "\n";
		}
		
		cout << "\n";
	}
	
	return 0;
}
