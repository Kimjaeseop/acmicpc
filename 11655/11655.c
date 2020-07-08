#include <stdio.h>
#include <string.h>

char input[102];

int main(void)
{
	freopen("input2.txt", "r", stdin);
	fgets(input, sizeof(input), stdin);

	for (int i=0; i<strlen(input); i++) {
		char tmp = input[i];

		if (tmp>='a' && tmp<='z') {
			if (tmp+13>'z')
				tmp-=13;
			else
				tmp+=13;
		}

		if (tmp>='A' && tmp<='Z') {
			if (tmp+13>'Z')
				tmp-=13;
			else
				tmp+=13;
		}

		printf("%c", tmp);
	}

	return 0;
}


