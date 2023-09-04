// boj.kr/16234

/*
* Ǯ�� �ð�: 1 h 20 min
* 
* dfs ���� Ž����
* ������ ������ ���������� �����ϸ鼭 �� ������ ���������� �α��̵��� �� �� �ִ�.
* 
* n by n �� ���ڸ� start�� dfs �� ������ ���� Ž�� O(n*n)
* Ž���ϸ鼭 vec�� ������ �����ϰ� �α� ���� �����Ѵ�.
* q�� �ִ� ���� ���� �α��� �̵� ��Ų��.
* �α� �̵��� ���������� ��¥ cnt++
* �̰� �α��̵��� ���� ������ �ִ� 2000�� �ݺ�
* 
* O(n^2) -> T(n) = 2000 * n^2 = 2000 * 2500 = 5e6 < 1��
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

	int res = popul / sz;	// �Ҽ��� ����

	for (Node nation : vec) MAP[nation.y][nation.x] = res;
}

int main() {
	input();

	int cnt = 0;
	bool flag = false;	// �α��̵� ���� �Ǻ�

	while (true) {
		memset(used, 0, sizeof(used));
		flag = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (used[i][j]) continue;	// dfs �� �ѹ� �����ϸ� ������ ������ ��� Ž���ϹǷ� �ǳ� �پ ��.

				vec.clear();
				Node start = { i, j };

				used[start.y][start.x] = true;
				vec.push_back(start);
				dfs(start);
				imigrate();

				if (vec.size() != 1) flag = true;	// �α��̵��� �ѹ��̶� �����ߴٸ� true
			}
		}

		if (!flag) break;	// �α��̵��� �ѹ��� ������. -> �Ϸ�
		cnt++;	// �Ϸ�����.
	}

	cout << cnt;
}