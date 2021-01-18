#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, r, c;

// wookje.dance 참고
// 1 << N
// 1을 N칸 만큼 shift함으로 2의 N승

void recursive(int N, int R, int C, int cnt)
{
	if (N == 0 && R == r && C == c) {
		printf("%d\n", cnt);
		exit(0);
	}

	// r < R : 정답 사분면 위에 있는 사분면
	// c < C : 정답 사분면 옆에 있는 사분면
	// R + N * 2 <= r : 정답 사분면 아래에 있는 사분면
	// C + N * 2 <= c : 정답 사분면 옆에 있는 사분면
	if (r < R || c < C || R + N*2 <= r || C + N*2 <= c)
		return ;

	recursive(N/2, R, C, cnt); // 2사분면
	recursive(N/2, R, C+N, cnt + N*N); // 1사분면
	recursive(N/2, R+N, C, cnt + 2*N*N); // 3사분면
	recursive(N/2, R+N, C+N, cnt + 3*N*N); // 4사분면
}

int main(void)
{
	scanf("%d %d %d", &N, &r, &c);
	recursive((1 << (N-1)), 0, 0, 0);

	return 0;
}
