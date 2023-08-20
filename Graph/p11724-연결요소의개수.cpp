// https://www.acmicpc.net/problem/11724

#include <iostream>

#define MAXN 1000

using namespace std;

// M ≤ N×(N-1)/2 -> 그래프에서 모든 노드를 연결하는 경우, N×(N-1)/2 개의 간선이 사용된다.
// adj matrix를 사용한다.
int n, m;
int cnt;
int adj[MAXN + 1][MAXN + 1];
int used[MAXN + 1];

void dfs(int now)
{
	// base condition
	// none

	// 1 <= N <= 1000
	for (int i = 1; i <= n; i++)
	{
		// cycle check & 연결 탐색
		if (used[i] == true || adj[now][i] == false) continue;

		// 기록
		used[i] = 1;

		dfs(i);
	}

	return;
}

int main()
{
	//input
	cin >> n >> m;
	// 무방향 그래프 = 양방향 그래프
	int from, to;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 1) continue;

		dfs(i);
		cnt++;
	}

	cout << cnt;

	return 0;
}