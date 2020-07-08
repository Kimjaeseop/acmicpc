#include <stdio.h>

char c;

int main(void)
{
	freopen("input.txt", "r", stdin);

	while ((scanf("%c", &c) != EOF)) {
		printf("%c", c);
	}

	return 0;
}
