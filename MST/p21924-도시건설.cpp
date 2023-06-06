#include <iostream>
#include <queue>

#define MAXN 100000
#define MAXM 500000

using namespace std;

int n, m;
int parent[MAXN];
long long t;

struct Edge {
	int a, b, w;

	bool operator< (Edge edge) const {
		return this->w > edge.w;
	}
};

priority_queue<Edge> pq;

void input() {
	cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		pq.push({ a - 1, b - 1, w }); // 노드 번호 1 부터

		t += w;
	}
}

void init() {
	for (int i = 0; i < n; i++) parent[i] = i;
}

int find(int node) {
	if (parent[node] == node) return node;

	int p = find(parent[node]);
	return parent[node] = p;
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

int main() {
	input();
	init();

	long long acc = 0, e = 0;
	Edge edge;
	while (!pq.empty()) {
		if (e == n - 1) break;

		edge = pq.top();
		pq.pop();

		if (find(edge.a) == find(edge.b)) continue;
		unite(edge.a, edge.b);
		acc += edge.w;
		e++;
	}

	if (e != n - 1) { // 모든 노드가 연결되지 못함. tree가 완성 되지 않았다.
		cout << -1;
		return 0;
	}

	cout << t - acc;

	return 0;
}
