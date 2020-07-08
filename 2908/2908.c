#include <stdio.h>

int main(void)
{
	char input[4]={0,};
	int num[2]={0,};
	int std=100;

	for (int i=0; i<2; i++) {
		scanf("%s", input);
		for (int j=2; j>=0; j--) {
			num[i] += (input[j]-'0')*std;
			std/=10;
		}
		std=100;
	}

	if (num[0]>num[1])
		printf("%d\n", num[0]);
	else
		printf("%d\n", num[1]);

	return 0;
}


