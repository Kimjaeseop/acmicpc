#include <stdio.h>

int main (void)
{
	int N;
	long long dp[101][101]={0,};
	long long sum=0;

	// 끝번이 9이거나 0인경우는 하나의 가지만 생성
	// n=1 1 2 3 4 5 6 7 8 9
	// n=2 (12 10) (21 23) (32 33) (43 45) (54 56) (65 67) (76 78) (87 89) 98, 17
	// n=3 (121 123, 101) (210 212, 232 234) (432 434, 454 567) --- (876 878, 898) (987 989)
	// n=4 (1210 1212, 1232 1234, 1010 1012)
	// 각수는 각 수에 해당하는 depth만큼 지날때마다 *2 만큼의 0과 9를 생산
	// ex) 9는 depth가 9의 배수가 될 때 마다 1, 2, 4 ---의 2의 배수만큼 0과 9를 생산
	scanf("%d", &N);

	// 끝자리를 기준으로 몇개인지 넣음
	// ex) dp[1][3], 자리수 1에 끝자리가 3인 수의 개수
	dp[1][0]=0;
	for (int i=1; i<=9; i++) // depth == 0일때 0~9를 가짐
		dp[1][i]=1;

	for (int i=2; i<=N; i++) { // i == 자리수 (depth), j == 끝 자리 숫자
		for (int j=0; j<=9; j++) {
			if (j==0)
				//dp[i][j] = dp[i-1][1] % 1000000000;
				dp[i][j] = dp[i-1][1];
			else if (j==9)
				//dp[i][j] = dp[i-1][8] % 1000000000;
				dp[i][j] = dp[i-1][8];
			else
				//dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];

			dp[i][j] %= 1000000000;
		}
	}

	for (int i=0; i<=9; i++)
		sum += (dp[N][i]%1000000000);
		//sum += dp[N][i];

	printf("%lld\n", sum%1000000000);

	return 0;
}
