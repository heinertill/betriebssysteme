struct list* append(struct list *, int);
struct list* delete(struct list *, int);
struct list* find(struct list *, int);
void push(struct list*, int data);
struct node* pop(struct list*);


#include <stdlib.h>
#include <stdio.h>

struct list {
	struct node *head;
	struct node **tail;
};

struct node {
	int data;
	struct node *next;
};
	
int main (void) {
	struct list *L = (struct list *) malloc(sizeof(struct list));
	L->tail = &L->head;
	L->head = NULL;	

	return 0;
}

void push(struct list *L, int data) {
	struct node *el = (struct node *) malloc(sizeof(struct node));
	el->data = 5;
	el->next = NULL;

	if(L->head == NULL) {
		L->head = el;
	}
	
	*L->tail = el;
	L->tail = &el->next;
}

struct node* pop(struct list *L) {
	struct node* temp = L->head;
	L->head = (*L).head->next;
	
	return temp;
}
