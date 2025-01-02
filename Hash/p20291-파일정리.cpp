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
		int pos = file_name.find('.'); // 점은 정확히 한 번 등장하며, 파일 이름의 첫 글자 또는 마지막 글자로 오지 않는다.
		int start = pos + 1;

		int sz = file_name.length() - pos;
		string extend = file_name.substr(start, sz);

		map[extend]++;
	}

	vector<pair<string, int>> extends(map.begin(), map.end());
	sort(extends.begin(), extends.end()); // pair 정렬은 기본 pair.first 기준 오름차순 정렬

	print(extends);

	return 0;
}