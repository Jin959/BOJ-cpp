#include <iostream>
#define MAXN 100000
#define MAXM 100000
using namespace std;

int n, m;
int arr[MAXN + 1]; // idx = 1~N
int prefix[MAXN + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tmp = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		tmp += arr[i];
		prefix[i] = tmp;
	}

	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;

		int sum = prefix[e] - prefix[s - 1];
		//int sum = prefix[e] - prefix[s] + arr[s];

		cout << sum << '\n';
	}

	return 0;
}