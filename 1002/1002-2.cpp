#include <iostream>
#include <stdio.h>

using namespace std;

int T;
int x[2], y[2], r[2];
int x3, y3, x4, y4;

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

		for (int n = 0; n < 2; n++) {
			for (int i = 0; i <= r[n]; i++) {
				x3 = x[n] - r[n] + i; y3 = r[n] - (x[n] - x3);
				x4 = r[n] - x[n] - i; y4 = r[n] - (x4 + x[n]);
  
				printf("(%d, %d), (%d, %d)\n", x3, y3, x4, y4);
			}
			printf("===================================\n");
		}
	}

	return 0;
}
