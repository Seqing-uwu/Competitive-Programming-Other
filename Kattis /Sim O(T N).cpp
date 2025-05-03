#include <iostream>
using namespace std;

const int N = 1e6+5;
const int END = -1, HEAD = 0;

char elem[N];
int nxt[N], pre[N];
int pt, cursor, tail;
string op;

void init() {
	pt = 1;
	cursor = HEAD;
	tail = HEAD;
	nxt[HEAD] = END;
	pre[HEAD] = END;
}

void insert(const char &c) {
	int cur = pt++; // 紀錄 idx
	elem[cur] = c;
	nxt[cur] = nxt[cursor];
	pre[cur] = cursor;
	// 不是最後一個元素時，要將下一個元素的 pre 接到插入的這個元素
	if (nxt[cursor] != END) pre[nxt[cursor]] = cur;
	nxt[cursor] = cur;
	cursor = cur;
	if (nxt[cur] == END) tail = cur; // 插入為最後一個時才更新 tail
}

void remove() {
	if (cursor == HEAD || cursor == END) return;
	int cur = cursor; // 要刪掉的 idx
	cursor = pre[cur]; // 游標退到上一個
	nxt[cursor] = nxt[cur]; // 把「新位置」的 nxt 指向下一個節點，跳過 cur。
	// 如果刪掉的是最後一個，tail 就往前移
	if (cur == tail) tail = pre[cur];
	// 如果 cur 後面還有東西，就把它的 pre 也改成新的位置，斷開和 cur 的連結。
	if (nxt[cur] != END) pre[nxt[cur]] = cursor;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	cin.ignore();
	
	while (T--) {
		// 初始化與輸入字串
		init();
		getline(cin, op);
		
		for (char c : op){
			if (c == '<') {
				remove();
			}
			else if (c == '[') {
				// 跳到頭
				cursor = HEAD;
			}
			else if (c == ']') {
				// 跳到尾
				cursor = tail;
			}
			else {
				insert(c);
			}
		}
		
		for (int cur = nxt[HEAD]; cur != END; cur = nxt[cur]) {
			cout << elem[cur];
		}
		cout << "\n";
	}
	return 0;
}
