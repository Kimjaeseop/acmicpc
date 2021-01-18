#include <stdio.h>
#include <string.h>

char str[512];
char c;

void strupr(char (*str)[512])
{
	for (int i = 0; i < strlen(*str); i++) {
		if ('a' <= (*str)[i] && 'z' >= (*str)[i])
			(*str)[i] -= 32;
	}
}

char toupper(char c)
{
	if ('a' <= c && 'z' >= c)
		c -= 32;

	return c;
}

int main(void)
{
	freopen("input.txt", "r", stdin);

	char *ptr[10] = {{'\0',},};

	while(1) {
		scanf("%c", &c);

		if (c == '#')
			return 0;

		fgets(str, sizeof(str), stdin);

		strupr(&str);

		int count = 0;

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == toupper(c))
				count++;
		}
		
		printf("%c %d\n", c, count);
	}

	return 0;
}

