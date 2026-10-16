// 2026/10/16 在這題拿下我在 TOJ 第一個 Top Coder QQQ 一直哭
// 前前後後磨了好久，主要是在想更好的求中點方法，感覺還是太菜
// 不對呀，為什麼這個已畢業的老人在寫 114 高一期末考 (X)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    double sx, sy, k, p;
    cin >> sx >> sy >> k >> p;
    double move_dist = k * p; // 最大移動距離

    double x[4], y[4]; // 讀入正方形四個頂點座標 (可能亂序)
    for (int i=0; i<4; i++) cin >> x[i] >> y[i];
    // sorry 真想不到更好的寫法
    double cnma = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2)); // A(x[0], y[0]) 到 B(x[1], y[1]) 的距離，往下同理
    double cnmb = sqrt(pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2));
    double cnmc = sqrt(pow(x[0] - x[3], 2) + pow(y[0] - y[3], 2));
    double mx, my; // 邊長中點
    // 若 AB 不是最長，則 B 一定與 A 相鄰
    if (cnma < cnmb || cnma < cnmc) {
        mx = (x[0] + x[1]) / 2.0;
        my = (y[0] + y[1]) / 2.0;
    } else { // 若 AB 最長，則 A 一定與 C D 相鄰 (取C)
        mx = (x[0] + x[2]) / 2.0;
        my = (y[0] + y[2]) / 2.0;
    }
    // 內接圓圓心就是正方四頂點相加平均
    double cx = (x[0] + x[1] + x[2] + x[3]) / 4.0, cy = (y[0] + y[1] + y[2] + y[3]) / 4.0;
    double R = sqrt(pow(cx - mx, 2) + pow(cy - my, 2)); // 半徑 = 圓心到正方形中點距離

    double d = sqrt(pow(cx - sx, 2) + pow(cy - sy, 2)); // 自己與圓心的距離
    double required_dist = (d >= R) ? 0.0 : (R - d); // 需要移動多少才能逃脫

    if (move_dist >= required_dist) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
