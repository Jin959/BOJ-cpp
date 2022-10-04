// https://www.acmicpc.net/problem/1743

#include <iostream>

#define MAXN 100
#define MAXM 100

using namespace std;

struct Node { int y, x; };

int n, m, k;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
int MAP[MAXN][MAXM];
int used[MAXN][MAXM];

int max_cnt = -321;
int cnt = 0;

bool isOut(Node node)
{
	return (node.y < 0 || node.y >= n || node.x < 0 || node.x >= m);
}

int de;
void dfs(Node now)
{

	for (int i = 0; i < 4; i++)
	{
		Node next = { now.y + dy[i], now.x + dx[i] };

		if (used[next.y][next.x]) continue;
		if (isOut(next)) continue;
		if (MAP[next.y][next.x] == 0) continue;

		used[next.y][next.x] = 1;
		cnt++;
		dfs(next);
	}

	de = -1;
	return;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		MAP[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (used[i][j] == 1) continue;
			if (MAP[i][j] == 0) continue;


			cnt = 1; // ½ÃÀÛÁ¡
			used[i][j] = 1;
			dfs({ i, j });
			if (cnt > max_cnt) max_cnt = cnt;
		}
	}

	cout << max_cnt;

	return 0;
}