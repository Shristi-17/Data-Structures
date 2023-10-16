#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
    if (front == NULL)
        rear = NULL;
}

void display() {
    struct Node* temp = front;
    if (front == NULL)
        printf("Queue underflow\n");
    else {
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("Queue elements: ");
    display();

    dequeue();
    printf("after dequeue: ");
    display();

    return 0;
}
