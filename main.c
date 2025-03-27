#include <stdio.h>
#include "assert_utils.h"

typedef struct node {
    int key;
    struct node *next;
}node;

/**
 * 노드를 만들어서 반환함
 */
node *initNode(int key) {
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

/**
 * 새로운 노드가 들어가야할 노드의 직전의 노드를 반환해줌
 * while의 반복문조건을 동시에만족할시에 반환함
 */
node *findPosition(node **head, int key) {
    node *temp = *head;
    node *prev = NULL;
    while (temp != NULL && temp->key < key) {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

/**
 * 원하는 키값의 노드를 찾고 반환시켜줌
 */
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

/**
 * 노드를 연결리스트에 넣음
 * 리스트가 비었거나 헤드값이 키값보다작다면 현재의 키값을 다음노드값으로 넣어주고
 * 현재값을 헤드에넣어줌
 * 그외에는 findPosition()이용하여 위치를 찾고
 * 직전 노드의 next를 현재의 next에 이어준후
 * 직전 노드의 next를 현재노드에 설정해줌
 */
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

/**
 * 지워야할 키값의 직전노드를 findPosition으로 반환받고
 * 타겟노드의 next값을 직전노드 next값에 넣어준후 메모리해제함
 */
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

/**
 *  next에 현재노드의 next 세팅 1->2
 *  현재노드의 next를 이전에있던 노드로 바꿈 최초엔 NULL
 *  previous를 현재로 세팅해줌
 *  현재노드를 다음노드로 이동시켜서 반복
 */
void reverse(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * head 부터 순차조회하여 출력함
 */
void pouring(node **head) {
    node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * 노드값을 넣고 삭제하여 검증
 */
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

/**
 * findNode 함수로 잘찾아지는지 검증
 */
void unitTest2() {
    //given
    node *head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    //when
    node *result = findNode(&head, 10);
    //then
    assertEqualInt(result->key,10,null);
}

int main(void) {
    unitTest();
    unitTest2();
    node *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    reverse(&head);
    pouring(&head);

    return 0;
}
