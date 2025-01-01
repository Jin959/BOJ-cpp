// https://www.acmicpc.net/problem/9372

/*
* ������ E = ������� �� M == 10000 
* �׽�Ʈ ���̽� �� T �� �ݺ��ؾ� �Ѵ�.
* 
* ����̰� �� �������� �ٸ� ������ �̵��� �� �ٸ� ������ ���� ����(������ �̹� �湮�� ������) �ȴ�.
* �׷��� ���� ���� ������ ����⸦ Ÿ���Ѵ�. -> Tree �̴�.
* �־����� ���� �������� �׻� ���� �׷����� �̷��. -> ������ �� ���� ���ص� �ȴ�.
* MST �ٵ� ����ġ�� ����. Tree �� ����� �ȴ�.
* �ð����⵵ -> T * E ~ T * M ~ 100 * 10000
*/

#include<iostream>
#include<vector>

#define MAXT 100 // Test Case
#define MAXN 1000 // ������ ��
#define MAXM 10000 // ������� ��, ���� ��

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