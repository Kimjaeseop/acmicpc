#include <stdio.h>

int fact (int n)
{
	if (!n)
		return 1;

	for (int i = n-1; i != 0; i--) 
		n *= i;

	return n;
}

int combination (int n, int r)
{
	if (!(n-r))
		return 1;
	else
		return fact(n)/(fact(r)*fact(n-r));
}
