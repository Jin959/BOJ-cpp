// https://www.acmicpc.net/problem/9372

/*
* 간선수 E = 비행기의 수 M == 10000 
* 테스트 케이스 수 T 번 반복해야 한다.
* 
* 상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다.
* 그런데 가장 적은 종류의 비행기를 타야한다. -> Tree 이다.
* 주어지는 비행 스케줄은 항상 연결 그래프를 이룬다. -> 못가는 거 생각 안해도 된다.
* MST 근데 가중치가 없다. Tree 만 만들면 된다.
* 시간복잡도 -> T * E ~ T * M ~ 100 * 10000
*/

#include<iostream>
#include<vector>

#define MAXT 100 // Test Case
#define MAXN 1000 // 국가의 수
#define MAXM 10000 // 비행기의 수, 간선 수

using namespace std;

struct Edge {
	int a, b;
};

int n, m;
vector<Edge> edges; // 1 <= a, b <= n
int parent[MAXN + 1];

void init() {
	for (int i = 0; i < n; i++) edges.clear();
	for (int i = 1; i <= n; i++) parent[i] = i;
}

void input() {

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges.push_back({ a, b });
	}
}


int find(int now) {
	if (parent[now] == now) return now;

	int p = find(parent[now]);
	parent[now] = p;
	return p;
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

int getSpannigTree() {
	int e = 0;

	while (!edges.empty()) {
		if (e == n - 1) break;
		Edge edge = edges.back();
		edges.pop_back();

		if (find(edge.a) != find(edge.b)) {
			unite(edge.a, edge.b);
			e++;
		}
	}
	return e;
}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		init();
		input();
		cout << getSpannigTree() << endl;
	}

	return 0;
}