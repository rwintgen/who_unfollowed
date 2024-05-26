/********************************************************\
|*                Before Your Very Eyes...              *|
\********************************************************/

#include "who_unfollowed.h"

void	init_info(t_info *info)
{
	info->opt_h = false;
	info->opt_x = false;
	info->opt_l = false;
	info->opt_s = false;
	info->opt_o = false;
	info->o_file = NULL;
	info->out_fd = -2;
	info->x_format = NULL;
	info->form_fd = -2;
	info->path = NULL;
	info->followers_path = NULL;
	info->followers_fd = -2;
	info->followings_path = NULL;
	info->followings_fd = -2;
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	result;
	char	**followers = NULL;
	char	**following = NULL;

	if (argc < 2)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	init_info(&info);
	set_options(&info, argv);
	access_files(&info);
	parse_infile(&info, &followers, &following);
	result = compare_arrays(info, followers, following);
	print_struct(result);
	free_all(&info, &result, followers, following);
	return (EXIT_SUCCESS);
}
