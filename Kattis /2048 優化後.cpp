#include<iostream>
using namespace std;

int board[10][10];
const int N = 4;

// 用同個函式統一轉換
void rotateBoard(int n) {
	int tmp[N][N] = {0};
	
	// 逆時針轉90度
	if (n == 1) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				tmp[i][j] = board[j][N-i-1];
			}
		}
	}
	// 水平翻轉
	else if (n == 2) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				tmp[i][j] = board[i][N-j-1];
			}
		}
	}
	// 順時針轉90度
	else if (n == 3) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				tmp[i][j] = board[N-j-1][i];
			}
		}
	}
	// 把轉完的寫回原陣列
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

// 讓一列依照 2048 規則向左滑動
void slideLeft(int row[]) {
    int temp[N] = {0}; // 用來存放處理後的數列
    int p = 0; // temp 的索引

    // Step 1: 移除 0，將非 0 數字向左壓縮
    for (int j=0; j<N; j++) {
    	if (row[j] != 0) {
    		temp[p++] = row[j];
    	}
    }
    // Step 2: 合併相鄰相同的數字
    for (int j=0; j<N-1; j++) {
        if (temp[j] != 0 && temp[j] == temp[j+1]) {
            temp[j] *= 2;   // 合併
            temp[j+1] = 0; // 被合併的數變成 0
        }
    }
    // Step 3: 再次移除 0
    int ts[N] = {0}, pos = 0;
    for (int j=0; j<N; j++) {
    	if (temp[j] != 0) {
    		ts[pos++] = temp[j];
    	}
    }
    // 將處理後的結果寫回原陣列
    for (int j=0; j<N; j++) {
    	row[j] = ts[j];
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    for (int i=0; i<N; i++) {
    	for (int j=0; j<N; j++) {
    		cin >> board[i][j];
    	}
    }
    int n;
    cin >> n;
    
    // 判斷怎麼轉
    if (n != 0) rotateBoard(n);
    // 處理每一列 (左滑)
    for (int i=0; i<N; i++) {
        slideLeft(board[i]);
    }
    // 轉回去
    if (n != 0) rotateBoard(4-n);
    
    for (int i=0; i<N; i++) {
    	cout << board[i][0];
    	for (int j=1; j<N; j++) {
    		cout << " " << board[i][j];
    	}
    	cout << "\n";
    }
    return 0;
}
