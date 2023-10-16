#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear, size;
    unsigned capacity;
    char* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (char*)malloc(sizeof(char) * capacity);
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, char item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

char dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return '\0';
    char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int isPalindrome(char* str) {
    struct Queue* queue = createQueue(strlen(str));
    
    for (int i = 0; str[i]; i++) {
        enqueue(queue, str[i]);
    }
    
    while (!isEmpty(queue)) {
        char frontChar = dequeue(queue);
        char rearChar = str[strlen(str) - 1];
        
        if (frontChar != rearChar) {
            free(queue->array);
            free(queue);
            return 0;
        }
        
        str[strlen(str) - 1] = '\0';
    }
    
    free(queue->array);
    free(queue);
    return 1;
}

int main() {
    char str[MAX_SIZE];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str))
        printf("Entered string is a palindrome.\n", str);
    else
        printf("Entered string is not a palindrome.\n", str);
    
    return 0;
}