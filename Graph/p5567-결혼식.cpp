// https://www.acmicpc.net/problem/5567
/*
* 방문한 곳을 가지치기 하고 탐색하면서 친구를 카운팅하면, 다음 경우에 4번을 친구로 할 수 없다.
* 그래서 방문한 곳을 나중에 다시 세야한다.
* 1 2
* 1 3
* 2 3
* 3 4
* 
* 오히려 BFS 로 풀면 가까운 순서로 탐색해서 딱 거리가 2인 친구들까지만 세므로 더 적합할 수 있다.
*/
#include<iostream>
#include<queue>
using namespace std;

#define MAXN 500

// 동기의 번호는 2 부터 501
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
	// 상근 제외
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