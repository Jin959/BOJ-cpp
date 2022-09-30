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
	
	// 또한 문자열은 공백으로 시작하거나 끝날 수 있다.
	//  전부 공백일 경우 str.size() == 0으로 된다.
	// 뒤에 공백 제거
	int i = str.size() - 1;
	while (!str.empty() && str[i--] == ' ') str.pop_back(); // (!str.empty()) : out of range
	// 앞에 공백 제거
	if (!str.empty())
	{
		while (str[a++] == ' ');
		a--;
		str = str.substr(a, str.size() - (a - 1));
	}

	// split ; 단어는 공백 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다.
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