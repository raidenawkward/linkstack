#ifndef _LINKSTACK_BASE_H
#define _LINKSTACK_BASE_H

#include <stdlib.h>
#include "linkstack.h"

/// create new linkstack, NULL returns if failed
struct LinkStack* linkstack_create ();
/// destory existed stack
void linkstack_destory (struct LinkStack** stack);
/// clear existed stack and returns node nums be cleared
Int32 linkstack_clear (struct LinkStack** stack);
/// create new link stack node, NULL returns if failed
struct linkstack_node* linkstack_create_node ();

/// if stack is empty
Boolean linkstack_is_empty (struct LinkStack *stack);
/// if count if nodes in stack reaches max_length
Boolean linkstack_is_full (struct LinkStack *stack);
/// length of stack
Int32 linkstack_length (struct LinkStack *stack);
/// max lengt of stack
Int32 linkstack_max_length (struct LinkStack *stack);
/// get top ptr of stack
struct linkstack_node* linkstack_top (struct LinkStack *stack);
/// get bottom ptr of stack
struct linkstack_node* linkstack_bottom (struct LinkStack *stack);

/// push elem
Boolean linkstack_push (struct LinkStack *stack, StackElement elem);
/// push node
Boolean linkstack_push_node (struct LinkStack *stack, struct linkstack_node *node);
/// pop elem
Boolean linkstack_pop (struct LinkStack *stack, StackElement *ret);
/// pop node
struct linkstack_node* linkstack_pop_node (struct LinkStack *stack);

#endif // _LINKSTACK_BASE_H
