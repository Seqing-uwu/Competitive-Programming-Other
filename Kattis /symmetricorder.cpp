#include<iostream>
using namespace std;

string s[30], sb[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n, times = 1;
	
    while (cin >> n) {
        if (!n) break;
    
        cout << "SET " << times++ << "\n";
		
        int maxl = 0, len;
        for (int i=0; i<n; i++) {
            cin >> s[i];
            len = s[i].size();
            if (len > maxl) maxl = len;
        }
		
        int l = 0, r = n-1, pos = 0;
        for (int i=1; i<=maxl; i++) {
            for (int j=0; j<n; j++) {
                len = s[j].size();
				
                // 偶數放前面, 奇數放後面
                if (len == i) {
                    if (pos % 2 == 0) {
                    sb[l] = s[j];
                    l++;
                    } else {
                    sb[r] = s[j];
                    r--;
                    }
                    pos++;
                }
                if (pos == n) goto next;
            }
        }
        next:;

        for (int i=0; i<n; i++) {
            cout << sb[i] << "\n";
        }
    }
    
    return 0;
}
