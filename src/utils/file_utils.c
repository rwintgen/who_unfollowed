/********************************************************\
|*             Everything In Its Right Place            *|
\********************************************************/

#include "who_unfollowed.h"

char	*strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		combsize;
	char	*combstr;

	if (!s1)
		return (NULL);
	if (s1 && !s2)
		return (strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	combsize = strlen(s1) + strlen(s2) + 1;
	combstr = malloc(sizeof(char) * combsize);
	if (!combstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		combstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		combstr[i + j] = s2[j];
		j++;
	}
	combstr[i + j] = '\0';
	return (combstr);
}

bool	isdirectory(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		return (true);
	}
	else
		return (false);
}

char	*itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	i = n;
	len = 1;
	while (i /= 10)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	get_followers_file(char *dirpath)
{
	char	*fullpath;
	int		fd;

	fullpath = strjoin(dirpath, FOLLOWERS_FILE_HTML);
	if (!fullpath)
	{
		print_err(MSG_MALLOC, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fd = open(fullpath, O_RDONLY);
	if (fd == -1)
	{
		print_err(MSG_PATH, STDERR_FILENO);
		print_err(fullpath, STDERR_FILENO);
		print_err("\n", STDERR_FILENO);
		exit(E_INVALID_PATH);
	}
	free(fullpath);
	return (fd);
}

int	get_followings_file(char *dirpath)
{
	char	*fullpath;
	int		fd;

	fullpath = strjoin(dirpath, FOLLOWINGS_FILE_HTML);
	if (!fullpath)
	{
		print_err(MSG_MALLOC, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fd = open(fullpath, O_RDONLY);
	if (fd == -1)
	{
		print_err(MSG_PATH, STDERR_FILENO);
		print_err(fullpath, STDERR_FILENO);
		print_err("\n", STDERR_FILENO);
		exit(E_INVALID_PATH);
	}
	free(fullpath);
	return (fd);
}
