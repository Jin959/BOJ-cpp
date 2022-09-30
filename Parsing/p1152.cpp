//https://www.acmicpc.net/problem/1152

/*
"          "

0



"          s s     "

2
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<string> v;

void doParsing()
{
	int a = 0;
	int b = 0;
	
	// ���� ���ڿ��� �������� �����ϰų� ���� �� �ִ�.
	//  ���� ������ ��� str.size() == 0���� �ȴ�.
	// �ڿ� ���� ����
	int i = str.size() - 1;
	while (!str.empty() && str[i--] == ' ') str.pop_back(); // (!str.empty()) : out of range
	// �տ� ���� ����
	if (!str.empty())
	{
		while (str[a++] == ' ');
		a--;
		str = str.substr(a, str.size() - (a - 1));
	}

	// split ; �ܾ�� ���� �� ���� ���еǸ�, ������ �����ؼ� ������ ���� ����.
	if (!str.empty())
	{
		string tmp;
		str.push_back(' ');
		while (str.size() != 0)
		{
			a = str.find(' ', b);

			tmp = str.substr(b, a - b);
			v.push_back(tmp);

			if (a == str.size() - 1) break;

			b = a + 1;
		}
	}

	return;
}

int main()
{
	getline(cin, str);

	doParsing();

	cout << v.size();

	return 0;
}