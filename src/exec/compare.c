/********************************************************\
|*                    No Hay Mañana                     *|
\********************************************************/

#include "who_unfollowed.h"

static void	init_result(t_data *result);
static void	get_unfollowers(t_data *result, char **followers, char **followings);
static void	get_unfollowings(t_data *result, char **followers, char **followings);
static void	get_mutual_followed(t_data *result, char **followers, char **followings);



t_data	compare_arrays(t_info info, char **followers, char **followings)
{
	t_data	result;

	init_result(&result);
	if (!info.opt_l && !info.opt_s)
		get_unfollowers(&result, followers, followings);
	else if (info.opt_s)
	{
		sort_array(&followers);
		sort_array(&followings);
		get_unfollowers(&result, followers, followings);
		get_unfollowings(&result, followers, followings);
		get_mutual_followed(&result, followers, followings);
	}
	else if (info.opt_l)
	{
		print_array(followers);
		print_array(followings);
	}
	return (result);
}

static void	init_result(t_data *result)
{
	result->unfollowers = NULL;
	result->unfollowings = NULL;
	result->mutual_followed = NULL;
}

static void	get_unfollowers(t_data *result, char **followers, char **followings)
{
	int	i;
	int	j;

	i = 0;
	while (followings[i])
	{
		j = 0;
		while (followers[j])
		{
			if (strcmp(followings[i], followers[j]) == 0)
				break ;
			j++;
		}
		if (followers[j] == NULL)
			add_to_array(&result->unfollowers, followings[i]);
		i++;
	}
}

static void	get_unfollowings(t_data *result, char **followers, char **followings)
{
	int	i;
	int	j;

	i = 0;
	while (followers[i])
	{
		j = 0;
		while (followings[j])
		{
			if (strcmp(followers[i], followings[j]) == 0)
				break ;
			j++;
		}
		if (followings[j] == NULL)
			add_to_array(&result->unfollowings, followers[i]);
		i++;
	}
}

static void	get_mutual_followed(t_data *result, char **followers, char **followings)
{
	int	i;
	int	j;

	i = 0;
	while (followers[i])
	{
		j = 0;
		while (followings[j])
		{
			if (strcmp(followers[i], followings[j]) == 0)
				add_to_array(&result->mutual_followed, followers[i]);
			j++;
		}
		i++;
	}
}
