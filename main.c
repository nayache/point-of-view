#include "main.h"
#include <unistd.h>

int		valid_input(char *str)
{
	char	*tmp;
	int		count;

	tmp = strtok(str, " ");
	if (tmp == NULL)
		return (0);
	count = 0;
	while (tmp != NULL)
	{
		if (tmp[1] != '\0')
			return (0);
		if (atoi(tmp) > N || atoi(tmp) < 1)
			return (0);
		tmp = strtok(NULL, " ");
		count++;
	}
	return (count == N * 4);
}

int		check(t_pov pov[4], char map[N][N], int y, int x, int value)
{
	if (memchr(map[y], value, N) != NULL || occur_col(map, x, value) == 1)
		return (0);
	map[y][x] = value;
	if (col_full(map, x) == 1)
	{
		if (check_up(map, pov[UP].value[x], x) == 0)
			return (0);
		if (check_down(map, pov[DOWN].value[x], x) == 0)
			return (0);
	}
	if (line_full(map, y) == 1)
	{
		if (check_left(map, pov[LEFT].value[y], y) == 0)
			return (0);
		if (check_right(map, pov[RIGHT].value[y], y) == 0)
			return (0);
	}
	return (1);
}

int		compute(char map[N][N], t_pov pov[4], int y, int x)
{
	int	value;
	int next_y;
	int next_x;
	
	if (y == N)
		return (1);
	value = 1;
	while (value <= N)
	{
		if (check(pov, map, y, x, value) == 1)
		{
			next_y = x == N - 1 ? y + 1 : y;
			next_x = x == N - 1 ? 0 : x + 1;
			if (compute(map, pov, next_y, next_x) == 0)
				map[y][x] = 0;
			else
				return (1);
		}
		else
			map[y][x] = 0;
		value++;
	}
	map[y][x] = 0;
	return (0);
}

int		main(int ac, char **av)
{
	t_pov	pov[4];
	char	*input;
	char 	map[N][N];

	if (ac != 2)
	{
		printf("Error : numbers of arguments invalid\n");
		return (-1);
	}
	if ((input = strdup(av[1])) == NULL)
		return (-1);
	if (valid_input(input) == 0)
	{
		printf("Error input\n");
		return (-1);
	}
	free(input);
	build_pov(pov, av[1]);
	init_map(map);
	if (compute(map, pov, 0, 0) == 0)
		printf("unsolvable\n");
	else
		print_map(map, pov);
	return (0);
}
