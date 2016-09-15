#include "fillit.h"
#include "libft.h"

/* no 10, check la piece suivante
	#
	###
*/

int		l3(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 5] == '#' && s[i + 7] == '#')
			return (1);	
		else 
			return (0);
	}
}

/* no 9, check la piece suviante
	#
	#
   ##
*/

int		l4(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 9] == '#' && s[i + 10] == '#')
			return (1);
		else
			return (0);
	}
}