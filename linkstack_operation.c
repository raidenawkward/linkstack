#include "linkstack_operation.h"

struct linkstack_operations* linkstack_get_operation() {
	struct linkstack_operations *op = (struct linkstack_operations*)malloc(sizeof(struct linkstack_operations));
	if (!op)
		return NULL;


	return op;
}
