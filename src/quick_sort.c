#include "common.h"

static void		swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*	Choosing lowest index item as pivot. */
static int		partition(int *p, int low, int high)
{
	int		i;
	int		partition_i;
	int		pivot_i;

	pivot_i = low;
	partition_i = pivot_i;
	i = pivot_i + 1;
	while (i < high)
	{
		if (p[i] < p[pivot_i]) {
			++partition_i;
			swap(&(p[i]), &(p[partition_i]));
		}
		++i;
	}
	swap(&(p[pivot_i]), &(p[partition_i]));
	return (partition_i);
}

static void		p_quick_sort(int *p, int low, int high)
{
	int		partition_i;

	if (high - low < 2)
		return ;
	if (high - low == 2)
	{
		if (p[low] > p[low + 1])
			swap(&(p[low]), &(p[low + 1]));
		return ;
	}
	partition_i = partition(p, low, high);
	p_quick_sort(p, low, partition_i);
	p_quick_sort(p, partition_i + 1, high);
}

void		quick_sort(int *p, int len)
{
	p_quick_sort(p, 0, len);
}
