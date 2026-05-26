#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at Front
void insertFront(int value) {

    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;

    printf("%d inserted at front\n", value);
}

// Insert at Rear
void insertRear(int value) {

    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;

    printf("%d inserted at rear\n", value);
}

// Delete from Front
void deleteFront() {

    if(front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d deleted from front\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from Rear
void deleteRear() {

    if(front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d deleted from rear\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Display
void display() {

    int i;

    if(front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements:\n");

    i = front;

    while(i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }

    printf("%d", deque[rear]);
}

int main() {

    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    printf("\nAfter deletion:\n");

    display();

    return 0;
}
