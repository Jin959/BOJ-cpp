// Parametric Search : upper boundary �� �ּҰ��� ã�� �����̴�.
// �׳� ����� ���� ���� ������ ���� �ǵ��� �ƴѵ�.
#include <iostream>

#define MAXX 1000000000

using namespace std;

long long x, y, zrate; // �� ����, �¸�, �·�

void init() {
	cin >> x >> y;
	zrate = y * 100 / x;
}

long long getRate(long long mid) {
	return (y + mid) * 100 / (x + mid);
}

int main() {
	init();
	if (zrate >= 99) { // �й� ����� ������� �ʱ� ������ 99% �̻��� �� �·��� ������ �ʴ´�.
		cout << -1;
		return 0;
	}

	long long lb = 0, ub = MAXX;
	long long mid, nrate;
	while (1) {
		mid = (lb + ub) / 2; // int �����÷�

		if (lb + 1 == ub) break; // ��谡 �� ���� �� ����

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
