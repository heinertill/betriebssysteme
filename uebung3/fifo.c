struct list* append(struct list *, int);
struct list* delete(struct list *, int);
struct list* find(struct list *, int);
void push(struct list*, int data);
struct node* pop(struct list*);
void printList(struct node currNode);

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
	
int main (int argc, char *argv[]) {

	if (argc < 4) {
		printf("Bitte gib mindestens 3 Zahlen für Elemente an.\n");
		exit(1);
	}
	struct list *L = (struct list *) malloc(sizeof(struct list));
	L->tail = &L->head;
	L->head = NULL;	

	printf("Adding Elements:\n");
	for (int i = 0; i < argc-1; i++) {
		printf("Adding %d", atoi(argv[i+1]));
		push(L, atoi(argv[i+1]));
	}
	
	printf("First Iteration:\n");
	printList(*(L->head));

	printf("Popping first 2 Elements...\n");
	printf("%d\n", pop(L)->data);
	printf("%d\n", pop(L)->data);

	printf("Iteration after popping:\n");
	printList(*(L->head));

	return 0;
}

void printList(struct node currNode) {
	printf("%d\n", currNode.data);
	if (currNode.next != NULL) {
		printList(*(currNode.next));
	}
}


void push(struct list *L, int data) {
	struct node *el = (struct node *) malloc(sizeof(struct node));
	el->data = data;
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
