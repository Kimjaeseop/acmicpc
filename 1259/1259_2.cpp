#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[6];
	int r, l;

	while (1) {
		scanf("%s", str);

		if (!strcmp(str, "0"))
			break;

		for (r = strlen(str)-1, l = 0; l <= r; l++, r--) {
			if (str[r] != str[l]) {
				printf("no\n");
				break;
			}
		}

		if (l > r) {
			printf("yes\n");
		}
	}

	return 0;
}
