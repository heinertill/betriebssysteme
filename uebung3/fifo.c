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
void push(struct list*, int);
struct node* pop(struct list*);

int main() {

	// Test append()
        printf("Test append():\n");
        struct list *l = (struct list *) malloc(sizeof(struct list));
        l->head = NULL;
        l->tail = &l->head;
        l = append(l, 10);
        l = append(l, 20);
        l = append(l, 30);
        struct node *p = l->head;
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n\n");

        // Test delete()
        printf("Test delete():\n");
        l = delete(l, 20);
        p = l->head;
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n\n");

        // Test find()
        printf("Test find():\n");
        struct list *found = find(l, 30);
        if (found != NULL) {
            printf("Element gefunden: %d\n", found->head->data);
        } else {
            printf("Element nicht gefunden.\n");
        }
        found = find(l, 20);
        if (found != NULL) {
            printf("Element gefunden: %d\n", found->head->data);
        } else {
            printf("Element nicht gefunden.\n");
        }	

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
