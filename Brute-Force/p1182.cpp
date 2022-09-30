// �κм��� : �߰��� �ǳ� �پ ������ ������ �����Ǹ� �κ� �����̴�.
// ���� �κм��� : �ǳ� �� ���� ���ӵ� �κ� ����

// ��� ��츦 �����Ѵ�. -> DFS

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