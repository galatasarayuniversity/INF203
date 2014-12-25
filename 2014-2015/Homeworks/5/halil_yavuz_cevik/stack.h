/*
 * stack.h
 *
 *  Created on: Nov 30, 2014
 *      Author: yc
 */

#ifndef STACK_H_
#define STACK_H_

struct stackNode {
	double data;
	struct stackNode *next;
};

/* Gosterici NULL ise 1, degilse 0 dondurur */
#define stack_is_empty(x) (x == NULL)

void stack_push(struct stackNode **top, double data);
void stack_print(struct stackNode *top);
double stack_pop(struct stackNode **top);
void stack_free(struct stackNode **top);

#endif				/* STACK_H_ */
