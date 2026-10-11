// 題目: KATTIS - Eeny Meeny
// 難度: 1.7 EASY
// 標籤: #vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string rhyme, s;
    int n;
    getline(cin, rhyme);
    cin >> n;

    int t = count(rhyme.begin(), rhyme.end(), ' '); // 計算 rhyme 空格數，相當於要跨過的人數

    vector<string> names(n), team_A, team_B;
    for (int i = 0; i < n; i++) cin >> names[i];

    int i = 0;
    while (!names.empty()) {
        i = (i + t) % names.size();
        // 利用隊伍人數的奇偶性質判斷
        if (team_A.size() == team_B.size()) {
            team_A.push_back(names[i]);
        } else {
            team_B.push_back(names[i]);
        }
        names.erase(names.begin() + i);
    }

    cout << team_A.size() << "\n";
    for (const string &ng : team_A) cout << ng << "\n"; // 使用 const reference 避免複製字串

    cout << team_B.size() << "\n";
    for (const string &ng : team_B) cout << ng << "\n";

    return 0;
}
