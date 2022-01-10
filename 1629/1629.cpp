#include <iostream>

long long getExponent(int a, int b, int c)
{
	if (b == 0) {
		return 1;
	}

	return (b % 2 == 1) ? (getExponent(a, b/2, c) * getExponent(a, b/2, c) % c * a % c) : (getExponent(a, b/2, c) * getExponent(a, b/2, c) % c);
}


int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	
	printf("%lld\n", getExponent(a, b, c));

	return 0;
}
