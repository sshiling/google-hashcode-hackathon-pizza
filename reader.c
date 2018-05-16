
#include "hashcode_pizza.h"

t_pizza		*reader(int fd)
{
	char 	*line;
	char 	**c;
	int 	i;
	t_pizza *list;

	i = 0;
	list = (t_pizza *)malloc(sizeof(t_pizza));
	if (fd == -1)
		return (NULL);
	get_next_line(fd,&line);
	c = ft_strsplit(line, ' ');
	list->rows = ft_atoi(c[0]);
	list->columns = ft_atoi (c[1]);
	list->min_ingr = ft_atoi (c[2]);
	list->max_cells = ft_atoi(c[3]);
	list->pizza = (char**)malloc(sizeof(char*) * (list->rows + 1));
	while(get_next_line(fd,&line) && i < list->rows)
	{
		list->pizza[i] = ft_strdup(line);
		i++;
	}
	list->pizza[i] = NULL;
	return(list);
}
