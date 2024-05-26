/********************************************************\
|*                          S91                       *|
\********************************************************/

#ifndef WHO_UNFOLLOWED_H
# define WHO_UNFOLLOWED_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <regex.h>
# include <pthread.h>
# include <sys/wait.h>

# define PATH_MAX 4096
# define BUFFER_SIZE 4096
# define URL "https://www.instagram.com/"
# define FOLLOWERS_FILE_HTML "followers_1.html"
# define FOLLOWINGS_FILE_HTML "following.html"

# define MSG_EXPORT "who_unfollowed: export option not implemented yet\n"
# define MSG_MALLOC "who_unfollowed: malloc error\n"
# define MSG_OPTION "who_unfollowed: invalid option: "
# define MSG_PATH "who_unfollowed: invalid path: "
# define MSG_OUT "who_unfollowed: invalid output file: "
# define MSG_WIP "who_unfollowed: work in progress: export\n\
Still working on this one!\n"
# define MSG_DIR "who_unfollowed: path is a directory: "
# define MSG_FORK "who_unfollowed: fork error\n"

typedef enum e_err
{
	E_INVALID_PATH = 2,
	E_INVALID_OPTION,
	E_EXPORT,
	E_INVALID_OUT,
	E_PATH_TOO_LONG,
	E_FORK_FAILED
}	t_err;

typedef struct s_info
{
	bool	opt_h;
	bool	opt_x;
	bool	opt_l;
	bool	opt_s;
	bool	opt_o;

	char	*o_file;
	int		out_fd;

	char	*x_format;
	int		form_fd;

	char	*path;
	char	*followers_path;
	int		followers_fd;
	char	*followings_path;
	int		followings_fd;
}	t_info;

typedef struct s_data
{
	char	**unfollowers;
	char	**unfollowings;
	char	**mutual_followed;
}	t_data;

char	*strjoin(char const *s1, char const *s2);
bool	isdirectory(char *path);
bool	try_file(char *base_filename, int *fd, char **path);
int		create_file(char **path);
void	access_files(t_info *info);
void	init_info(t_info *info);
int		main(int argc, char **argv);
void	set_options(t_info *info, char **argv);
void	print_err(char *str, int fd);
void	print_help(void);
void	print_usage(void);
void	o(void);
void	print_array(char **array);
char	*itoa(int n);
void	parse_infile(t_info *info, char ***followers, char ***followings);
int		get_followers_file(char *dirpath);
int		get_followings_file(char *dirpath);
char	*read_until_https(int fd);
char	*get_next_user(int fd, const char* str);
void	free_all(t_info *info, t_data *data, char **followers, char **followings);
t_data	compare_arrays(t_info info, char **followers, char **following);
void	add_to_array(char ***array, char *str);
void	print_struct(t_data result);
void	sort_array(char ***array);

#endif