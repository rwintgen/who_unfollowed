/********************************************************\
|*                    Write This Down                   *|
\********************************************************/

#include "who_unfollowed.h"

static void	close_all_fds(void);
static void	free_array(char **array);

void	free_all(t_info *info, t_data *data, char **followers, char **followings)
{
	free_array(followers);
	free_array(followings);
	close_all_fds();
	if (data->unfollowers)
		free_array(data->unfollowers);
	if (data->unfollowings)
		free_array(data->unfollowings);
	if (data->mutual_followed)
		free_array(data->mutual_followed);
	if (info->o_file)
		free(info->o_file);
	if (info->x_format)
		free(info->x_format);
	if (info->followers_path)
		free(info->followers_path);
	if (info->followings_path)
		free(info->followings_path);
}

static void	close_all_fds(void)
{
	int	i;

	i = 3;
	while (i < 1024)
		close(i++);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}