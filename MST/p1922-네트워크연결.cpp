// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <queue>

#define MAXN 1000
#define MAXM 100000

using namespace std;

int n, m;
int parent[MAXN + 1];
struct Edge {
	int u, v, w;

	bool operator< (Edge edge) const {
		return this->w > edge.w;
	}
};
priority_queue<Edge> pq;

void input() {
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		pq.push({ u, v, w });
	}
}

void init() {
	for (int i = 1; i < n + 1; i++) {
		parent[i] = i;
	}
}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	input();
	init();

	int e = 0;
	int acc = 0;

	while (1) {
		if (e == n - 1) break; // 모든 컴퓨터를 연결할 수 없는 경우는 없다.
		Edge edge = pq.top();
		pq.pop();
		if (find(edge.u) != find(edge.v)) {
			acc += edge.w;
			e++;
			unite(edge.u, edge.v);
		}
	}

	cout << acc;

	return 0;
}