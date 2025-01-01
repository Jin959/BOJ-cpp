// https://www.acmicpc.net/problem/1976

#include<iostream>
#include<vector>
using namespace std;

#define MAXN 200
#define MAXM 1000

int n, m; // ���ü�, ���� ���� ��
int parent[MAXN + 1];
vector<int> travels;
bool adj[MAXN + 1][MAXN + 1]; // ������ ��ȣ�� 1���� N���� ���ʴ�� �Ű��� �ִ�.

void input() {
	cin >> n >> m;

	// A�� B�� ����Ǿ����� B�� A�� ����Ǿ� �ִ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}

	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		travels.push_back(tmp);
	}
}

int find(int now) {
	if (parent[now] == now) return now;

	int p = find(parent[now]);
	parent[now] = p; // ��ξ���
	return p;
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

void init() {
	for (int city = 1; city <= n; city++) parent[city] = city;
}

void group_cities() {
	// �밢�� ���� �����ʸ� union �Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!adj[i][j]) continue;
			unite(i, j);
		}
	}
}

int main() {
	input();

	init();
	group_cities();

	int group = find(travels.front());
	for (int i = 1; i < m; i++) {
		if (group != find(travels.at(i))) { // �ٸ� �׷��̸� �Ұ����� �����̹Ƿ� NO
			cout << "NO";
			return 0;
		}
	}

	// ���� �������� parent �迭�� �ƴ϶� find�� ã�ƾ� �Ѵ�.
	// Union �ѹ� ���� �ߴٰ� �θ� ��� �迭�� �ϳ��� �θ�� ��� �Ǵ� ���� �������� �ʴ´�.
	/*int group = parent[travels.front()];
	for (int i = 1; i < m; i++) {
		if (group != parent[travels.at(i)]) {
			cout << "NO";
			return 0;
		}
	}*/

	cout << "YES";

	return 0;
}