#include <stdio.h>
#include <string.h>

char N[10][4]={[2]={'A', 'B', 'C'}, [3]={'D','E','F'}, [4]={'G', 'H', 'I'}, [5]={'J', 'K', 'L'}, [6]={'M', 'N', 'O'}, [7]={'P', 'Q', 'R', 'S'}, [8]={'T', 'U', 'V'}, [9]={'W', 'X', 'Y', 'Z'}};

int find(char C) {
	for (int i=2; i<10; i++) {
		for (int j=0; j<4; j++) {
			if (C == N[i][j])
				return i;
		}
	}
}
int main(void)
{
	char input[16];
	int sum=0;

	scanf("%s", input);

	for (int i=0; i<strlen(input); i++) {
		sum += find(input[i])+1;
	}

	printf("%d\n", sum);

	return 0;
}
