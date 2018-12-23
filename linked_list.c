#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *prevNode ;
    struct Node *nextNode;
} node;

typedef struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
} linked_list;

linked_list LinkedList_new() {
    linked_list newList;
    newList.head = NULL;
    newList.tail = NULL;
    newList.size = 0;

    return newList;
}

node* LinkedList_get(linked_list *list, int position) {
    if(position > list->size - 1) {
        return NULL;
    } else if(position == 0) {
        return list->head;
    } else if(position == list->size - 1) {
        return list->tail;
    } else {
        node *n;

        // if node is located in the first half
        if( position < ((list->size-1) / 2)) {
            n = list->head;
            for(int i = 1; i <= position; i++) {
                n = n->nextNode;
            }
        } else {
            n = list->tail;
            for(int i = list->size-1; i >= position; i--) {
                n = n->prevNode;
            }
        }
        return n;
    }
}

void LinkedList_insert(linked_list *list, int element, int position) {
    node newNode;
    newNode.value = element;

    if(list->size == 0) {     
        newNode.prevNode = NULL;
        newNode.nextNode = NULL;

        list->head = &newNode;
        list->tail = &newNode;
        list->size += 1;
    } else {
        node *nodeAtPos = LinkedList_get(list, position);
        if(nodeAtPos != NULL) {
            // todo
            list->size += 1;
        }
        
    }
}

void LinkedList_append(linked_list *list, int element) {
    node newNode;
    newNode.value = element;

    newNode.prevNode = list->tail;
    newNode.nextNode = NULL;

    if(list->size == 0) list->head = &newNode;
    list->tail = &newNode;

    list->size += 1;
}

void LinkedList_preppend(linked_list *list, int element) {
    node newNode;
    newNode.value = element;

    newNode.prevNode = NULL;
    newNode.nextNode = list->head;

    if(list->size == 0) list->tail = &newNode;
    list->head = &newNode;
    list->size += 1;
}

void LinkedList_print(linked_list *list) {
    if(list->size == 0) {
        printf("[]\n");
    } else {
        node *n = list->head;
        printf("[");
        while(1) {
            
            if(n == list->tail) {
                printf("%d]\n", n->value);
                break;
            } else {
                printf("%d, ", n->value);
                n = n->nextNode;
            }
            
        }
    }
    
}


void main() {
    linked_list list = LinkedList_new();
    LinkedList_print(&list);

    LinkedList_append(&list, 2);
    LinkedList_print(&list);
    printf("\nsize = %d, head = %d, tail = %d", list.size, list.head->value, list.tail->value);   
    
    LinkedList_append(&list, 3);
    LinkedList_print(&list);

    printf("\nsize = %d, head = %d, tail = %d", list.size, list.head->value, list.tail->value);
    
}