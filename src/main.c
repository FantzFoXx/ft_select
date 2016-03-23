#include "libft.h"
#include "ft_select.h"

int		main(int argc, char **argv, char **environ)
{
	(void)environ;
	t_all *global;

	if (argc < 2)
		return (1);
	global = t_all_new();
	init_env(global, argv);

	return (0);
}
