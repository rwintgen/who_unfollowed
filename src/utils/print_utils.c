/********************************************************\
|*                        Reptilia                      *|
\********************************************************/

#include "who_unfollowed.h"

void	print_err(char *str, int fd)
{
	write(fd, str, strlen(str));
}

void	print_usage(void)
{
	printf("Usage\n");
	printf("\t./who_unfollowed [pathname] -[option] [argument]\n");
}

void	print_help(void)
{
	printf("Usage\n");
	printf("\t./who_unfollowed [pathname] -[option] [argument]\n");
	printf("\n");
	printf("Arguments\n");
	printf("\tpathname: The location of the directory containing your information.");
	printf("Will default to current working directory if none specified.\n");
	printf("\n");
	printf("Options\n");
	printf("\t--outfile / -o [filename]: writes output to outfile whose path");
	printf("corresponds to `filename`. Will default to create a file in");
	printf("current working directory if none specified.\n");
	printf("\t--list / -l: prints all followers and following as");
	printf("human-readable data.\n");
	printf("\t--sort / -s: prints all followers and following sorted aplhabetically");
	printf("and by category (mutually followed accounts, followed by you, following you).\n");
	printf("\t--export / -x [format]: output will be in the format specified by 'format'.");
	printf("\tCurrently compatible with xls only.\n");
	printf("\t--help / -h: prints the help panel.\n");
	printf("\n");
	printf("Uninstall\n");
	printf("\tmake uninstall\n");
	exit(EXIT_SUCCESS);
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("\t%s\n", array[i]);
		i++;
	}
}

void	print_struct(t_data result)
{
	if (result.unfollowers)
	{
		printf("\nUnfollowers:\n");
		print_array(result.unfollowers);
	}
	if (result.unfollowings)
	{
		printf("\nUnfollowings:\n");
		print_array(result.unfollowings);
	}
	if (result.mutual_followed)
	{
		printf("\nMutually Followed:\n");
		print_array(result.mutual_followed);
	}
}
