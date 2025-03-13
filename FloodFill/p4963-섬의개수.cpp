// boj.kr/4963, T -> O(WH) ~ 2500 < 1초

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAXWH 50

int w, h;
int MAP[MAXWH][MAXWH];
int used[MAXWH][MAXWH];
bool is_end = false;
int cnt;

int dy[] = { 0, -1, 0, 1, 1, -1, 1, -1 };
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

struct Node {
	int y, x;
} start;

void init() {
	cnt = 0;
	memset(MAP, 0, sizeof(MAP));
	memset(used, 0, sizeof(used));
}

void input() {
	cin >> w >> h;

	if (w == 0 && h == 0) {
		is_end = true;
		return;
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> MAP[y][x];
		}
	}
}

bool isOut(Node node) {
	return node.y < 0 || node.y >= h || node.x < 0 || node.x >= w;
}

void dfs(Node now) {
	// base condition 없음.

	for (int i = 0; i < 8; i++) {
		Node nxt = { now.y + dy[i] , now.x + dx[i] };

		if (isOut(nxt)) continue;
		if (used[nxt.y][nxt.x]) continue;
		if (MAP[nxt.y][nxt.x] == 0) continue;

		used[nxt.y][nxt.x] = true;
		dfs(nxt);

	}

}

int main() {
	vector<int> ans;
	while (true) {
		init();
		input();
		if (is_end) break;
		
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {

				if (MAP[y][x] == 0) continue; // 바다
				if (used[y][x]) continue; // 재방문 차단

				used[y][x] = 1;
				dfs({ y, x });
				cnt++;
			}
		}
		ans.push_back(cnt);
	}

	// print
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	return 0;
}