#include <iostream>
using namespace std;

const int N = 30;
int pows2[N];

// 預處理 2 的次方
void pre_2_powers() {
	pows2[0] = 1;
	for (int i=1; i<N; i++) {
		pows2[i] = pows2[i-1] * 2;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	pre_2_powers();
	
	int T;
	cin >> T;
	
	while (T--) {
		int a, b;
		cin >> a >> b;
		
		int min_x = 0, min_y = 0;
		int max_x = 0, max_y = 0;
		bool found_first_diff = false;
		
		for (int i=N-1; i>=0; i--) {
			bool bit_a = (a & pows2[i]) > 0;
			bool bit_b = (b & pows2[i]) > 0;
			
			// a b 相同, x y 也要相同
			if (bit_a == bit_b) {
				min_x += pows2[i];
				min_y += pows2[i];
				max_x += pows2[i];
				max_y += pows2[i];
			}
			else {
				if (!found_first_diff) {
					// 第一個不同給 min_x 其他全部給 min_y
					min_x += pows2[i];
					// 全部給 max_x
					max_x += pows2[i];
				}
				else {
					min_y += pows2[i];
					max_x += pows2[i];
				}
				found_first_diff = true;
			}
		}
		
		cout << max_x - max_y << " " << min_x - min_y << "\n";
	}
	
	return 0;
}
