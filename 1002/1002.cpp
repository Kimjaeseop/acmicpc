#include <iostream>
#include <vector>

#include <stdio.h>

using namespace std;

int T;
int ans;
int arr[20001][20001];

int main(void)
{
	freopen("input_1.txt", "r", stdin);

	cin >> T;

	while (T--) {
		for (int i = 0; i < 20001; i++)
			for (int j = 0; j < 20001; j++) 
				arr[i][j] = 0;

		int x[2] = {0, }, y[2] = {0, }, r[2] = {0, };
		ans = 0;

		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

		for (int n = 0; n <= 1; n++) {
			for (int i = x[n]-r[n]; i <= x[n]+r[n]; i++) {
				printf("(%d, %d), (%d, %d)\n", i,y[n]-r[n]-i ,i, y[n]+r[n]+i);
				arr[i+10000][y[n]-r[n]-i+10000] += 1;
				arr[i+10000][y[n]-r[n]+i+10000] += 1;
			}
		}

		for (int i = 0; i < 20001; i++) 
			for (int j = 0; j < 20001; j++) 
				if (arr[i][j] == 2)
					ans++;

		cout << ans << endl;
	}


	return 0;
}
