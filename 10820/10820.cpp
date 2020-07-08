#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

string input;
int lower, upper, num, spc;

int main(void)
{
	//freopen("input.txt", "r", stdin);

	while (getline(cin, input, '\n')) { // eof 문제가 깔끔하게 해결되지 않아 getline 사용
		if (input[0]=='\n')
			break;
		for (int i=0; i<input.size(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z')
				lower++;
			else if (input[i] >= 'A' && input[i] <= 'Z')
				upper++;
			else if (input[i] >= '0' && input[i] <= '9')
				num++;
			else if (input[i]==' ')
				spc++;
		}

		printf("%d %d %d %d\n", lower, upper, num, spc);

		lower = upper = num = spc = 0;
	}

	return 0;
}
