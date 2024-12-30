// https://www.acmicpc.net/problem/1753

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAXV 20000
#define MAXE 300000
#define INF 21e8

struct Node {
	int node, acc;

	bool operator<(Node node) const {
		return this->acc > node.acc;
	}
};

struct Edge {
	int to, cost;
};

int v, e;
int k; // ���� ���
int dist[MAXV + 1];
bool visited[MAXV + 1];
vector<Edge> adj[MAXE + 1];

void input() {
	cin >> v >> e >> k;

	int U, V, w;
	for (int i = 0; i < e; i++) {
		cin >> U >> V >> w;
		adj[U].push_back({ V, w }); // ����׷���
	}
}

void dijkstra() {
	priority_queue<Node> pq;
	pq.push({ k, 0 });
	dist[k] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		// ���⼭ �湮 �˻縦 �ؾ��Ѵ�.
		if (visited[now.node]) continue;
		visited[now.node] = true;

		for (Edge edge : adj[now.node]) {
			if (now.acc + edge.cost < dist[edge.to]) {
				dist[edge.to] = now.acc + edge.cost;
				pq.push({ edge.to, dist[edge.to] });
			}
		}
	}
}

// ���� �Լ��� �湮 Ȯ�� ��ġ ������ fail �̴�.
void dijkstra_fail() {
	priority_queue<Node> pq;
	pq.push({ k, 0 });
	dist[k] = 0;
	visited[k] = true;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (Edge edge : adj[now.node]) {
			if (visited[edge.to]) continue;
			visited[edge.to] = true;
			if (now.acc + edge.cost < dist[edge.to]) {
				dist[edge.to] = now.acc + edge.cost;
				pq.push({ edge.to, dist[edge.to] });
			}
		}
	}
}

void print() {
	// ������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ���
	for (int i = 0; i < v; i++) {
		if (i + 1 == k) cout << 0 << endl;
		else if (dist[i + 1] == INF) cout << "INF" << endl;
		else cout << dist[i + 1] << endl;
	}
}

int main() {
	input();
	fill(dist, dist + (MAXV + 1), INF);
	dijkstra();
	//dijkstra_fail();
	print();
}