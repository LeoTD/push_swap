#ifndef COMMON_H
# define COMMON_H

# ifdef PRINT_MODE
#  include <stdio.h>
#  define XPRINTF(...) printf(__VA_ARGS__)
# else
#  define XPRINTF(...) do{}while(0)
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#define IF_NULL(x,y) {if (NULL == (x)) { return y; }}

struct			s_stack
{
	int					*arr;
	int					top;
	int					n;
};

struct			s_data
{
	struct s_instlist	*ops;
	struct s_stack		*a;
	struct s_stack		*b;
};

struct s_data	*init_data(int len, char **input);
void			print_stacks(struct s_stack *a, struct s_stack *b);

/*
**	Instructions:
*/

void			arr_swap(struct s_stack *s);
void			arr_push(struct s_stack *to, struct s_stack *from);
void			arr_rot(struct s_stack *s);
void			arr_rrot(struct s_stack *s);
void			dispatcher(char *op, struct s_stack *a, struct s_stack *b);

/*
**	Library Functions:
*/

long			xatoi(char *s);
int				xstrlen(char *s);
void			xputs(char *s);
void			quick_sort(int *p, int len);

/*
**	Array Representation:
*/

#endif
