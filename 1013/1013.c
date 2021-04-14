#include <stdio.h>
#include <string.h>

int N;
char str[256];

void printfNO(void) {
	printf("NO\n");
}

void func(char str[], int index, char state) {
	if (strlen(str) == index) {
		if (state == 'E' || state == 'G' || state == 'F' || state == 'S') 
			printf("YES\n");
		else
			printfNO();

		return ;
	}

	if (state == 'S') {
		if (str[index] == '0')
			func(str, index+1, 'B');
		else
			func(str, index+1, 'A');
	}
	else if (state == 'A') {
		if (str[index] == '0') 
			func(str, index+1, 'C');
		else
			printfNO();
	}
	else if (state == 'B') {
		if (str[index] == '0')
			printfNO();
		else
			func(str, index+1, 'F');
	}
	else if (state == 'C') {
		if (str[index] == '0') 
			func(str, index+1, 'D');
		else
			printfNO();
	}
	else if (state == 'D') {
		if (str[index] == '0') 
			func(str, index+1, 'D');
		else
			func(str, index+1, 'E');
	}
	else if (state == 'E') {
		if (str[index] == '1')
			func(str, index+1, 'G');
		else
			func(str, index+1, 'B');
	}
	else if (state == 'F') {
		func(str, index, 'S');
	}
	else if (state == 'G') {
		if (str[index] == '0')
			func(str, index+1, 'H');
		else
			func(str, index+1, 'G');
	}
	else if (state == 'H') {
		if (str[index] == '1')
			func(str, index+1, 'F');
		else
			func(str, index+1, 'D');
	}
}

int main(void)
{
	//freopen("input_1.txt", "r", stdin);

	scanf("%d", &N);

	while (N--) {
		scanf("%s", str);
		func(str, 0, 'S');
	}

	return 0;
}
