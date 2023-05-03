#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct list {
	struct node *head;
	struct node **tail;
};

struct list* append(struct list *, int);
struct list* delete(struct list *, int);
struct list* find(struct list *, int);

int main() {
		


	return 0;
}

struct list* append(struct list* currList, int data) {
	struct node *el = (struct node *) malloc(sizeof(struct node));
	el->data = data;
	el->next = NULL;
	*(currList->tail) = el;
	currList->tail = &el->next;
	return currList;
}

struct list* delete(struct list* currList, int target) {
	struct node **p = &currList->head;

	// suche nach dem knoten, der das ziel enthält
	while (*p != NULL && (*p)->data != target) {
		p = &(*p)->next;
	}

	// lösche das ziel, wenn es gefunden wurde
	if (*p != NULL) {
		struct node *tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}

	// falls das erste element entfernt wurde, aktualisiere den listenkopf
	if (currList->head == NULL) {
		currList->tail = &currList->head;
	}

	return currList;
}

struct list* find(struct list* currList, int target) {
	struct node *p = currList->head;

	// suche nach knoten, der ziel enthält
	while (p != NULL && p->data != target) {
		p = p->next;
	}

	// rueckgabe des knotens bzw NULL wenn nicht gefunden
	if (p != NULL) {
		return currList;
	} else {
		return NULL;
	}
}
