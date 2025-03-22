#include <iostream>
#include <algorithm>
using namespace std;

const int n = 13;
string E[n], S[n], W[n], N[n]; // 存四家手牌

bool comp(const string &a, const string &b) {
	string order = "CDSH"; // 花色排序
	string porder = "23456789TJQKA"; // 點數排序
	int ca = order.find(a[0]);
	int cb = order.find(b[0]);
	
	if (ca == cb) { // 如果花色相同就比點數
		return porder.find(a[1]) < porder.find(b[1]);
	}
	return ca < cb;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		char start; cin >> start;
		if (start == '#') break;
		
		int num;
		if (start == 'E') num = 1; // E -> S 開始
		else if (start == 'S') num = 2; // 同理, 略
		else if (start == 'W') num = 3;
		else num = 0;
		
		char color, point;
		int e = 0, s = 0, w = 0, n = 0; // 各家手牌索引
		
		// 輸入
		for (int i=0; i<52; i++) {
			cin >> color >> point;
			string card = "";
			card += color;
			card += point;
			
			if (num % 4 == 0) {
				E[e++] = card;
			}
			else if (num % 4 == 1) {
				S[s++] = card;
			}
			else if (num % 4 == 2) {
				W[w++] = card;
			}
			else if (num % 4 == 3) {
				N[n++] = card;
			}
			num++;
		}
		
		// 排序手牌
		sort(E, E+13, comp); sort(S, S+13, comp);
		sort(W, W+13, comp); sort(N, N+13, comp);
		
		// 輸出
		cout << "S: " << S[0];
		for (int i=1; i<13; i++) {
			cout << " " << S[i];
		}
		cout << "\nW: " << W[0];
		for (int i=1; i<13; i++) {
			cout << " " << W[i];
		}
		cout << "\nN: " << N[0];
		for (int i=1; i<13; i++) {
			cout << " " << N[i];
		}
		cout << "\nE: " << E[0];
		for (int i=1; i<13; i++) {
			cout << " " << E[i];
		}
		cout << "\n";
	}
	
	return 0;
}
