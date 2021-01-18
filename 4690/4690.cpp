#include <iostream>

using namespace std;


int main(void)
{
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= i; j++) {
			for (int p = j; p <= i; p++) {
				for (int q = p; q <= i; q++) {
					if ((i*i*i) == (j*j*j) + (p*p*p) + (q*q*q)) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, p, q);
					}
				}
			}
		}
	}

	return 0;
}
