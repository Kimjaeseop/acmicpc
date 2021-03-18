#include <stdio.h>
#include <string.h>

char in1[1001], in2[1001];
int arr1[26], arr2[26];
int cnt;

int main(void)
{
	int tmp = 0;
	scanf("%s %s", in1, in2);

	for (int i = 0; i < strlen(in1); i++)
		arr1[in1[i] - 'a']++;

	for (int i = 0; i < strlen(in2); i++)
		arr2[in2[i] - 'a']++;

	for (int i = 0; i < 26; i++) {
		tmp = arr1[i] - arr2[i];

		if (tmp != 0) 
			cnt += tmp > 0 ? tmp : -tmp;
	}

	printf("%d\n", cnt);

	return 0;
}
