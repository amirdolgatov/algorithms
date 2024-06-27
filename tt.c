#include <stdio.h>


int main(int argc, char const *argv[])
{
	int x[10] = {1, 0, 1, 0, 0, 1, 0, 0, 0, 0};
	int a[10];
	int size = 1;

	a[0] = x[0];

	for (int i = 1; i < 10; ++i)
	{
		int j = 0;
		while(x[i] != a[j] && j++ < size)
			;
		if (j >= size)
		{
			a[size] = x[i];
			++size;
		}
	}

	printf("%d\n", size);

	return 0;
}