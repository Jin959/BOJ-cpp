// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100

int n, e;
vector<int> adj[MAXN + 1];
bool used[MAXN + 1];
int cnt;

void dfs(int now) {

	for (int nxt : adj[now]) {
		if (used[nxt]) continue;

		cnt++;
		used[nxt] = true;
		dfs(nxt);
	}

	return;
}

int main() {

	cin >> n >> e;

	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	used[1] = true;
	dfs(1);

	cout << cnt;

	return 0;
}