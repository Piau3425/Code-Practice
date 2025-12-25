#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef OJ_MODE
#define main student_main
#endif

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Add the element x to the "end" of the list
void push_Back(int element) {
    // TO DO
}

// Add an element to the "head" of the list
void push_Front(int element) {
    // TO DO
}

// Delete "the specified element" from the list.
void remove_Node(int element) {
    // TO DO
}

// Check if x is in the list, Yes return True; No return False
bool contain(int element) {
    // TO DO
}

// Reverse the list
void invert_List() {
    // TO DO
}

// Clear the entire list
void clean() {
    // TO DO
}

// DON'T TOUCH !!!!!
// Output the result
void print_List() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// You can modify the main() below, it won't be executed.
int main() {
    // You can test your code here.
    return 0;
}

// -----------------------------------------------------
// DON'T TOUCH !!!!!
#ifdef OJ_MODE
#undef main
int main() {
    int n, x;
    char op[3];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'b') {
            scanf("%d", &x);
            push_Back(x);
        }
        else if (op[0] == 'f') {
            scanf("%d", &x);
            push_Front(x);
        }
        else if (op[0] == 'r') {
            scanf("%d", &x);
            remove_Node(x);
        }
        else if (op[0] == 'c') {
            scanf("%d", &x);
            printf("%s\n", contain(x) ? "True" : "False");
        }
        else if (op[0] == 'i') {
            invert_List();
        }
        else if (op[0] == 'C') {
            clean();
            printf("Clear the list!\n");
        }
    }

    print_List();
    return 0;
}
#endif