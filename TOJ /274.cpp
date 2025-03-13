#include <iostream>
using namespace std;

string s; 

bool neko(int l, int r, bool removed) {
	while (l < r) {
		if (s[l] != s[r]) {
			if (removed) return false;
			
			return neko(l+1, r, true) or neko(l, r-1, true); // 刪去 左 或 右 其中一個仍是回文就好
		}
		l++; r--;
	}
	
	return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    while (n--) {
    	cin >> s;
    	
    	if (neko(0, s.size() - 1, false)) cout << "YES\n";
    	else cout << "NO\n";
    }
    
    return 0;
}
