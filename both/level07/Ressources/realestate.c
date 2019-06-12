#include <stdio.h>

int		main(void)
{
	int		i;
	unsigned long long	tmp;


	for (i = 0; i <= 100 ; i++)
	{
		tmp = 0xaaaaaaab;
		tmp *= i;
		tmp = tmp >> 32;
		tmp = tmp >> 1;
		tmp *= 3;
		tmp -= i;
		if (tmp)
			printf("%3d - OK\n", i);
		else
			printf("%3d - ERROR\n", i);
	}
	return 0;
}
