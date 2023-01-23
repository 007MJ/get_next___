#include <stdio.h>

int count()
{
	static int count = 0;
	count++;
	return (count);
}

int main()
{
	printf("%d",count());
	printf("\n");
	printf("%d",count());
}
