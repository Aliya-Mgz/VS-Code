#include <stdio.h>
#include <stdlib.h>
struct node {
    int number;
    struct node *next;
    struct node *prev;
};
struct node* create_node(int number) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
int main(void){
    struct node *node10 = create_node(10);
    struct node *node20 = create_node(20);
    struct node *node30 = create_node(30);
    struct node *node40 = create_node(40);
    struct node *node50 = create_node(50);

    node10->next = node20;
    node20->prev = node10;
    node20->next = node30;
    node30->prev = node20; 
    node30->next = node40;
    node40->prev = node30;
    node40->next = node50;
    node50->prev = node40;

    struct node *node35 = create_node(35);
    struct node *head = node10;

    printf("Before insertion:\n");
    struct node *current = head;
    struct node *tail = NULL;

    while (current != NULL) {
        printf("%d ", current->number);
    if (current->next == NULL) {
            tail = current;
        }
        current = current->next;
    }
    printf("\n\n");

    node30->next = node35;
    node35->prev = node30;
    node35->next = node40;
    node40->prev = node35;

    printf("After insertion:\n");
    current = tail;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->prev;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;

}