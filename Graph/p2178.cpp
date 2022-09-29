// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <string>

#define MAXN 100
#define MAXM 100

using namespace std;

int used[MAXN][MAXM];
int MAP[MAXN][MAXM];
int dist[MAXN][MAXM];

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n, m;

struct Node { int y, x; };

Node goal;

void input()
{
    cin >> n >> m;
    goal.y = n - 1;
    goal.x = m - 1;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            MAP[i][j] = tmp[j] - '0'; // char to int
        }
    }

    return;
}

bool isOut(int y, int x)
{
    return (y < 0 || y >= n || x < 0 || x >= m);
}

int de;
void bfs()
{
    // 준비물
    queue<Node> q;

    // setting start
    q.push({ 0, 0 });
    used[0][0] = 1;
    dist[0][0] = 1;   //  칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        // 도착 
        if (now.y == goal.y && now.x == goal.x) return;

        for (int i = 0; i < 4; i++)
        {
            Node next = { now.y + dy[i], now.x + dx[i] };

            if (isOut(next.y, next.x)) continue;
            if (!MAP[next.y][next.x]) continue; // 0은 벽
            if (used[next.y][next.x]) continue;

            dist[next.y][next.x] = dist[now.y][now.x] + 1;
            used[next.y][next.x] = 1;

            q.push(next);
        }
    }

    de = -1;
    return;
}

int main()
{
    input();

    bfs();

    cout << dist[goal.y][goal.x] << endl;

    return 0;
}