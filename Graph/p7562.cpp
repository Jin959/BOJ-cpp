// https://www.acmicpc.net/problem/7562

/*
�׽�Ʈ ���̽����� �ʱ�ȭ�ϴ� �� �����.
ť�� ���� �� ��

�湮����Ȯ�� �ϴ� used�� ������ dist�� ���� ����ϸ� �ȵȴ�.
�������� �ٽù湮�ϴ� �� ���ʿ��ϰų� �����ʴ� Ž���� ��.
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
	return (node.x < 0 || node.x >= n || node.y < 0 || node.y >= n); // ������ true
}

void bfs()
{
	// ������
	q.push(start);
	used[start.y][start.x] = 1;

	while (!q.empty())
	{
		// 1. ��带 ���Ѵ�.
		Node now = q.front();
		q.pop();
		
		// 2. ��� Ž��
		for (int i = 0; i < 8; i++)
		{
			Node next = { now.y + dy[i], now.x + dx[i] };

			if (used[next.y][next.x]) continue;
			if (isOut(next)) continue;

			dist[next.y][next.x] = dist[now.y][now.x] + 1;
			used[next.y][next.x] = 1;
			if (next.y == goal.y && next.x == goal.x) return; // ������ ����
			
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