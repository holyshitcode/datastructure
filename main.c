#include <stdio.h>
#include "assert_utils.h"

typedef struct node {
    int key;
    struct node *next;
}node;

node *initNode(int key) {
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

node *findPosition(node **head, int key) {
    node *temp = *head;
    node *prev = NULL;
    while (temp != NULL && temp->key < key) {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

node *findNode(node **head, int key) {
    node *temp = *head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertNode(node **head, int key) {
    if(*head == NULL || (*head)->key >= key) {
        node *temp = initNode(key);
        temp->next = *head;
        *head = temp;
    }else {
        node *target = initNode(key);
        node *before = findPosition(head, key);
        target->next = before->next;
        before->next = target;
    }
}

void deleteNode(node **head, int key) {
    node *target =findNode(head, key);
    if(target == NULL){
        return;
    }
    if (*head == target) {
        *head = target->next;
        free(target);
    }else {
        node *before = findPosition(head, key);
        before->next = target->next;
        free(target);
    }
}

void pouring(node **head) {
    node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void unitTest() {
    //given
    node *head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    //when
    deleteNode(&head, 10);
    //then
    assertEqualInt(head->key,10,IsNot);
    assertEqualInt(head->key,20,null);
}

int main(void) {
    unitTest();
    node *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    pouring(&head);
    deleteNode(&head, 1);
    deleteNode(&head, 2);
    deleteNode(&head, 3);
    deleteNode(&head, 4);
    pouring(&head);

    return 0;
}
