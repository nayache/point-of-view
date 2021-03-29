#include "main.h"

int		check_up(char map[N][N], int requiered, int x)
{
	int	i;
	int	max;
	int viewed;

	max = map[0][x];
	viewed = 1;
	i = 1;
	while (i < N)
	{
		if (map[i][x] > max)
		{
			max = map[i][x];
			viewed++;
		}
		i++;
	}
	if (viewed == requiered)
		return (1);
	return (0);
}

int		check_down(char map[N][N], int requiered, int x)
{
	int	i;
	int	max;
	int viewed;

	max = map[N - 1][x];
	viewed = 1;
	i = N - 2;
	while (i >= 0)
	{
		if (map[i][x] > max)
		{
			max = map[i][x];
			viewed++;
		}
		i--;
	}
	if (viewed == requiered)
		return (1);
	return (0);
}

int		check_left(char map[N][N], int requiered, int y)
{
	int	i;
	int	max;
	int viewed;

	max = map[y][0];
	viewed = 1;
	i = 1;
	while (i < N)
	{
		if (map[y][i] > max)
		{
			max = map[y][i];
			viewed++;
		}
		i++;
	}
	if (viewed == requiered)
		return (1);
	return (0);
}

int		check_right(char map[N][N], int requiered, int y)
{
	int	i;
	int	max;
	int viewed;

	max = map[y][N - 1];
	viewed = 1;
	i = N - 2;
	while (i >= 0)
	{
		if (map[y][i] > max)
		{
			max = map[y][i];
			viewed++;
		}
		i--;
	}
	if (viewed == requiered)
		return (1);
	return (0);
}
