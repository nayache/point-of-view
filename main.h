#ifndef __MAIN_H
# define __MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum	SIDE {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
}				SIDE;

typedef struct pov t_pov;

struct pov {
	SIDE		side;
	int         value[N];
};

int		valid_input(char *str);
void	build_pov(t_pov pov[N], char *str);
void	init_map(char map[N][N]);
void	print_map(char map[N][N], t_pov pov[N]);

#endif
