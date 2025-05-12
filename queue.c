#include <stdio.h>
#include <stdlib.h>

int main() {
    int f = -1, r = -1, n = 5, q[5], item, ch, ans = 1, i;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            // Enqueue
            if (r == n - 1) {
                printf("Overflow! Queue is full.\n");
            } else {
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                if (f == -1) {
                    f = 0;
                }
                r++;
                q[r] = item;
                printf("Item inserted.\n");
            }
            break;

        case 2:
            // Dequeue
            if (f == -1 || f > r) {
                printf("Underflow! Queue is empty.\n");
            } else {
                printf("Deleted item: %d\n", q[f]);
                f++;
            }
            break;

        case 3:
            // Display
            if (f == -1 || f > r) {
                printf("Queue is empty.\n");
            } else {
                printf("Queue elements are:\n");
                for (i = f; i <= r; i++) {
                    printf("%d ", q[i]);
                }
                printf("\n");
            }
            break;

        case 4:
            ans = 0;
            break;

        default:
            printf("Invalid choice.\n");
        }

        if (ch != 4) {
            printf("Press 1 to continue, 0 to exit: ");
            scanf("%d", &ans);
        }

    } while (ans == 1);

    return 0;
}
