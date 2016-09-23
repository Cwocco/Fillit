#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <stdio.h>

int square(char *s)
{
  int i;

  i = 0;
  while (i < 20)
    {
      if (s[i] == '#' && s[i + 1] == '#' && s[i + 5] == '#'
	  && s[i + 6] == '#')
	return (1);
      else
	return (2);
      i++;
    }
  return(0);
}


int main()
{
  char *s;
 
   s = ".#..\n##..\n....\n....";
   if (square(s) == 1)
    printf("%s", s);
  return (0);
}