// Parametric Search : upper boundary 의 최소값을 찾는 문제이다.
// 그냥 산수로 구할 수는 있으나 출제 의도가 아닌듯.
#include <iostream>

#define MAXX 1000000000

using namespace std;

long long x, y, zrate; // 총 게임, 승리, 승률

void init() {
	cin >> x >> y;
	zrate = y * 100 / x;
}

long long getRate(long long mid) {
	return (y + mid) * 100 / (x + mid);
}

int main() {
	init();
	if (zrate >= 99) { // 패배 기록이 사라지지 않기 때문에 99% 이상일 때 승률이 변하지 않는다.
		cout << -1;
		return 0;
	}

	long long lb = 0, ub = MAXX;
	long long mid, nrate;
	while (1) {
		mid = (lb + ub) / 2; // int 오버플로

		if (lb + 1 == ub) break; // 경계가 딱 만날 때 까지

		nrate = getRate(mid);

		if (nrate > zrate) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}

	cout << ub;
	return 0;
}
