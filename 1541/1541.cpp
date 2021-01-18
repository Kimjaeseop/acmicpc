#include <stdio.h>

// BFS로 모든 경우의 문자열을 만들고자 했지만 아닌 것 같아서
// 고민 후 서칭해서 찾음
// -(A + B) < -A + B 항상 성립
// A - B == -(-A + B)

// A - (B ? C ? D ? E ? F) NULL
// NULL에서 괄호 친 부분 마이너스 플러스 상관 없이 더한 뒤 빼주면 된다.

// http://wookje.dance/2019/01/23/boj-1541/

// 배운 것
// str[i-1] : null check

// 55-50+40

char str[128] = {1}; // str[i-1]에서 걸리지 않기 위한 초기화
int n, t, f, sum;

int main(void)
{
	freopen("input.txt", "r", stdin);

	scanf("%s", str + 1);

	for (int i = 1; str[i-1]; i++) {
		if ('0' <= str[i] && '9' >= str[i]) {
			n *= 10; n += (str[i] - '0');
		}
		else if (str[i] == '+') {
			t += n;
			n = 0;
		}
		else {
			t += n;
			n = 0;

			sum += f ? -t : t;

			t = 0;
			f = (str[i] == '-');
		}
	}

	printf("%d\n", sum);

	return 0;
}

