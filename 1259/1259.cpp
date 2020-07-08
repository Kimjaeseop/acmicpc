#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack <int> S;
char str[10];
int SIZE;
bool chk = 0;

int main(void)
{
	while(1) {
		scanf("%s", str);

		if(!strcmp(str, "0")) {
			break;
		}

		SIZE = strlen(str);

		for (int i = 0; i < SIZE; i++, chk = 0) {
			if(i < SIZE / 2) {
				S.push(str[i] - '0');
			}
			else if(SIZE % 2 == 1 && i == (SIZE / 2)) {
				continue;
			}
			else {
				if (S.top() == (str[i] - '0')) {
					S.pop();
				}
				else {
					printf("no\n");
					chk = 1;
					break;
				}
			}
		}

		if (!chk) {
			printf("yes\n");
		}
		
		while(!S.empty()) {
			S.pop();
		}
	}

	return 0;
}
