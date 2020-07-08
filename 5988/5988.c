#include <stdio.h>
#include <string.h>

char input[61];

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i=0; i<T; i++) {
		scanf("%s", input);

		printf("%s\n", (int)(input[strlen(input)-1] - '0')%2 ? "odd" : "even"); 
		memset(input, 61, 0);
	}

	return 0;
}
