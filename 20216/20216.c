#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	freopen("input_2.txt", "r", stdin);
	printf("\n");

	while(1) {
		char str[10001] = {0,};

		fgets(str, 10001, stdin);
		str[strlen(str)-1] = '\0';

		if (strcmp(str, "I quacked the code!\n") == 0)
			exit(0);

		if (str[strlen(str)-1] == '.')
			printf("*Nod*\n\n");
		else if (str[strlen(str)-1] == '?')
			printf("Quack!\n\n");
	}

	return 0;
}
