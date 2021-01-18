#include <stdio.h>

int main(void)
{
	freopen("input.txt", "r", stdin);

	int h1, h2, m1, m2, s1, s2, time, cnt;
	char str[1024];

	for (int i = 0; i < 3; i++) {
		cnt = 0;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

		while (1) {
			if (s1 == 60) {
				s1 = 0;
				m1++;
			}

			if (m1 == 60) {
				m1 = 0;
				h1++;
			}

			if (h1 == 24) {
				h1 = 0;
			}

			time = (h1*10000) + (m1*100) + s1;

			if (time % 3 == 0)
				cnt++;

			if (s1 == s2 && m1 == m2 && h1 == h2)
				break;

			s1++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
