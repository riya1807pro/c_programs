#include <stdio.h>

int main() {
    int ch, top = 0, s[5], n = 5, item, ans = 1, i;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: // Push
            if (top == n) {
                printf("Stack overflow! Can't add element.\n");
            } else {
                printf("Enter the item you want to insert: ");
                scanf("%d", &item);
                s[top] = item;
                top++;
                printf("Item pushed.\n");
            }
            break;

        case 2: // Pop
            if (top == 0) {
                printf("Stack underflow! Can't delete element.\n");
            } else {
                top--;
                printf("Item popped: %d\n", s[top]);
            }
            break;

        case 3: // Display
            if (top == 0) {
                printf("Stack is empty!\n");
            } else {
                printf("Stack elements (Top to Bottom):\n");
                for (i = top - 1; i >= 0; i--) {
                    printf("%d\n", s[i]);
                }
            }
            break;

        case 4:
            ans = 0;
            break;

        default:
            printf("Invalid choice!\n");
        }

        if (ch != 4) {
            printf("\nPress 1 to continue, 0 to exit: ");
            scanf("%d", &ans);
        }

    } while (ans == 1);

    return 0;
}
