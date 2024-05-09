#include "Stack.h"

int main()
{
	ST s;
	STInit(&s);

	STPush(&s, 1);
	printf("%d ", STTop(&s));
	STPush(&s, 2);
	printf("%d ", STTop(&s));
	STPush(&s, 3);
	printf("%d ", STTop(&s));
	STPush(&s, 4);
	printf("%d ", STTop(&s));
	STPush(&s, 5);
	printf("%d ", STTop(&s));

	//printf("%d ", STTop(&s));
	//STPop(&s);
	//printf("%d ", STTop(&s));
	//STPop(&s);
	//printf("%d ", STTop(&s));
	//STPop(&s);
	//printf("%d ", STTop(&s));
	//STPop(&s);
	//printf("%d ", STTop(&s));
	//STPop(&s);

	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}

	STDestroy(&s);
	return 0;
}


