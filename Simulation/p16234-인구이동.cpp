// boj.kr/16234

/*
* 풀이 시간: 1 h 20 min
* 
* dfs 완전 탐색시
* 연합은 여러개 국지적으로 존재하면서 각 연합이 병렬적으로 인구이동을 할 수 있다.
* 
* n by n 각 격자를 start로 dfs 로 연합인 나라를 탐색 O(n*n)
* 탐색하면서 vec에 연합을 저장하고 인구 수를 갱신한다.
* q에 있는 나라 들의 인구를 이동 시킨다.
* 인구 이동이 존재했으면 날짜 cnt++
* 이걸 인구이동이 없을 때까지 최대 2000번 반복
* 
* O(n^2) -> T(n) = 2000 * n^2 = 2000 * 2500 = 5e6 < 1초
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

#define MAXN 50
#define MAXLR 100

using namespace std;

struct Node{
	int y, x;
};

int n, l, r;
int MAP[MAXN][MAXN];
int used[MAXN][MAXN];
//queue<Node> q;
vector<Node> vec;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
}

bool isOut(Node node) {
	return node.y < 0 || node.y >= n || node.x < 0 || node.x >= n;
}

bool isImigration(Node now, Node nxt) {
	int gap = abs(MAP[now.y][now.x] - MAP[nxt.y][nxt.x]);
	if (l <= gap && gap <= r) return true;
	return false;
}

void dfs(Node now) {
	for (int i = 0; i < 4; i++) {
		Node nxt = { now.y + dy[i], now.x + dx[i] };

		if (isOut(nxt)) continue;
		if (used[nxt.y][nxt.x]) continue;
		if (!isImigration(now, nxt)) continue;

		used[nxt.y][nxt.x] = true;
		vec.push_back(nxt);
		dfs(nxt);
	}
}

void imigrate() {

	int sz = vec.size();
	int popul = 0;

	for (Node nation: vec) popul += MAP[nation.y][nation.x];

	int res = popul / sz;	// 소수점 무시

	for (Node nation : vec) MAP[nation.y][nation.x] = res;
}

int main() {
	input();

	int cnt = 0;
	bool flag = false;	// 인구이동 종료 판별

	while (true) {
		memset(used, 0, sizeof(used));
		flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (used[i][j]) continue;	// dfs 를 한번 수행하면 가능한 연합은 모두 탐색하므로 건너 뛰어도 됨.

				vec.clear();
				Node start = { i, j };

				used[start.y][start.x] = true;
				vec.push_back(start);
				dfs(start);
				imigrate();

				if (vec.size() != 1) flag = true;	// 인구이동이 한번이라도 존재했다면 true
			}
		}

		if (!flag) break;	// 인구이동이 한번도 없었음. -> 완료
		cnt++;	// 하루지남.
	}

	cout << cnt;
}