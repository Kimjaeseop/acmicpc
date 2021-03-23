#include <iostream>
#include <cmath>

using namespace std;

int T;
int x[2], y[2], r[2];
double d;

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

		if (x[0] == x[1] && y[0] == y[1]) {
			if (r[0] == r[1])
				cout << -1 << endl; // 원이 완전히 겹침
			else
				cout << 0 << endl; // 큰 원 안에 작은 원이 있고 반지름이 다름

			continue;
		}

		d = sqrt((x[1]-x[0]) * (x[1]-x[0]) + (y[1]-y[0]) * (y[1]-y[0]));

		if (d == abs(r[1]-r[0]) || d == (r[1]+r[0])) { // 한 점에서 겹치는 경우
			cout << 1 << endl;
			continue;
		}

		if (r[0]+r[1] < d || d < abs(r[1]-r[0])) { // 원이 완전히 떨어진 경우, 큰 원 안에 작은 원이 있는 경우
			cout << 0 << endl;
			continue;
		}

		if (abs(r[1]-r[0]) < d && d < (r[1]+r[0])) { // 두 원이 두 점에서 겹치는 경우
			cout << 2 << endl;
			continue;
		}
	}

	return 0;
}
