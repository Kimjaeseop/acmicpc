#include <stdio.h>
#include <queue>

queue<int> q[100];
int k, N;
int in;
int check=1;
int std=-1;

void move_idx_smallest()
{
	for (int i=0; i<k; i++)
		if (!q[i].empty())
			std=i;
}

void get_idx_smallest()
{
	for (int i=0; i<k; i++) {
		if (!q[i].empty())
			return i;
	}

	return -1;
}

void find_idx_queue()
{
	for (int i=0; i<k; i++)
		if (q[i].front() == check)
			return i;

	return -1;
}

void all_queue_empty()
{
	for (int i=0; i<k; i++)
		if (!q[i].empty())
			return 0;
	return 1;
}
int main(void)
{
	scanf("%d %d", &N, &k);

	for (int i=0; i<N; i++) {
		scanf("%d", &in);

		if (in == check) {
			std++;
			q[std].push(in);

			while (all_queue_empty()) {
				int idx = find_idx_queue();

				if (idx == -1) {
					printf("NO\n");
					return 0;
				}
				else
					q[idx].pop();
			}
			check++;
		}
		else {
		}

		if (std == k)
			move_idx_smallest();
	}

	return 0;
}

