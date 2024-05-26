/********************************************************\
|*                     Self Control                     *|
\********************************************************/

#include "who_unfollowed.h"

void	set_options(t_info *info, char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (strcmp(argv[i], "--outfile") == 0 || strcmp(argv[i], "-o") == 0)
		{
			info->opt_o = true;
			if (argv[i + 1])
				info->o_file = strdup(argv[i + 1]);
		}
		else if (strcmp(argv[i], "--list") == 0 || strcmp(argv[i], "-l") == 0)
			info->opt_l = true;
		else if (strcmp(argv[i], "--sort") == 0 || strcmp(argv[i], "-s") == 0)
			info->opt_s = true;
		else if (strcmp(argv[i], "--export") == 0 || strcmp(argv[i], "-x") == 0)
		{
			info->opt_x = true;
			info->x_format = argv[i + 1];
			print_err(MSG_EXPORT, STDERR_FILENO);
			exit(E_EXPORT);
		}
		else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
			info->opt_h = true;
		else if (strncmp(argv[i], "-", 1) == 0)
		{
			print_err(MSG_OPTION, STDERR_FILENO);
			print_err(argv[i], STDERR_FILENO);
			print_err("\n", STDERR_FILENO);
			exit(E_INVALID_OPTION);
		}
		else if (i == 1)
			info->path = argv[i];
		i++;
	}
}
