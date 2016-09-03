#include <stdio.h>

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

void	print_coord(t_coord *c)
{
	printf("%d - %d\n", c->x, c->y);
}

int		main(void)
{
	t_coord pos;

	pos.x = 5;
	pos.y = 10;
	print_coord(&pos);
}