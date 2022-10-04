// https://www.acmicpc.net/problem/7562

/*
테스트 케이스마다 초기화하는 것 까먹음.
큐를 비우는 것 등

방문여부확인 하는 used의 역할을 dist로 같이 사용하면 안된다.
시작점을 다시방문하는 등 불필요하거나 맞지않는 탐색을 함.
*/

#include <iostream>
#include <queue>
#include <cstring>

#define MAXI 300

using namespace std;

struct Node { int y, x; };

Node start, goal;
int dist[MAXI][MAXI];
int used[MAXI][MAXI];
int t, n;

int dy[] = { 2, 1, 2, 1, -2, -1, -2, -1 };
int dx[] = { 1, 2, -1, -2, 1, 2, -1, -2 };

queue<Node> q;

bool isOut(Node node)
{
	return (node.x < 0 || node.x >= n || node.y < 0 || node.y >= n); // 나가면 true
}

void bfs()
{
	// 시작점
	q.push(start);
	used[start.y][start.x] = 1;

	while (!q.empty())
	{
		// 1. 노드를 택한다.
		Node now = q.front();
		q.pop();
		
		// 2. 노드 탐색
		for (int i = 0; i < 8; i++)
		{
			Node next = { now.y + dy[i], now.x + dx[i] };

			if (used[next.y][next.x]) continue;
			if (isOut(next)) continue;

			dist[next.y][next.x] = dist[now.y][now.x] + 1;
			used[next.y][next.x] = 1;
			if (next.y == goal.y && next.x == goal.x) return; // 목적지 도착
			
			q.push(next);
		}
	}
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		//init
		memset(dist, 0, sizeof(dist));
		memset(used, 0, sizeof(used));
		while (!q.empty()) q.pop();

		cin >> n >> start.y >> start.x >> goal.y >> goal.x;
		
		bfs();
		cout << dist[goal.y][goal.x] << endl;
	}

	return 0;
}