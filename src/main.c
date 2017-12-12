#include "fillit.h"

static int		ft_check_number_arg(int ac)
{
	char	*usage;

	usage = "usage : ./fillit [file name]\n";//
	if (ac != 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
	return (1);
}

char			*ft_check(char *str)
{
	int i;
	size_t sharp;

	i = 0;
	sharp = 0;
	if (!str)
		return (NULL);
	while (str)
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			sharp += 1;
			i++;
		}
		i++;
	}
	return (str);
}



int				main(int ac, char **av)
{
	int		open_file;
	char	*buf;
	char	*str_tetra;
	int		read_file;

	read_file = 0;
	open_file = 0;
	str_tetra = ft_strnew(21);//
	buf = ft_strnew(21);//
	if ((ft_check_number_arg(ac)) == 0)
		return (0);
	open_file = open(av[1], O_RDONLY);
	if (open_file == -1)
	{
		ft_putstr_fd("open() failed\n", 2);
		return (1);
	}
	if (read_file == -1)
	{
		ft_putstr_fd("read() failed\n", 2);
		return (1);
	}
	while ((read_file = read(open_file, buf, 21)) > 0)
	{
		buf[read_file] = '\0';
		str_tetra = ft_strcat(str_tetra, buf);
		buf = ft_strnew(21);//
	}
	free(buf);
	ft_putstr(str_tetra);//
	if (close(open_file) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (1);
	}
	return (0);
}

/*
   static t_list	*ft_fill_struct(char *str)
   {
   l_tetra *list;
   l_tetra *begin;

   if (!(list = (l_tetra *)malloc(sizeof(l_tetra))))
   return(NULL);
   if (str)
   {
 * TODO : replace this fuckin' dynamic memory allocation by
 * by simple hard allocation because the size that must be 
 * allocated is always the same. Fuckin' bitch!
 if (!(list->tetra = (char*)malloc(sizeof(21))))//
 return (NULL);// 
 list->tetra = ft_memcpy(list->tetra, (const void*)str, 20);
 str = ft_str_counter(str);
 list->next = list;
 begin = list;
 }
 while (str)//
 {
 if (!(list->tetra = (char*)malloc(sizeof(21))))//
 return (NULL);//
 list->tetra = ft_memcpy(list->tetra, (const void*)str, 20);
 str = ft_str_counter(str);
 list->next = list;
 }
 if (!(str))
 list->tetra = NULL;
 list->next = NULL;
 return (l_tetra);
 }

 static char		*ft_str_counter(char *str)
 {
 char *ptr_str;

 ptr_str = str;
 while (*ptr_str != '\0' && *ptr_str != '\n' && (*ptr_str - 1) != '\n')
 ptr_str++;
 return (ptr_str);
 }
 */
