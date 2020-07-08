#include <stdio.h>

#define PI 3.14159265359

double r;

// 택시 기하학

// 기준이 0,0
// x1 = -1, 0
// x2 = 1, 0
// y1 = 0, 1
// y2 = 0, -1

//이라면 r == 1이다.
//바깥쪽 변의 길이 * 4를 하면 되는데
//바깥쪽 변의 길이는 r * r의 제곱근이다.
//r * r의 제곱근이 4개의 합이 변의 넓이가 되는데
//이는 2 * r * r과 같다.


int main(void)
{
	scanf("%lf", &r);

	printf("%.6f\n%.6f\n", (PI * r * r), (2 * r * r));

	return 0;
}
