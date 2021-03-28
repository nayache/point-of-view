#include "main.h"

int		valid_input(const char *str)
{
	char	*tmp;
	int		count;

	tmp = strtok((char *)str, " ");
	if (tmp == NULL)
		return (0);
	count = 0;
	while (tmp != NULL)
	{
		if (tmp[1] != '\0')
			return (0);
		if ((atoi(tmp) > N || atoi(tmp) < 1))
			return (0);
		tmp = strtok(NULL, " ");
		count++;
	}
	return (count == N * N);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error : numbers of arguments invalid\n");
		return (-1);
	}
	if (valid_input(av[1]) == 0)
	{
		printf("Error input\n");
		return (-1);
	}
	return (0);
}
