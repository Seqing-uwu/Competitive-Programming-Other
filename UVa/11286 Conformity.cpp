#include <iostream>
#include <algorithm>
using namespace std;

struct combo {
	int course[5];
};

const int N = 10000;
combo a[N];

bool comp(const combo &a, const combo &b) {
	for (int i=0; i<5; i++) {
		if (a.course[i] != b.course[i]) {
			return a.course[i] < b.course[i];
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<5; j++) {
				cin >> a[i].course[j];
			}
			sort(a[i].course, a[i].course+5); // 排序學生的課程編序
		}
		
		sort(a, a+n, comp); // 排序課程組合
		
		int max_count = 0, count = 1;
		int students = 0;
		
		for (int i=1; i<n; i++) {
			bool same = true;
			for (int j=0; j<5; j++) {
				if (a[i].course[j] != a[i-1].course[j]) {
					same = false;
					break;
				}
			}
			
			if (same) {
				count++;
			}
			else {
				if (count > max_count) {
					max_count = count;
					students = count;
				}
				else if (count == max_count) {
					students += count; // 當最多人選的課程組合有複數個時, 要把這些並列第一的課程組合的人數都加起來
				}
				count = 1;
			}
		}
		
		// 計算最後一組
		if (count > max_count) {
			students = count;
		}
		else if (count == max_count) {
			students += count;
		}
		
		cout << students << "\n";
	}
	return 0;
}
