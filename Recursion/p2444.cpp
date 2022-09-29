// https://www.acmicpc.net/problem/2444

#include <iostream>

using namespace std;

int limit;

void dfs(int now)
{
	if (now == limit)
	{
		for (int i = 0; i < 2 * limit - 1; i++) cout << '*';
		cout << endl;

		return;
	}

	for (int i = 0; i < limit - now; i++) cout << ' ';
	for (int i = 0; i < 2 * now - 1; i++) cout << '*';
	cout << endl;

	dfs(now + 1);

	for (int i = 0; i < limit - now; i++) cout << ' ';
	for (int i = 0; i < 2 * now - 1; i++) cout << '*';
	cout << endl;

	return;
}

int main()
{
	cin >> limit;

	dfs(1);

	return 0;
}