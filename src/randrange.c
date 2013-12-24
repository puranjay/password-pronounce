#include "../include/randrange.h"
#include <stdlib.h>

int randRange(int n)
{
	int limit;
	int r;

	limit = RAND_MAX - (RAND_MAX % n);
	while ((r = rand()) >= limit);

	return r % n;
}	
