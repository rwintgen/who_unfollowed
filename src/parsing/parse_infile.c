/********************************************************\
|*                 Beneath The Underdog                 *|
\********************************************************/

#include "who_unfollowed.h"

static void	get_followers(char ***followers, int fd);
static void	get_followings(char ***followings, int fd);

void	parse_infile(t_info *info, char ***followers, char ***followings)
{
	get_followers(followers, info->followers_fd);
	get_followings(followings, info->followings_fd);
}

void	add_to_array(char ***array, char *str)
{
	int	i;

	i = 0;
	if (*array == NULL)
	{
		*array = malloc(sizeof(char *));
		(*array)[0] = NULL;
	}
	while ((*array)[i] != NULL)
		i++;
	*array = realloc(*array, sizeof(char *) * (i + 2));
	(*array)[i] = strdup(str);
	(*array)[i + 1] = NULL;
}

static void	get_followers(char ***followers, int fd)
{
	char	*line;

	line = get_next_user(fd, URL);
	while (line)
	{
		add_to_array(followers, line);
		free(line);
		line = get_next_user(fd, URL);
	}
}

static void	get_followings(char ***followings, int fd)
{
	char	*line;

	line = get_next_user(fd, URL);
	while (line)
	{
		add_to_array(followings, line);
		free(line);
		line = get_next_user(fd, URL);
	}
}
