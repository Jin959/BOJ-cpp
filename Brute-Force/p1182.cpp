// 부분수열 : 중간에 건너 뛰어도 되지만 순서는 유지되면 부분 수열이다.
// 연속 부분수열 : 건너 뜀 없이 연속된 부분 수열

// 모든 경우를 봐야한다. -> DFS

#include <iostream>

#define MAXN 20

using namespace std;

int n, s;
int arr[MAXN];
int sum;
int cnt;

int de;
void dfs(int idx)
{
	if (idx == n - 1) return;
	

	for (int i = idx + 1; i < n; i++)
	{
		sum += arr[i];
		if (sum == s) cnt++;

		dfs(i);

		sum -= arr[i];
	}

	de = -1;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	// input
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++)
	{
		sum = arr[i];
		if (sum == s) cnt++;
		dfs(i);
	}

	cout << cnt;

	return 0;
}