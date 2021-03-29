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
void	print_up_down_pov(t_pov pov);
void	print_map(char map[N][N], t_pov pov[N]);
int		occur_col(char map[N][N], int x, int value);
int		col_full(char map[N][N], int x);
int		line_full(char map[N][N], int y);
int		check_up(char map[N][N], int requiered, int x);
int		check_down(char map[N][N], int requiered, int x);
int		check_left(char map[N][N], int requiered, int y);
int		check_right(char map[N][N], int requiered, int y);
#endif
