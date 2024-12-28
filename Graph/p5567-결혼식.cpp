// https://www.acmicpc.net/problem/5567
/*
* �湮�� ���� ����ġ�� �ϰ� Ž���ϸ鼭 ģ���� ī�����ϸ�, ���� ��쿡 4���� ģ���� �� �� ����.
* �׷��� �湮�� ���� ���߿� �ٽ� �����Ѵ�.
* 1 2
* 1 3
* 2 3
* 3 4
* 
* ������ BFS �� Ǯ�� ����� ������ Ž���ؼ� �� �Ÿ��� 2�� ģ��������� ���Ƿ� �� ������ �� �ִ�.
*/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 500

// ������ ��ȣ�� 2 ���� 501
int adj[MAXN + 2][MAXN + 2];
bool visited[MAXN + 2];
int n, m;

void dfs(int now, int depth) {

	if (depth == 2) return;

	for (int nxt = 1; nxt <= n; nxt++) {
		if (adj[now][nxt] == 0) continue;

		visited[nxt] = 1;
		dfs(nxt, depth + 1);
	}

}

int count() {
	int cnt = 0;
	// ��� ����
	for (int i = 2; i <= n; i++) {
		cnt += visited[i];
	}

	return cnt;
}

int main() {

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	dfs(1, 0);

	cout << count();

	return 0;
}