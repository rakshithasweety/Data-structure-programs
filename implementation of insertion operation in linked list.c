#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end
void insert(struct Node **head, int value)
{
    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        // Move to last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Link new node
        temp->next = newNode;
    }
}

// Function to print linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;

    // Insert elements
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // Print linked list
    display(head);

    return 0;
}
