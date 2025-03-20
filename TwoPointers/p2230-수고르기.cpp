/**
* 정렬한다. -> nlogn < 50만
* 
* 투 포인터로 right 포인터를 한 칸씩 옮기면서 m 이상이 처음 될 때까지 옮긴다.
* m 이 되었을때 left 포인터를 한 칸씩 옮기면서 차이의 값이 m 이상이면서 최소이면 갱신
* m 미만이 되었으면 left 를 멈추고 다시 m 이상이 될 때까지 right 를 옮긴다.
* -> O(n)
* 
* T -> O(n + nlogn)) ~ O(nlogn) < 1초
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