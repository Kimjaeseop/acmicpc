#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

// Brute-force로 풀어보았다
// 생각보다 시간차이가 크지 않다

int main(void)
{
	freopen("input_4.txt", "r", stdin);
	double ANS = 14143;

	scanf("%d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

	double x_1 = (double)(Bx - Ax) / 1000000;
	double x_2 = (double)(Dx - Cx) / 1000000;
	double y_1 = (double)(By - Ay) / 1000000;
	double y_2 = (double)(Dy - Cy) / 1000000;

	for (int i = 0; i <= 1000000; i++) {
		ANS = min(ANS, sqrt(pow((Ax + x_1*i)-(Cx+x_2*i), 2) + pow((Ay+y_1*i)-(Cy+y_2*i), 2)));
	}

	printf("%.7f\n", ANS);

	return 0;
}
		

