#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node** top, char data) {
    struct Node* node = newNode(data);
    node->next = *top;
    *top = node;
}

char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

bool isPalindrome(char* str) {
    int len = strlen(str);
    struct Node* stack = NULL;

    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&stack)) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}