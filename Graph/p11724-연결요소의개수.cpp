// https://www.acmicpc.net/problem/11724

#include <iostream>

#define MAXN 1000

using namespace std;

// M �� N��(N-1)/2 -> �׷������� ��� ��带 �����ϴ� ���, N��(N-1)/2 ���� ������ ���ȴ�.
// adj matrix�� ����Ѵ�.
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
		// cycle check & ���� Ž��
		if (used[i] == true || adj[now][i] == false) continue;

		// ���
		used[i] = 1;

		dfs(i);
	}

	return;
}

int main()
{
	//input
	cin >> n >> m;
	// ������ �׷��� = ����� �׷���
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