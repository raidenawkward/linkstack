#include "linkstack_operation.h"
#include "linkstack_base.h"

struct linkstack_operations* linkstack_get_operation() {
	struct linkstack_operations *op = (struct linkstack_operations*)malloc(sizeof(struct linkstack_operations));
	if (!op)
		return NULL;

	op->create = linkstack_create;
	op->destory = linkstack_destory;
	op->clear = linkstack_clear;
	op->create_node = linkstack_create_node;
	op->is_empty = linkstack_is_empty;
	op->is_full = linkstack_is_full;
	op->length = linkstack_length;
	op->max_length = linkstack_max_length;
	op->top = linkstack_top;
	op->bottom = linkstack_bottom;
	op->push = linkstack_push;
	op->push_node = linkstack_push_node;
	op->pop = linkstack_pop;
	op->pop_node = linkstack_pop_node;

	return op;
}
