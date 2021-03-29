#include "main.h"

int		occur_col(char map[N][N], int x, int value)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (map[i][x] == value)
			return (1);
		i++;
	}
	return (0);
}

int		col_full(char map[N][N], int x)
{
	int y;

	y = 0;
	while (y < N)
	{
		if (map[y][x] == 0)
			return (0);
		y++;
	}
	return (1);
}

int		line_full(char map[N][N], int y)
{
	int x;

	x = 0;
	while (x < N)
	{
		if (map[y][x] == 0)
			return (0);
		x++;
	}
	return (1);
}
