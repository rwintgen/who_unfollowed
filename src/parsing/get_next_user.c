/********************************************************\
|*           Nineteen Hundred and Eighty Five           *|
\********************************************************/

#include "who_unfollowed.h"

static char	*read_file(char *str, int fd, const char *tofind);
static char	*add_username(int fd, char *str);
static char	*get_user(char *buffer);
static char	*clean_buffer(char *buf);
static char	*joinandfree(char *str, char *buf);

char	*get_next_user(int fd, const char *tofind)
{
	static char	*buffer;
	char		*user;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(buffer, fd, tofind);
	if (!buffer)
		return (NULL);
	user = get_user(buffer);
	if (user == NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	else
		buffer = clean_buffer(buffer);
	return (user);
}

static char	*read_file(char *str, int fd, const char *tofind)
{
	int		chrd;
	char	*buf;

	buf = calloc(sizeof(char), BUFFER_SIZE + 1);
	chrd = 1;
	if (!str)
		str = calloc(sizeof(char), 1);
	while (chrd != 0 && !strstr(buf, tofind))
	{
		chrd = read(fd, buf, BUFFER_SIZE);
		if (chrd == -1)
		{
			free(str);
			free(buf);
			return (NULL);
		}
		buf[chrd] = '\0';
		str = joinandfree(str, buf);
	}
	if (chrd != 0)
		str = add_username(fd, str);
	free(buf);
	return (str);
}

static char	*add_username(int fd, char *str)
{
	int		chrd;
	char	username[31];

	chrd = read(fd, username, 30);
	if (chrd == -1)
	{
		free(str);
		return (NULL);
	}
	username[chrd] = '\0';
	return (joinandfree(str, username));
}

static char	*get_user(char *buffer)
{
	char	*username_ptr;
	int		username_len;

	username_ptr = strstr(buffer, URL);
	if (!username_ptr)
		return (NULL);
	username_ptr += strlen(URL);
	username_len = 0;
	while (username_ptr[username_len] != '\"')
		username_len++;
	return (strndup(username_ptr, username_len));
}

static char	*clean_buffer(char *buf)
{
	char	*new_buf;
	int		clean_from;

	new_buf = strstr(buf, URL);
	if (!new_buf)
		return (NULL);
	new_buf += strlen(URL);
	clean_from = 0;
	while (new_buf[clean_from] != '\"')
		clean_from++;
	new_buf = strdup(new_buf + clean_from);
	free(buf);
	return (new_buf);
}

static char	*joinandfree(char *str, char *buf)
{
	char	*tmp;

	tmp = strjoin((const char *)str, (const char *)buf);
	free(str);
	return (tmp);
}
