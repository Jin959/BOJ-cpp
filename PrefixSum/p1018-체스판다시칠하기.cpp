// loop �� ����Ž���Ͽ� Ǯ ���� ������ Prefix�� Ǯ�� �ð����⵵�� ���� ��� �޶�����.

// (row + col) % 2 == 0 �̸� ü������ �������� ������(0,0) �� ���� ���ƾ����� �����ϴ� �� �������.

#include <iostream>
#include <algorithm>

#define MAXNM 50

using namespace std;

int n, m;
char board[MAXNM][MAXNM + 1];	// ������ �� '\n'
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

			if (haveToSameWithStart(i, j)) {			// start�� ���� ���̾�� �ϴµ�
				if (board[i - 1][j - 1] != start) {	// �ٸ���. -> �ٽ� ĥ�ؾ���.
					prefix[i][j] += 1;
				}
			}
			else {									// start�� �ٸ� ���̾�� �ϴµ�
				if (board[i - 1][j - 1] == start) { // ����. -> �ٽ� ĥ�ؾ���.
					prefix[i][j] += 1;
				}
			}
		}
	}
}

void updateMin() {
	for (int i = 8; i <= n; i++) {
		for (int j = 8; j <= m; j++) {
			// 8 by 8 ü���� �߶� üŷ
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