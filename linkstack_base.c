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
	if (!stack || !*stack)
		return;

	if (!(*stack)->top || !(*stack)->bottom)
		goto done;

	struct linkstack_node *p = (*stack)->top;
	while(p) {
		struct linkstack_node *node = p;
		p = p->next;
		free(node);
	}
done:
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

	if (stack->top != stack->bottom || stack->length > 0)
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
	if (!stack)
		return false;
	struct linkstack_node *node = linkstack_create_node();
	if (!node)
		return false;
	node->data = elem;

	Boolean ret = linkstack_push_node(stack,node);
	if (!ret)
		free(node);

	return ret;
}

Boolean linkstack_push_node (struct LinkStack *stack, struct linkstack_node *node) {
	if (!node || !stack)
		return false;
	if (stack->length >= stack->max_length)
		return false;

	if (!stack->bottom)
		stack->bottom = node;
	else
		node->next = stack->top;
	stack->top = node;
	++stack->length;

	return true;
}

Boolean linkstack_pop (struct LinkStack *stack, StackElement *ret) {
	if (!stack)
		return false;
	struct linkstack_node* top = linkstack_pop_node(stack);
	if (!top)
		return false;
	else {
		*ret = top->data;
		free(top);
	}
	return true;
}

struct linkstack_node* linkstack_pop_node (struct LinkStack *stack) {
	if (!stack)
		return NULL;
	if (stack->length <= 0 || !stack->top || !stack->bottom)
		return NULL;

	struct linkstack_node* ret = stack->top;
	stack->top = stack->top->next;
	--stack->length;
	if (stack->length <= 0) {
		stack->length = 0;
		stack->top = NULL;
		stack->bottom = NULL;
	}

	return ret;
}
