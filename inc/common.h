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
};

struct	s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
};

struct s_stack			*initStack(void);
void					pushStack(struct s_stack *s, int val);
struct s_node			*popStack(struct s_stack *s);
struct s_node			*peekStack(struct s_stack *s);
int						isEmptyStack(struct s_stack *s);

/*
**	Library Functions:
*/

long					xatoi(char *s);
int						xstrlen(char *s);
void					xprint(char *s);

#endif
