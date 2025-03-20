/**
* �����Ѵ�. -> nlogn < 50��
* 
* �� �����ͷ� right �����͸� �� ĭ�� �ű�鼭 m �̻��� ó�� �� ������ �ű��.
* m �� �Ǿ����� left �����͸� �� ĭ�� �ű�鼭 ������ ���� m �̻��̸鼭 �ּ��̸� ����
* m �̸��� �Ǿ����� left �� ���߰� �ٽ� m �̻��� �� ������ right �� �ű��.
* -> O(n)
* 
* T -> O(n + nlogn)) ~ O(nlogn) < 1��
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100000

using namespace std;

int n, m;
int arr[MAXN];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

int main() {
	input();

	sort(arr, arr + n);

	int l = 0;
	int r = 1;
	int min_diff = 21e8;

	while (true) {

		if (r > n) break;

		int diff = arr[r] - arr[l];

		if (diff >= m) {
			if (diff < min_diff) {
				min_diff = diff;
			}
			if (l < r - 1) l++;
			else r++;
		} else {
			r++;
		}
	}

	cout << min_diff;

	return 0;
}