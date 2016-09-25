header ..


#include "fillit.h"

int		error(int e)
{
	if (e == 1)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	else if (e == 2)
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
}