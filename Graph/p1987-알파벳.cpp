// https://www.acmicpc.net/problem/1987

/*
line 53����
�湮 ó���� ���� �湮���� ������ 
if (dist[next.y][next.x] != 0) continue;
�������� ��θ� Ž���� �� ���� �Ǿ� �ִ� ��θ� ���ϴ� ��찡 �����.

line 64����
//if (dist[next.y][next.x] > ans) ans = dist[next.y][next.x];
�� ����ϸ� 
1 1
A
�� ���� ���� ���̽����� ans ������ �̷�������ʴ´�.
*/

#include <iostream>
#include <string>

#define MAXR 20
#define MAXC 20

using namespace std;

struct Node { int y, x; };

string MAP[MAXR];
bool dat[26];
int dist[MAXR][MAXC + 1];

int r, c;
int ans = -1;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };

void input()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++) cin >> MAP[i];

	return;
}

bool isOut(Node node)
{
	return (node.x < 0 || node.x >= c || node.y < 0 || node.y >= r);
}

int de;
void dfs(Node now)
{
	if (dist[now.y][now.x] > ans) ans = dist[now.y][now.x];

	for (int i = 0; i < 4; i++)
	{
		Node next = { now.y + dy[i], now.x + dx[i] };

		if (isOut(next)) continue;
		if (dat[MAP[next.y][next.x] - 'A']) continue; // ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.
		//if (dist[next.y][next.x] != 0) continue;

		// ���
		dat[MAP[next.y][next.x] - 'A'] = true;
		dist[next.y][next.x] = dist[now.y][now.x] + 1;

		//if (dist[next.y][next.x] > ans) ans = dist[next.y][next.x];

		dfs(next);

		// Backtracking
		dat[MAP[next.y][next.x] - 'A'] = false;
		dist[next.y][next.x] = 0;
	}

	de = -1;
	return;
}

int main()
{
	input();

	// init
	dist[0][0] = 1; // ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.
	dat[MAP[0][0] - 'A'] = true;

	dfs({0, 0});

	cout << ans;

	return 0;
}