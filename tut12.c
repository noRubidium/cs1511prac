#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void printlist(struct node *list) {
	struct node *curr;
	for (curr = list; curr != NULL; curr = curr->next) {
		printf("[%d]->", curr->data);
	}
	printf("X");
}
// pre condition: list is a singly linked list
// return 1 if value is in the list otherwise 0
// int member(int value, struct node *list) {
// 	struct node *curr = list;
// 	while (curr != NULL) {
// 		if (curr->data == value) {
// 			return 1;
// 		}
// 		curr = curr->next;
// 	}
// 	return 0;
// }

int member(int value, struct node *list) {
	// base case
	if (list == NULL) {
		return 0;
	}
	// inductive case
	// handle ourselves
	if (list->data == value) {
		return 1;
	}
	// call the function itself
	return member(value, list->next);
}

// struct node *list_append(struct node *base, struct node *toAppend) {
// 	if (base == NULL) {
// 		return toAppend;
// 	}
// 	// find the tail of the base
// 	struct node *tail = base;
// 	while (tail->next != NULL) {
// 		tail = tail->next;
// 	}
// 	// append toAppend to the tail
// 	tail->next = toAppend;
// 	return base;
// }

struct node *list_append(struct node *base, struct node *toAppend) {
	if (base == NULL) {
		return toAppend;
	}
	// take care of our own business
	base->next = list_append(base->next, toAppend);
	return base;
}

// struct node *insert_ordered(int item, struct node *list) {
// 	// base case
// 	if (list == NULL || list->data > item) {
// 		struct node *new = malloc(sizeof(struct node));
// 		new->data = item;
// 		new->next = list;
// 		return new;
// 	}
//
// 	// inductive case
// 	list->next = insert_ordered(item, list->next);
// 	return list;
// }

struct node *insert_ordered(int item, struct node *list) {
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		printf("AHHHHHH! RUN OUT OF MEMORY!!!\n");
		exit(1);
	}
	new->data = item;
	new->next = NULL;
	if (list == NULL) {
		return new;
	}

	// find the slot
	struct node *curr = list;
	struct node *prev = NULL;
	while (curr != NULL) {
		if (curr->data > item) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	new->next = curr;
	if (prev == NULL) {
		return new;
	}
	// add value in
	prev->next = new;
	return list;
}

// struct node *merge_sorted(struct node *list1, struct node *list2) {
// 	if (list1 == NULL) {
// 		return list2;
// 	}
// 	if (list2 == NULL) {
// 		return list1;
// 	}
// 	struct node *result = NULL;
// 	if (list1->data > list2->data) {
// 		list2->next = merge_sorted(list1, list2->next);
// 		result = list2;
// 	} else {
// 		list1->next = merge_sorted(list1->next, list2);
// 		result = list1;
// 	}
// 	return result;
// }

// r>0-> node1 > node2
// r=0 -> node1 == node2
// r<0 -> node1 < node2
int node_cmp (struct node *node1, struct node *node2) {
	if (node1 == NULL) {
		return 1;
	}
	if (node2 == NULL) {
		return -1;
	}
	return node1->data - node2->data;
}

struct node *merge_sorted(struct node *list1, struct node *list2) {
	if (list1 == NULL) {
		return list2;
	}
	if (list2 == NULL) {
		return list1;
	}
	struct node *head = NULL;
	struct node *tail;
	while(list1 != NULL || list2 != NULL) {
		if (node_cmp(list1, list2) > 0) {
			if (head == NULL) {
				head = list2;
				tail = list2;
			} else {
				tail->next = list2;
				tail = list2;
			}
			list2 = list2->next;
		} else {
			if (head == NULL) {
				head = list1;
				tail = list1;
			} else {
				tail->next = list1;
				tail = list1;
			}
			list1 = list1->next;
		}
	}
	return head;
}
