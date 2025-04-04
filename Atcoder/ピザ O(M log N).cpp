#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
int D, N, M; // 環狀線長度, 店鋪個數, 訂單個數
int d[MAX_N]; // 店鋪位置
long long Left, Right;

// 逆時針找最接近的
void found_left(int l, int r, int k) {
	if (l > r) return;
	
	int mid = (l+r)/2;
	
	if (d[mid] == k) {
		Left = 0;
		return; // 剛好等於的話距離為 0 直接return
	}
	else if (d[mid] > k) {
		Left = d[mid] - k; // 如果大於, 紀錄距離
		found_left(l, mid-1, k); // 找有沒有更接近 k 的地點
	}
	else if (d[mid] < k) {
		found_left(mid+1, r, k); // 如果小於, 則往後找
	}
}

// 順時針找最接近的
void found_right(int l, int r, int k) {
	if (l > r) return;
	
	int mid = (l+r)/2;
	
	if (d[mid] == k) {
		Right = 0;
		return; // 剛好等於的話距離為 0 直接return
	}
	else if (d[mid] > k) {
		found_right(l, mid-1, k); // 如果大於, 則往前找
	}
	else if (d[mid] < k) {
		Right = k - d[mid]; // 如果小於, 紀錄距離
		found_right(mid+1, r, k); // 找有沒有更接近 k 的地點
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> D >> N >> M;
	
	d[0] = 0;
	for (int i=1; i<N; i++) {
		cin >> d[i]; // 輸入店鋪位置
	}
	
	sort(d, d+N); // 店鋪編號沒差, 只要找距離每個宅配地點最近的就好
	// 排序具有單調性即可用二分搜 <3
	
	int k;
	long long min_move = 0;
	for (int i=0; i<M; i++) {
		cin >> k; // 輸入宅配地點
		
		// 預設為到 S1 的距離
		Left = D - k;
		Right = k;
		found_left(0, N-1, k);
		found_right(0, N-1, k);
		
		min_move += min(Left, Right);
	}
	
	cout << min_move << "\n";
	return 0;
}
