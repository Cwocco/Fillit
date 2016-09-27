#include <stdio.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

int count_tetri(char *file)
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
      if (x < 5)
	{
	  if (file[i] == '.' || file[i] == '#')
	    i++;
	  else
	    return (1);
	  x++;
	}
      if (x == 4)
	{
	  if (file[i] != '\n')
	    return (1);
	  i++;
	  x = 0;
	  y++;
	}
      //opti_count(x, y, i);
      if (y == 4)
	{
	  nb_tetri++;
	  if (file[i] == '\0')
	    return (nb_tetri);
	  //printf("Test2");
	  else if (file[i] == '\n')
	    {
	      i++;
	      y = 0;
	    }
	  else
	    return (1); 
	}
    }
  return (0);
}

int main()
{
  char *file;
  
  file = "....\n####\n....\n....\n\n....\n....\n####\n....\n";
  if (count_tetri(file) != '0')
    printf("%s", file);
  return (0);
}
