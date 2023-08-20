// https://www.acmicpc.net/problem/3009

/*
1 1
1 4
4 4

4 1
*/

#include <iostream>

using namespace std;

int y[3];
int x[3];
// 후보
int candi_y[2];
int candi_x[2];

int dat[2][1001];

int ans_y, ans_x;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// 각각의 좌표에서, y에서 한번 나온곳, x에서 한번 나온 곳이 답이다.
	for (int i = 0; i < 3; i++)
	{
		cin >> y[i] >> x[i];

		// 일단 정답 후보 한개를 받는다.
		if (i == 0)
		{
			candi_y[0] = y[i];
			candi_x[0] = x[i];
		}
		else
		{
			if (candi_y[0] != y[i]) candi_y[1] = y[i];
			if (candi_x[0] != x[i]) candi_x[1] = x[i];
		}

		dat[0][y[i]]++;
		dat[1][x[i]]++;

	}

	ans_y = (dat[0][candi_y[0]] == 1) ? candi_y[0] : candi_y[1];
	ans_x = (dat[1][candi_x[0]] == 1) ? candi_x[0] : candi_x[1];

	cout << ans_y << ' ' << ans_x;

	return 0;
}