#include <iostream>
#include <cmath>

using namespace std;

//output1 정답
//output2 오답

//1의 실행 결과 중 16, 17번째줄을 비교해보면
//하나의 i값의 값이 내부 반복문에 의해서 dp[i]가 계속 최소값으로 감소한다.
//이 과정때문에 dp[i]와의 최소값 비교가 필요한 것

//2번을 실행하게되면 내부 반복문에서 감소한 값이 비교되지 못하므로
//최소값을 도출하지 못한다.

int dp[100501];
int N;

int main(void)
{
    int s=0;

	//freopen("output2.txt", "w+", stdout);
	scanf("%d", &N);

    s = sqrt(N);

	dp[0]=0;
	dp[1]=1;

    for (int i=2; i<=N; i++) {
		dp[i]=i; // 1

		if (i<=s)
			dp[i*i]=1;

        if (dp[i]==1)
            continue;

        for (int j=1; j*j<=i; j++) {
			//printf("%d : %d, %d : %d\n", i-j*j, dp[i-j*j], i, dp[i]); // 1
			//printf("%d : %d, %d : %d\n", i-j*j, dp[i-j*j], j+i-j, dp[j]+dp[i-j]); // 2
			dp[i] = min(dp[i-j*j]+1, dp[i]); // 1
			//dp[i] = min(dp[i-j*j]+1, dp[j]+dp[i-j]); // 2
		}
	}

	printf("%d\n", dp[N]);

    return 0;
}

