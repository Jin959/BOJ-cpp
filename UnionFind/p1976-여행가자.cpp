// https://www.acmicpc.net/problem/1976

#include<iostream>
#include<vector>
using namespace std;

#define MAXN 200
#define MAXM 1000

int n, m; // 도시수, 여행 도시 수
int parent[MAXN + 1];
vector<int> travels;
bool adj[MAXN + 1][MAXN + 1]; // 도시의 번호는 1부터 N까지 차례대로 매겨져 있다.

void input() {
	cin >> n >> m;

	// A와 B가 연결되었으면 B와 A도 연결되어 있다.
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
	parent[now] = p; // 경로압축
	return p;
}

void unite(int a, int b) {
	parent[find(b)] = find(a);
}

void init() {
	for (int city = 1; city <= n; city++) parent[city] = city;
}

void group_cities() {
	// 대각축 기준 우상귀쪽만 union 한다.
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
		if (group != find(travels.at(i))) { // 다른 그룹이면 불가능한 여정이므로 NO
			cout << "NO";
			return 0;
		}
	}

	// 메인 로직에서 parent 배열이 아니라 find로 찾아야 한다.
	// Union 한번 수행 했다고 부모 기록 배열에 하나의 부모로 기록 되는 것을 보장하진 않는다.
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