#include "main.h"
#include <unistd.h>

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

void	print_side_pov(t_pov pov)
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
	print_side_pov(pov[0]);
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
	print_side_pov(pov[1]);
}

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

int		check_side(t_pov pov[4], char map[N][N], int y, int x)
{
	if (check_up(map, pov[UP].value[x], x) == 0)
		return (0);
	if (check_down(map, pov[DOWN].value[x], x) == 0)
		return (0);
	if (check_left(map, pov[LEFT].value[y], y) == 0)
		return (0);
	if (check_right(map, pov[RIGHT].value[y], y) == 0)
		return (0);
	return (1);
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
