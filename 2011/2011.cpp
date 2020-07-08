#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[5003];
int dp[5003];
//dp�� 1����
int main(void)
{
	scanf("%s", input);

	if (input[0]=='0') {
		printf("0\n");
		return 0;
	}

	dp[0]=dp[1]=1; // -2 �ϴ� ��� �ε��� ������ ���� ó��

	// ���� ���� ������ �ε����� ���� i, j�� ������� �ε���
	for (int i=1, j=2; i<strlen(input); i++, j++) {
		char tmp[3] = {input[i-1], input[i], '\0'};
		int tmp_num = atoi(tmp);

		if (input[i]-'0'>=0 && input[i]-'0'<=9)
			dp[j]=dp[j-1]%1000000; // ���ڸ� ���� ��� ������ ���� �����´�.
		if (tmp_num >= 10 && tmp_num <= 26 && tmp_num%10!=0)
			dp[j]=(dp[j]+dp[j-2])%1000000; // ���ڸ� �� �ΰ�� ���� ��쿡 2�ܰ� ���� ����
		if (tmp_num >= 10 && tmp_num <= 26 && tmp_num%10==0)
			dp[j]=dp[j-2]%1000000; // 10�� ����� ��� 2ĭ ���� ����� ������
		if ((input[i]-'0'==0 && tmp_num >= 30) || tmp_num==0) {
			dp[strlen(input)]=0; // ���ǿ� ��߳��� ��� �ݺ����� ���߰� 0 ���
			break;
		}
	}

	printf("%d\n", dp[strlen(input)]);

	return 0;
}
