#include <stdio.h>

int T;
int x, y;
unsigned int gap, cur, ans; // unsigned or long long

/* 
   https://private-space.tistory.com/3

   위 링크 참조

   k를 나열했을 때 절반을 기준으로 양 옆이 같아야 마지막에 k=1인 상태로 도달 할 수있다는 것은 
   생각했는데 구현이 어려워서 단순하게 그래프(BFS)로 풀었을 땐 메모리 초과

   단순히 x, y의 차이마다 k를 나열해보면

   (n : x와 y의 차이)
   1 1
   2 11
   3 111
   4 121
   5 1211
   6 1221
   7 11221

   ... 

	의 형태가 되어 

	a1 = 1, a2 = 2, a3 = 3, a4 = 5, a5 = 7, a6 = 10 ... 
	a(n+1) = An + (n+1)/2 -> 이 부분은 블로그가 틀림

	이걸 반복문으로 수식화해서 An을 계산하면 끝

	왜인지는 모르겠지만 cur을 long long혹은 unsigend int로 타입 지정을 하지 않으면
	시간 초과가 나는 것으로 보아 테스트 케이스에 int 범위를 벗어나는 케이스가 있는 것 같다
*/

int main(void)
{
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &x, &y);

		gap = y - x;
		cur = ans = 1;

		for (int i = 2; cur < gap; i++) {
			cur += (i / 2);
			ans++;
		}

		if (cur > gap)
			ans--;

		printf("%d\n", ans);
	}

	return 0;
}
