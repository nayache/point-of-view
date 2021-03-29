#include "main.h"

void	init_map(char ptr[N][N])
{
	int		i;

	i = 0;
	while (i < N)
	{
		bzero(ptr[i], N);
		i++;
	}
}

void	build_pov(t_pov pov[4], char *str)
{
	char	*tmp;
	int		i;
	int		n;

	tmp = strtok(str, " ");
	n = 0;
	while (n < 4)
	{
		i = 0;
		pov[n].side = n;
		while (i < N)
		{
			pov[n].value[i] = atoi(tmp);
			tmp = strtok(NULL, " ");
			i++;
		}
		n++;
	}
}
