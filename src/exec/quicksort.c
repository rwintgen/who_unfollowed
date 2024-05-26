/********************************************************\
|*                       Dolerme                        *|
\********************************************************/

#include "who_unfollowed.h"

static void	quicksort(char **array, int low, int high);
static int	partition(char **array, int low, int high);
static void	swap(char **a, char **b);

void	sort_array(char ***array)
{
	int	n;

	n = 0;
	while ((*array)[n])
		n++;
	quicksort(*array, 0, n - 1);
}

static void	quicksort(char **array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

static int	partition(char **array, int low, int high)
{
	char	*pivot;
	int		i;

	pivot = array[high];
	i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (strcmp(array[j], pivot) < 0)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}
