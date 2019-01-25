#include "push_swap.h"
#include "common.h"

void					add_op(struct s_instlist *l, char type)
{
	struct s_inst		*tmp;

	IF_NULL((tmp = init_inst(type)), NULL);
	if (l->head == NULL)
	{
		l->head = tmp;
		l->tail = tmp;
	}
	else
	{
		link_inst(l->tail, tmp);
	}
	l->n += 1;
}

struct s_instlist		*init_instlist(void)
{
	struct s_instlist	*tmp;

	IF_NULL((tmp = malloc(sizeof(*tmp))), NULL);
	tmp->n = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

struct s_inst			*init_inst(char type)
{
	struct s_inst		*tmp;

	IF_NULL((tmp = malloc(sizeof(*tmp))), NULL);
	tmp->type = type;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/*	Returns the pointer to the newly linked inst. */

struct s_inst			*link_inst(struct s_inst *p, struct s_inst *n)
{
	if (p != NULL && n != NULL)
	{
		if (p->next != NULL)
		{
			p->next->prev = n;
			n->next = p->next;
		}
		p->next = n;
		n->prev = p;
	}
	return (n);
}

struct s_inst			*delink_inst(struct s_inst *n)
{
	if (n->prev != NULL)
		n->prev->next = n->next;
	if (n->next != NULL)
		n->next->prev = n->prev;
	return (n);
}
