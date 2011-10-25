#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#include "linkstack_define.h"

struct linkstack_node {
	StackElement data;
	struct linkstack_node *next;
};

struct LinkStack {
	Int32 length;
	Int32 max_length;
	struct linkstack_node *top;
	struct linkstack_node *bottom;
};

struct linkstack_operations {
	struct LinkStack* (*create) (void);
	void (*destory) (struct LinkStack** stack);
	Int32 (*clear) (struct LinkStack** stack);
	struct linkstack_node* (*create_node) (void);

	Boolean (*is_empty) (struct LinkStack *stack);
	Boolean (*is_full) (struct LinkStack *stack);
	Int32 (*length) (struct LinkStack *stack);
	Int32 (*max_length) (struct LinkStack *stack);
	struct linkstack_node* (*top) (struct LinkStack *stack);
	struct linkstack_node* (*bottom) (struct LinkStack *stack);

	Boolean (*push) (struct LinkStack *stack, StackElement elem);
	Boolean (*push_node) (struct LinkStack *stack, struct linkstack_node *node);
	Boolean (*pop) (struct LinkStack *stack, StackElement *ret);
	struct linkstack_node* (*pop_node) (struct LinkStack *stack);
};

#endif // _LINKSTACK_H
