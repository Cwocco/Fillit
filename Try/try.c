#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <stdio.h>

int main()
{
  char *s;
 
  //s = "##..\n##..\n....\n....\n";
  s = ".#..\n###.\n....\n....";
  if (cross4(s) == 1)
    printf("%s", s);
  return (0);
}

int cross4(char *s)
{
  int i;

  i = 0;
  while (i < 20)
    {
      while (s[i] != '#')
	i++;
      if (s[i] == '#' && s[i + 4] == '#' && s[i + 6] == '#')
	return (1);
      else
	return (2);
    }
  return (0);
}
