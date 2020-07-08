#include <stdio.h>
#include <string.h>

int main(void)
{
	char *arr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	char input[101]={0,};
	int cnt=0;

	scanf("%s", input);

	for (int i=0; i<strlen(input); i++) {
		for (int j=0; j<8; j++) {
			if (strncmp(input+i, arr[j], strlen(arr[j])) == 0) {
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
