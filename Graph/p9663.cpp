// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cmath>

using namespace std;

char arr[15][16];
int pos[15]; // �� ���
int n; // N�� �Է� �޽��ϴ�. (1 <= N <= 14) ü���� ũ��
int cnt; // ans

// �밢 Ȯ���� ���� ����迭
int dy[] = { -1,-1,+1,+1 };
int dx[] = { -1,+1,-1,+1 };

// �Ʒ��� ���� ������ �� Ž���ϸ� n=10���� ����ð��� �ſ� ���� �ɸ���.
	/*
bool isBattery(int row, int col) {

	// ���� ���� ������ false
	for (int r = 0; r < row; r++) {
		if (arr[r][col] == '#') return false;
	}
	// �밢�� ������ false
	for (int i = 1; i < n; i++) { // ���� ���� �ڸ� i = 0;�� ����
		for (int j = 0; j < 4; j++) {
			int ny = row + dy[j] * i;
			int nx = col + dx[j] * i;
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (arr[ny][nx] == '#') return false;
		}
	}
	return true;
}
	*/

bool isBattery(int row, int col) {
	for (int r = 0; r < row; r++) {
		// ���� ���� ������ false
		if (pos[r] == col) return false;

		// �밢�� ������ false
		if (row - r == abs(col - pos[r])) return false;
	}

	return true;
}

int de; // dummy for tracing
void dfs(int row) {
	de = 321;
	// ��ü Ž�������� ������ ���� cnt++ ����
	if (row == n) {
		cnt++;
		return;
	}


	for (int col = 0; col < n; col++) {
		if (isBattery(row, col) == false) continue;
		//arr[row][col] = '#';
		pos[row] = col; // ��ġ ���
		dfs(row + 1);
		//arr[row][col] = '_';
	}

	de = 231;
	return;
}

int main() {
	cin >> n;
	/*
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = '_';
	*/

	dfs(0);

	cout << cnt;

	return 0;
}