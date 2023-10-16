#include <stdio.h>

#define max 100

int q[max];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == max - 1) {
        printf("Queue overflow\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    q[rear] = x;
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue underflow\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1)
        printf("Queue underflow\n");
    else {
        for (i = front; i <= rear; i++)
            printf("%d\t", q[i]);
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
    printf("Queue elements after dequeue: ");
    display();

    return 0;
}
