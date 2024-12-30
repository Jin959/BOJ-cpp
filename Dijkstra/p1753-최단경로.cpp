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
int k; // 시작 노드
int dist[MAXV + 1];
bool visited[MAXV + 1];
vector<Edge> adj[MAXE + 1];

void input() {
	cin >> v >> e >> k;

	int U, V, w;
	for (int i = 0; i < e; i++) {
		cin >> U >> V >> w;
		adj[U].push_back({ V, w }); // 방향그래프
	}
}

void dijkstra() {
	priority_queue<Node> pq;
	pq.push({ k, 0 });
	dist[k] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		// 여기서 방문 검사를 해야한다.
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

// 다음 함수는 방문 확인 위치 때문에 fail 이다.
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
	// 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력
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