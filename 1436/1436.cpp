#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char tmp[10];
vector <int> V;

int main(void)
{
	scanf("%d", &N);
	// 문자열 앞뒤로 숫자를 붙여서 트리를 만들거나
	// 문자열 연산 없이 단순히 수를 나눠서 구하면 더 좋은 시간 복잡도를 갖을 수 있지만
	// sort할 필요없는 방법으로 구현
	// 별로 잘 짠 알고리즘 코드가 아님 다시 구현해봐야겠음
	for (int i=666; N>=V.size(); i++) {
		sprintf(tmp, "%d", i);
		for (char *c = tmp; *c != '\0'; c++) {
			if ((*c == *(c + 1)) &&(*(c + 1) == *(c + 2)) && (*(c+2) == '6')) {
				V.push_back(atoi(tmp));
				break;
			}
		}
	}

	printf("%d\n", V[N-1]);

	return 0;
}
