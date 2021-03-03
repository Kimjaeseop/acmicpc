#include <stdio.h>
#include <time.h>

int main(void)
{
	struct tm *local;
	time_t curtime;

	time(&curtime);
	local =	localtime(&curtime);

	printf("%d-%02d-%02d\n", (local->tm_year)+1900, (local->tm_mon)+1, local->tm_mday);

	return 0;
}

