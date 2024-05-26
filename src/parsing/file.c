/********************************************************\
|*                Prophecy of the Dragon                *|
\********************************************************/

#include "who_unfollowed.h"

bool	try_file(char *base_filename, int *fd, char **path)
{
	static char	filename[PATH_MAX];

	strncpy(filename, base_filename, sizeof(filename));
	*fd = open(filename, O_EXCL | O_CREAT | O_RDWR, 0644);
	if (*fd >= 0)
	{
		if (*path)
			free(*path);
		*path = strdup(filename);
		return (true);
	}
	return (false);
}

int	create_file(char **path)
{
	static char	filename[PATH_MAX];
	char		*id_str = NULL;
	int			fd;
	int			i = 0;

	if (!*path)
		*path = strdup("./");
	while (true)
	{
		if (strlen(*path) >= PATH_MAX - 1)
			return (E_PATH_TOO_LONG);
		strncpy(filename, *path, sizeof(filename) - 1);
		filename[sizeof(filename) - 1] = '\0';
		if (strlen(filename) == 0 || filename[strlen(filename) - 1] != '/')
			strncat(filename, "/", sizeof(filename) - strlen(filename) - 1);
		strncat(filename, "followers_report_", sizeof(filename) - strlen(filename) - 1);
		id_str = itoa(i++);
		if (strlen(filename) + strlen(id_str) + 1 < sizeof(filename))
		{
			strncat(filename, id_str, sizeof(filename) - strlen(filename) - 1);
			if (try_file(filename, &fd, path))
			{
				free(id_str);
				return (fd);
			}
		}
		else
		{
			free(id_str);
			break ;
		}
		free(id_str);
	}
	return (-1);
}

void	handle_outfile(t_info *info)
{
	if (info->opt_o)
	{
		if (!info->o_file || isdirectory(info->o_file))
		{
			create_file(&info->o_file);
		}
		info->out_fd = open(info->o_file, O_CREAT | O_RDWR, 0644);
		if (info->out_fd == -1)
		{
			print_err(MSG_OUT, STDERR_FILENO);
			print_err(info->o_file, STDERR_FILENO);
			print_err("\n", STDERR_FILENO);
			exit(E_INVALID_OUT);
		}
		dup2(info->out_fd, STDOUT_FILENO);
	}
}

void	access_files(t_info *info)
{
	char	*path_cpy;
	DIR *dir;

	if (info->opt_h)
	{
		print_help();
		exit(EXIT_SUCCESS);
	}
	else
	{
		path_cpy = strdup(info->path);
		if (info->path[strlen(info->path) - 1] != '/')
			info->path = strjoin(path_cpy, "/");
		free(path_cpy);
		dir = opendir(info->path);
		if (dir == NULL)
		{
			print_err(MSG_PATH, STDERR_FILENO);
			print_err(info->path, STDERR_FILENO);
			print_err("\n", STDERR_FILENO);
			exit(E_INVALID_PATH);
		}
		info->followers_fd = get_followers_file(info->path);
		info->followings_fd = get_followings_file(info->path);
		handle_outfile(info);
		closedir(dir);
	}
}
