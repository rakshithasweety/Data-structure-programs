#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create Circular Linked List
void create(int n) {

    struct Node *newNode, *temp;
    int data, i;

    for(i = 1; i <= n; i++) {

        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;
}

// Display
void display() {

    struct Node* temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Circular Linked List:\n");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("HEAD\n");
}

// Insert at beginning
void insertBeginning(int value) {

    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Delete from beginning
void deleteBeginning() {

    struct Node *temp, *last;

    temp = head;
    last = head;

    while(last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}

int main() {

    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    display();

    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    insertBeginning(value);

    display();

    deleteBeginning();

    printf("\nAfter deletion:\n");

    display();

    return 0;
}
