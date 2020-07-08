#include <stdio.h>

int arr[5];
int ans;

int main(void)
{
	for (int i=0; i<5; i++)
		scanf("%d", &arr[i]);

	for (int i=0; i<5; i++)
		ans += arr[i] * arr[i];

	printf("%d\n", ans%10);

	return 0;
}


