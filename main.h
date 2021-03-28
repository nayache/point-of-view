#ifndef __MAIN_H
# define __MAIN_H

# include <stdio.h>
# include <stdlib.h>

# define N	4

enum SIDE {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct pov t_pov;

struct pov {
	enum SIDE    side;
	int          value[N];
};

int	valid_input(const char *str);
t_pov	*build_pov(const char *str);
char 	**build_map(void);
int	compute(t_pov *conds, char **map);
void	print_map(char **map);

#endif
