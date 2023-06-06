/*
* 사이클이 이미 형성된 경우에 대한 반례
* https://www.acmicpc.net/board/view/103259
// input
5 3
0 0
0 1
0 2
0 3
0 100
1 2
2 3
1 3

//output
98.00
*/

#include <iostream>
#include <queue>
#include <cmath>

#define MAXN 1000
#define MAXM 1000

using namespace std;

struct Node {
	int y, x;
} node[MAXN + 1];

struct Edge {
	int a, b;
	double w;

	bool operator< (Edge edge) const {
		return this->w > edge.w;
	}
};

priority_queue<Edge> pq;
int n, m;
int parent[MAXN + 1];
int e;

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

double getDist(Node a, Node b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> node[i].x >> node[i].y;
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;

		for (int j = i + 1; j <= n; j++) {
			double w = getDist(node[i], node[j]);
			pq.push({ i, j, w });
		}
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		if (find(a) == find(b)) continue;	// 여기서 사이클이 생기는 반례가 있다. 이때는 e++ 하면 안된다.
		unite(a, b);
		e++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	double acc = 0;

	while (1) {
		if (e == n - 1) break;	// 사이클이 이미 존재할 때, 위에서 처리하지 않았다면 여기서 오류가 생긴다.

		Edge edge = pq.top();
		pq.pop();

		if (find(edge.a) == find(edge.b)) continue;

		unite(edge.a, edge.b);
		acc += edge.w;
		e++;
	}

	cout << fixed;
	cout.precision(2);
	cout << acc;
	//printf("%.2lf", acc);

	return 0;
}