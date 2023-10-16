#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int TOP = -1;

void push() {
    int ele;
    if (TOP == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter the element: ");
        scanf("%d", &ele);
        stack[++TOP] = ele;
    }
}

void pop() {
    if (TOP == -1)
        printf("Stack Underflow\n");
    else {
        int item = stack[TOP--];
        printf("The popped element is %d\n", item);
    }
}

void display() {
    if (TOP == -1)
        printf("Stack Empty\n");
    else {
        printf("Elements: ");
        for (int i = TOP; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void peek() {
    if (TOP == -1)
        printf("Stack Underflow\n");
    else
        printf("Top element: %d\n", stack[TOP]);
}

int isFull() {
    if (TOP == SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (TOP == -1)
        return 1;
    else
        return 0;
}

int main() {
    int choice;
    printf("1.Push\n2.Pop\n3.Display\n4.IsFull\n5.IsEmpty\n6.Peek\n7.Exit\n");

    while (1) {
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                if (isFull())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;

            case 5:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;

            case 6:
                peek();
                break;

            case 7:
                printf("Program Terminated!!!\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}