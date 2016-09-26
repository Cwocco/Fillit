header..

#include "libft.h"
#include "fillit.h"

static int opti_count(int x, int y)
{
	
}

int		count_tetri(char *file)
{
	int i;
	int x;
	int y;
	int nb_tetri;

	i = 0;
	x = 0;
	y = 0;
	nb_tetri = 0;
	while (file[i] != '\0')
	{
		if (x < 4)
		{
			if (file[i] == '.' || file[i] == '#')
				i++;
			else
				return (0);
			x++;
		}
		if (x == 4)
		{
			if (file[i] != '\n')
				return (0);
			i++;
			x = 0;
			y++;
		}
		if (y == 4)
		{
			nb_tetri++;
			if (file[i] == '\0')
				return (nb_tetri);
			else if (file[i] == '\n')
			{
				i++;
				y = 0;
			}
			else
				return (0); 
		}
	}
	return (0);
}