#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N;
	int cnt=1;
	queue <int> q;

	cin >> N;

	if (N==1) {
		cout << 0 << endl;
		return 0;
	}

	q.push(N);

	while (1) {
		int size = q.size();

		for (int i=0; i<size; i++) {
			int tmp = q.front();
			q.pop();

			if (!(tmp%3))
				q.push(tmp/3);
			if (!(tmp%2))
				q.push(tmp/2);
			
			q.push(tmp-1);

			if ((!(tmp%3)&&tmp/3==1) || (!(tmp%2)&&tmp/2==1) || tmp-1==1) {
				cout << cnt << endl;
				return 0;
			}
		}
		cnt++;
	}

	return 0;
}



