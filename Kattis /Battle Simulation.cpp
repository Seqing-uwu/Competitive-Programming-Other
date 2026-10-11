// Problem: KATTIS - Battle Simulation
// Difficultly: 2.2 EASY
// Tags: #vector
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> atk;
    char t; int i = 0;

    while (cin >> t) {
        atk.push_back(t);
        if (i >= 2) {
            int R=0, B=0, L=0;
            for (int j = i; j > i-3; j--) {
                if (atk[j] == 'R') R = 1;
                if (atk[j] == 'B') B = 1;
                if (atk[j] == 'L') L = 1;
            }
            if (R && B && L) {
                atk.pop_back();
                atk.pop_back();
                atk.pop_back();
                atk.push_back('C');
                i -= 2;
            }
        }
        i += 1;
    }

    for (char c : atk) {
        if (c == 'R') cout << 'S';
        else if (c == 'B') cout << 'K';
        else if (c == 'L') cout << 'H';
        else cout << c;
    }

    cout << "\n";
    return 0;
}
