#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include <stdio.h>

using namespace std;

int N, T;
double MIN = 10e7;
int arr[21][2];

double pitagoras(int x1, int x2, int y1, int y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main(void) {
	int VSIZE;

	//freopen("input_1.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> N;
		VSIZE = N/2;

		MIN = 0.0;

		for (int i = 0; i < N; i++) 
			cin >> arr[i][0] >> arr[i][1];

		if (N == 2)
			printf("%.6f\n", pitagoras(arr[0][0], arr[1][0], arr[0][1], arr[1][1]));
		else {
			vector<int> flags;
			flags.resize(N/2, 0);

			for (int i = 0; i < VSIZE; i++)
				flags.push_back(1);

			do {
				vector<int> V;

				for (int i = 0; i < N; i++) 
					if (!flags[i])
						V.push_back(i);

				for (int i = 0; i < VSIZE; i++) {
					for (int p = 0; p < N; p++) {
						int x1 = arr[V[i]][0]-arr[p][0];
						int y1 = arr[V[i]][1]-arr[p][1];

						for (int j = i + 1; j < VSIZE; j++) {
							for (int q = p + 1; q < N; q++) {
								int x2 = arr[V[j]][0]-arr[q][0];
								int y2 = arr[V[j]][1]-arr[q][1];

								double res = pitagoras(x1, x2, y1, y2);

								MIN = MIN > res ? res : MIN;
							}
						}
					}
				}
			} while (next_permutation(flags.begin(), flags.end()));

			printf("%.6f\n", MIN);
		}
	}

	return 0;
}



