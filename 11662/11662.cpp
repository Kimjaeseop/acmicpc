#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

// 처음 풀어보는 삼분탐색 // Ternary Search
// 볼록함수에서 극값 혹은 최대/최소값을 찾을 때 사용하는 테크닉이라 함

// 볼록함수에서 이진탐색을 하지 않는 이유는 도함수를 구해야하고 이는 쉽지 않다고함
// 또한 1/3 지점을 잡는 것이 더 안전하다고 하는데 잘 모르겠다.

// 또다른 삼분탐색문제 -> 13310, 8986
using namespace std;

typedef pair<double, double> pdd;

int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

// 이동 지점을 구하는 함수
double move(double s, double e, double p)
{
	return s + (e - s) * (p / 100);
}

// 이동한 좌표를 구하는 함수
pdd point(double x_1, double x_2, double y_1, double y_2, double p)
{
	return {move(x_1, x_2, p), move(y_1, y_2, p)};
}

int main(void)
{
	freopen("input_4.txt", "r", stdin);
	scanf("%d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

	double l = 0, r = 100; // 지점을 percent로 나눔
	double ANS = sqrt((10000*10000)+(10000*10000));

	while (r - l >= 1e-7) {
		// l ~ p_1, p_1 ~ p_2, p_2 ~ r으로 삼등분
		double p_1 = (2*l + r) / 3; // 1 : 2 지점
		double p_2 = (l + 2*r) / 3; // 2 : 1 지점

		// 민호, 강호가 1:2, 2:1 지점에 이동한 좌표
		pair<double, double> m[2] = {point(Ax, Bx, Ay, By, p_1), point(Ax, Bx, Ay, By, p_2)};
		pair<double, double> k[2] = {point(Cx, Dx, Cy, Dy, p_1), point(Cx, Dx, Cy, Dy, p_2)};

		// 거리계산
		double len_1 = sqrt(pow(k[0].first - m[0].first, 2) + pow(k[0].second - m[0].second, 2));
		double len_2 = sqrt(pow(k[1].first - m[1].first, 2) + pow(k[1].second - m[1].second, 2));

		ANS = min(min(len_1, len_2), ANS);

		// 삼분탐색의 조건에 따라 f(p) > f(q)라면 l ~ p에는 절대 최소값이 존재 할 수 없음
		if (len_1 > len_2)
			l = p_1;
		else
			r = p_2;
	}

	// 오차 범위이내로 출력
	printf("%.7f\n", ANS);

	return 0;
}
