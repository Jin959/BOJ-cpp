// https://www.acmicpc.net/problem/11720

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<string> v;

int cal(int idx)
{
	string str = v[idx];

	int score = 0;
	int tmp = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'O') score += (++tmp);
		else tmp = 0;
	}

	return score;
}

int main()
{
	cin >> n;

	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		cout << cal(i) << endl;
	}

	return 0;
}