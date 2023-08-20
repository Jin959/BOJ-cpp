// https://www.acmicpc.net/problem/3052

#include <iostream>
#include <vector>

#define DIV 42

using namespace std;

vector<int> v;
int dat[DIV];

int doCount()
{
	int cnt = 0;
	for (int i = 0; i < DIV; i++)
	{
		if (dat[i] != 0) cnt++;
	}

	return cnt;
}

int main()
{
	// input
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
		dat[v[i] % DIV]++;
	}

	cout << doCount();

	return 0;
}