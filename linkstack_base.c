#include "linkstack_base.h"

struct LinkStack* linkstack_create () {
	struct LinkStack *stack = (struct LinkStack*)malloc(sizeof(struct LinkStack));
	if (!stack)
		return NULL;

	stack->length = 0;
	stack->max_length = 0;
	stack->top = NULL;
	stack->bottom = stack->top;

	return stack;
}

void linkstack_destory (struct LinkStack** stack) {
	if (!stack || !!*stack)
		return;

	if (!(*stack)->top || !(*stack)->bottom)
		return;

	struct linkstack_node *p = (*stack)->top;
	while(p) {
		struct linkstack_node *node = p;
		p = p->next;
		free(node);
	}
	free(*stack);
}

Int32 linkstack_clear (struct LinkStack** stack) {
	if (!stack || !!*stack)
		return;

	if (!(*stack)->top || !(*stack)->bottom)
		return;
	Int32 ret = 0;
	struct linkstack_node *p = (*stack)->top;
	while(p) {
		struct linkstack_node *node = p;
		p = p->next;
		free(node);
		++ret;
	}

	(*stack)->length = 0;
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;

	return ret;
}

struct linkstack_node* linkstack_create_node () {
	struct linkstack_node *node = (struct linkstack_node*)malloc(sizeof(struct linkstack_node));
	if (!node)
		return NULL;

	node->next = NULL;

	return node;
}


Boolean linkstack_is_empty (struct LinkStack *stack) {
	Boolean ret = true;
	if (!stack)
		return ret;

	if (stack->top != stack->bottom || stack->length)
		ret = false;

	return ret;
}

Boolean linkstack_is_full (struct LinkStack *stack) {
	Boolean ret = false;
	if (!stack)
		return ret;

	if (stack->length >= stack->max_length)
		ret = true;

	return ret;
}

Int32 linkstack_length (struct LinkStack *stack) {
	if (!stack)
		return 0;
	return stack->length;
}

Int32 linkstack_max_length (struct LinkStack *stack) {
	if (!stack)
		return 0;
	return stack->max_length;
}

struct linkstack_node* linkstack_top (struct LinkStack *stack) {
	if (!stack)
		return NULL;
	return stack->top;
}

struct linkstack_node* linkstack_bottom (struct LinkStack *stack) {
	if (!stack)
		return NULL;
	return stack->bottom;
}


Boolean linkstack_push (struct LinkStack *stack, StackElement elem) {

}

Boolean linkstack_push_node (struct LinkStack *stack, struct linkstack_node *node) {

}

StackElement linkstack_pop (struct LinkStack *stack) {

}

struct linkstack_node* linkstack_pop_node (struct LinkStack *stack) {

}


