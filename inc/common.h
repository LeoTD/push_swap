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
#define DO_OP(x,y) ({x; add_op(d->ops, y);})

enum				e_inst
{
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

struct				s_vars
{
	int		l;
	int		reps;
	int		rem;
	int		elems;
	int		inv;
	int		a;
	int		b;
};

struct				s_inst
{
	char			type;
	struct s_inst	*next;
	struct s_inst	*prev;
};

struct				s_instlist
{
	int				n;
	struct s_inst	*head;
	struct s_inst	*tail;
};

struct				s_stack
{
	int					*arr;
	int					top;
	int					n;
};

struct				s_data
{
	struct s_instlist	*ops;
	struct s_stack		*a;
	struct s_stack		*b;
};

struct s_data		*init_data(int len, char **input);
int					sort_data(struct s_data *d);
void				final_pass(struct s_data *d);
void				print_stacks(struct s_stack *a, struct s_stack *b);

/*
**	Instructions:
*/

void				arr_swap(struct s_stack *s);
void				arr_push(struct s_stack *to, struct s_stack *from);
void				arr_rot(struct s_stack *s);
void				arr_rrot(struct s_stack *s);
void				dispatcher(char *op, struct s_stack *a, struct s_stack *b);

struct s_inst		*init_inst(char type);
struct s_instlist	*init_instlist(void);
void				add_op(struct s_instlist *l, char type);
struct s_inst		*link_inst(struct s_inst *p, struct s_inst *n);
struct s_inst		*delink_inst(struct s_inst *n);

/*
**	Library Functions:
*/

long				xatoi(char *s);
int					xstrlen(char *s);
void				xputs(char *s);
void				quick_sort(int *p, int len);

/*
**	Array Representation:
*/

#endif
