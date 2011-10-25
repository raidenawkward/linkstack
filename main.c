#include <stdio.h>
#include "linkstack.h"
#include "linkstack_operation.h"

int main() {
	struct linkstack_operations *op = linkstack_get_operation();
	if (!op)
		return -1;

	struct LinkStack *stack = op->create();
	if (!stack) {
		free(op);
		return -1;
	}

	stack->max_length = 4;
	op->push(stack,1);
	op->push(stack,2);
	op->push(stack,3);
	op->push(stack,4);
	op->push(stack,5);
	op->push(stack,6);
	printf("linkstack length : %d\n",op->length(stack));
	printf("linkstack empty : %d\n",op->is_empty(stack));
	printf("linkstack full : %d\n",op->is_full(stack));

	StackElement e;
	op->pop(stack,&e);
	printf("poped : %d\n",e);
	printf("linkstack length : %d\n",op->length(stack));
	op->pop(stack,&e);
	printf("poped : %d\n",e);
	printf("linkstack length : %d\n",op->length(stack));
	op->pop(stack,&e);
	printf("poped : %d\n",e);
	printf("linkstack length : %d\n",op->length(stack));
	op->pop(stack,&e);
	printf("poped : %d\n",e);
	printf("linkstack length : %d\n",op->length(stack));
	printf("linkstack empty : %d\n",op->is_empty(stack));
	printf("linkstack full : %d\n",op->is_full(stack));

	op->destory(&stack);
	free(op);
	return 0;
}
