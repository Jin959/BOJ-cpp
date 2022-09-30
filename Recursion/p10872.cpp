#include <iostream>

using namespace std;

int factorial(int now)
{
	// base
	if (now == 1 || now == 0) return 1;

	now = now * factorial(now - 1);

	return now;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	cout << factorial(n);

	return 0;
}