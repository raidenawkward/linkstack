#include "linkstack_base.h"

struct LinkStack* linkstack_create () {

}

void linkstack_destory (struct LinkStack** stack) {

}

Int32 linkstack_clear (struct LinkStack** stack) {

}

struct linkstack_node* linkstack_create_node () {

}


Boolean linkstack_is_empty (struct LinkStack *stack) {

}

Boolean linkstack_is_full (struct LinkStack *stack) {

}

Int32 linkstack_length (struct LinkStack *stack) {

}

Int32 linkstack_max_length (struct LinkStack *stack) {

}

struct linkstack_node* linkstack_top (struct LinkStack *stack) {

}

struct linkstack_node* linkstack_bottom (struct LinkStack *stack) {

}


Boolean linkstack_push (struct LinkStack *stack, StackElement elem) {

}

Boolean linkstack_push_node (struct LinkStack *stack, struct linkstack_node *node) {

}

StackElement linkstack_pop (struct LinkStack *stack) {

}

struct linkstack_node* linkstack_pop_node (struct LinkStack *stack) {

}


