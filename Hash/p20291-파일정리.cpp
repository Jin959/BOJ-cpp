// https://www.acmicpc.net/problem/20291

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

#define MAXN 50000

using namespace std;

int n;
vector<string> files;

void input() {
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		files.push_back(tmp);
	}

	return;
}

void print(vector<pair<string, int>>& ans) {
	for (pair<string, int> file : ans) {
		cout << file.first << ' ' << file.second << endl;
	}
}

int main() {
	input();

	unordered_map<string, int> map;
	for (int i = 0; i < n; i++) {
		string file_name = files.at(i);
		int pos = file_name.find('.'); // ���� ��Ȯ�� �� �� �����ϸ�, ���� �̸��� ù ���� �Ǵ� ������ ���ڷ� ���� �ʴ´�.
		int start = pos + 1;

		int sz = file_name.length() - pos;
		string extend = file_name.substr(start, sz);

		map[extend]++;
	}

	vector<pair<string, int>> extends(map.begin(), map.end());
	sort(extends.begin(), extends.end()); // pair ������ �⺻ pair.first ���� �������� ����

	print(extends);

	return 0;
}