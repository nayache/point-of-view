#include "main.h"

void	print_up_down_pov(t_pov pov)
{
	int i;

	i = 0;
	printf("     \e[1;4;44m ");
	while (i < N)
	{
		if (pov.side == UP)
			printf("\e[1;4;44m %d", pov.value[i]);
		else
			printf("\e[1;44m %d", pov.value[i]);
		if (i + 1 != N)
			printf("   ");
		else
			printf(" ");
		i++;
	}
	printf("\e[0;38m");
	printf("\n");
}

void	print_map(char map[N][N], t_pov pov[4])
{
	int i;
	int j;

	i = 0;
	print_up_down_pov(pov[0]);
	while (i < N)
	{
		j = 0;
		printf("\e[1;4;44m  %d  \e[0;38m", pov[2].value[i]);
		while (j < N)
		{
			printf("\e[0;4;40m  %d ", map[i][j]);
			if (j + 1 < N)
				printf(" ");
			j++;
		}
		printf("\e[1;4;44m  %d  \e[0;38m\n", pov[3].value[i]);
		i++;
	}
	print_up_down_pov(pov[1]);
}
