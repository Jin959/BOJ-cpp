// https://www.acmicpc.net/problem/1987

/*
line 53에서
방문 처리한 곳을 방문하지 않으면 
if (dist[next.y][next.x] != 0) continue;
여러가지 경로를 탐색할 수 없게 되어 최대 경로를 피하는 경우가 생긴다.

line 64에서
//if (dist[next.y][next.x] > ans) ans = dist[next.y][next.x];
를 사용하면 
1 1
A
와 같은 예외 케이스에서 ans 갱신이 이루어지지않는다.
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
		if (dat[MAP[next.y][next.x] - 'A']) continue; // 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
		//if (dist[next.y][next.x] != 0) continue;

		// 기록
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
	dist[0][0] = 1; // 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
	dat[MAP[0][0] - 'A'] = true;

	dfs({0, 0});

	cout << ans;

	return 0;
}