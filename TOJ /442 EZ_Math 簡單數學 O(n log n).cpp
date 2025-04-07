#include <iostream>
#include <algorithm>
using namespace std;

const int PR = 1e7 + 5; // Prime_Range
int minprime[PR] = {0};

// 預處理每個數的最小質因數
void found_min_pf() {
    for (int i=2; i<PR; i++) {
        if (minprime[i] == 0) {
            for (int j=i; j<PR; j+=i) {
            	if (minprime[j] == 0) minprime[j] = i;
            }
        }
    }
}

// 把 k 的所有 不同 質因數存起來, 回傳個數
int get_different_pf(int k, int a[]) {
	int count = 0;
	while (k > 1) {
		int p = minprime[k];
		a[count++] = p;
		while (k % p == 0) k /= p;
	}
	return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 預處理
    found_min_pf();
    
    int n;
    cin >> n;

    while (n--) {
    	int A;
        cin >> A;
		
		int pf[25];
        int count = get_different_pf(A, pf);
        
        if (count == 1) {
        	cout << 1 << " " << pf[0] << "\n";
        }
        else {
        	sort(pf, pf + count);
        	int a = pf[count - 2], b = pf[count - 1];
        	cout << a << " " << b << "\n";
        }
    }
    return 0;
}
