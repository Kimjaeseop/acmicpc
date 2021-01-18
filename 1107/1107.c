#include <stdio.h>

int arr[10];

int check(int num)
{
	int m_cnt = 0, p_cnt = 0, m_save, p_save, m_tmp, p_tmp, cnt, save;

	m_save = p_save = m_tmp = p_tmp = num;

	while (1) {
		while (m_tmp != 0) {
			if (arr[m_tmp % 10] == 1)
				break;

			m_tmp /= 10;
		}

		while (p_tmp != 0) {
			if (arr[p_tmp % 10] == 1)
				break;

			p_tmp /= 10;
		}

		if (!m_tmp) {
			cnt = m_cnt;
			save = m_save;
			break;
		}

		if (!p_tmp) {
			cnt = p_cnt;
			save = p_save;
			break;
		}

		m_tmp = --m_save;
		p_tmp = ++p_save;

		m_cnt++; p_cnt++;
	}

	if (save == 0)
		return cnt + 1;
	
	while (save) {
		cnt++;
		save /= 10;
	}

	return cnt;
}

int main(void)
{
	int num, N, tmp, i;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &num);
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arr[tmp] = 1;
	}

	if (num == 0) {
		for (int i = 0; i < 10; i++) {
			if (arr[i] != 1) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}

	tmp = (100 - num) < 0 ? (100 - num) * -1 : (100 - num);

	if (N == 10) {
		printf("%d\n", tmp);
		return 0;
	}

	N = check(num);

	printf("%d\n", N < tmp ? N : tmp);

	return 0;
}
