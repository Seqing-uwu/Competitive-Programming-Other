#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    
    while (cin >> n) {
        for (int i = -(n-1); i <= n-1; i++) {
            int space = abs(i);
            int chars = 2 * (n - space) - 1;
            cout << string(space, ' ');
            
            for (int j = 0; j < chars; j++) {
                int dis_from_edge = min(chars - j -1, j);
                cout << char(dis_from_edge + 'A');
            }
            cout << "\n";
        }
    }

    return 0;
}
// O(n^2)
