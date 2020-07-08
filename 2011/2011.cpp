#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[5003];
int dp[5003];
//dp는 1부터
int main(void)
{
	scanf("%s", input);

	if (input[0]=='0') {
		printf("0\n");
		return 0;
	}

	dp[0]=dp[1]=1; // -2 하는 경우 인덱스 문제로 인한 처리

	// 위와 같은 문제로 인덱스로 인한 i, j로 구분지어서 인덱스
	for (int i=1, j=2; i<strlen(input); i++, j++) {
		char tmp[3] = {input[i-1], input[i], '\0'};
		int tmp_num = atoi(tmp);

		if (input[i]-'0'>=0 && input[i]-'0'<=9)
			dp[j]=dp[j-1]%1000000; // 한자리 수인 경우 이전의 수를 가져온다.
		if (tmp_num >= 10 && tmp_num <= 26 && tmp_num%10!=0)
			dp[j]=(dp[j]+dp[j-2])%1000000; // 두자리 수 인경우 현재 경우에 2단계 전을 합함
		if (tmp_num >= 10 && tmp_num <= 26 && tmp_num%10==0)
			dp[j]=dp[j-2]%1000000; // 10의 배수인 경우 2칸 전의 결과를 가져옴
		if ((input[i]-'0'==0 && tmp_num >= 30) || tmp_num==0) {
			dp[strlen(input)]=0; // 조건에 어긋나는 경우 반복문을 멈추고 0 출력
			break;
		}
	}

	printf("%d\n", dp[strlen(input)]);

	return 0;
}
