#ifndef COMMON_H
# define COMMON_H

# ifdef PRINT_MODE
# include <stdio.h>
#  define XPRINTF(...) printf(__VA_ARGS__)
# else
#  define XPRINTF(...) do{}while(0)
# endif

# include <unistd.h>
# include <stdlib.h>

struct	s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
};

struct	s_stack
{
	int				n;
	struct s_node	*top;
	struct s_node	*bot;
};

struct s_stack			*initStack(void);
void					pushStack(struct s_stack *s, struct s_node *n);
struct s_node			*popStack(struct s_stack *s);
int						isEmptyStack(struct s_stack *s);

struct s_node			*newNode(int val);

void					printStacks(struct s_stack *a, struct s_stack *b);
/*
**	Instructions:
*/

void					inst_swap(struct s_stack *s);
void					inst_push(struct s_stack *to, struct s_stack *from);
void					inst_rot(struct s_stack *s);
void					inst_rrot(struct s_stack *s);
void					dispatcher(char *op, struct s_stack *a, struct s_stack *b);

/*
**	Library Functions:
*/

long					xatoi(char *s);
int						xstrlen(char *s);
void					xputs(char *s);

#endif
