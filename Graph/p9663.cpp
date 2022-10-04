// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cmath>

using namespace std;

char arr[15][16];
int pos[15]; // 열 기록
int n; // N을 입력 받습니다. (1 <= N <= 14) 체스판 크기
int cnt; // ans

// 대각 확인을 위한 방향배열
int dy[] = { -1,-1,+1,+1 };
int dx[] = { -1,+1,-1,+1 };

// 아래와 같이 말판을 다 탐색하면 n=10부터 실행시간이 매우 오래 걸린다.
	/*
bool isBattery(int row, int col) {

	// 같은 열에 있으면 false
	for (int r = 0; r < row; r++) {
		if (arr[r][col] == '#') return false;
	}
	// 대각에 있으면 false
	for (int i = 1; i < n; i++) { // 지금 놓은 자리 i = 0;은 제외
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
		// 같은 열에 있으면 false
		if (pos[r] == col) return false;

		// 대각에 있으면 false
		if (row - r == abs(col - pos[r])) return false;
	}

	return true;
}

int de; // dummy for tracing
void dfs(int row) {
	de = 321;
	// 전체 탐색했으면 가능한 경우로 cnt++ 리턴
	if (row == n) {
		cnt++;
		return;
	}


	for (int col = 0; col < n; col++) {
		if (isBattery(row, col) == false) continue;
		//arr[row][col] = '#';
		pos[row] = col; // 위치 기록
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