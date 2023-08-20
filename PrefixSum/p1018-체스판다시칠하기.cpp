// loop 로 완전탐색하여 풀 수도 있으나 Prefix로 풀면 시간복잡도가 눈에 띄게 달라진다.

// (row + col) % 2 == 0 이면 체스판의 시작점인 왼쪽위(0,0) 과 색이 같아야함을 생각하는 게 힘들었다.

#include <iostream>
#include <algorithm>

#define MAXNM 50

using namespace std;

int n, m;
char board[MAXNM][MAXNM + 1];	// 마지막 열 '\n'
int prefix[MAXNM + 1][MAXNM + 1];
int min_cnt = 21e8;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
}

bool haveToSameWithStart(int row, int col) {
	return !((row + col) % 2);
}

void makePrefix(char start) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

			if (haveToSameWithStart(i, j)) {			// start랑 같은 색이어야 하는데
				if (board[i - 1][j - 1] != start) {	// 다르다. -> 다시 칠해야함.
					prefix[i][j] += 1;
				}
			}
			else {									// start랑 다른 색이어야 하는데
				if (board[i - 1][j - 1] == start) { // 같다. -> 다시 칠해야함.
					prefix[i][j] += 1;
				}
			}
		}
	}
}

void updateMin() {
	for (int i = 8; i <= n; i++) {
		for (int j = 8; j <= m; j++) {
			// 8 by 8 체스판 잘라서 체킹
			int cnt = prefix[i][j] - (prefix[i - 8][j] + prefix[i][j - 8] - prefix[i - 8][j - 8]);
			min_cnt = min(min_cnt, cnt);
		}
	}
}

int main() {
	input();

	makePrefix('W');
	updateMin();
	makePrefix('B');
	updateMin();

	cout << min_cnt;

	return 0;
}