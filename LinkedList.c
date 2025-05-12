#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int main() {
    int item, ch, ans = 1, c, pos;
    struct node *temp, *ptr, *start = NULL, *prev;

    do {
        printf("\n1. Traverse\n2. Insert at Start\n3. Insert at End\n4. Insert at Position\n");
        printf("5. Delete from Start\n6. Delete from End\n7. Delete from Position\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch >= 2 && ch <= 4) {
            printf("Enter value for new node: ");
            scanf("%d", &item);
            temp = (struct node*)malloc(sizeof(struct node));
            temp->info = item;
            temp->link = NULL;
        }

        switch (ch) {
            case 1:
                ptr = start;
                if (ptr == NULL) {
                    printf("The linked list is empty.\n");
                } else {
                    printf("Linked list: ");
                    while (ptr != NULL) {
                        printf("%d -> ", ptr->info);
                        ptr = ptr->link;
                    }
                    printf("NULL\n");
                }
                break;

            case 2:
                temp->link = start;
                start = temp;
                break;

            case 3:
                if (start != NULL) {
                    ptr = start;
                    while (ptr->link != NULL) {
                        ptr = ptr->link;
                    }
                    ptr->link = temp;
                } else {
                    start = temp;
                }
                break;

            case 4:
                if (start != NULL) {
                    printf("Enter position to insert at: ");
                    scanf("%d", &pos);
                    if (pos == 1) {
                        temp->link = start;
                        start = temp;
                    } else {
                        ptr = start;
                        c = 1;
                        while (c < pos - 1 && ptr != NULL) {
                            ptr = ptr->link;
                            c++;
                        }
                        if (ptr == NULL) {
                            printf("Invalid position\n");
                        } else {
                            temp->link = ptr->link;
                            ptr->link = temp;
                        }
                    }
                } else {
                    start = temp;
                }
                break;

            case 5:
                if (start != NULL) {
                    temp = start;
                    start = start->link;
                    free(temp);
                } else {
                    printf("The linked list is empty.\n");
                }
                break;

            case 6:
                if (start == NULL) {
                    printf("Underflow: List is empty\n");
                } else if (start->link == NULL) {
                    free(start);
                    start = NULL;
                } else {
                    ptr = start;
                    while (ptr->link->link != NULL) {
                        ptr = ptr->link;
                    }
                    temp = ptr->link;
                    ptr->link = NULL;
                    free(temp);
                }
                break;

            case 7:
                if (start == NULL) {
                    printf("Underflow: List is empty\n");
                } else {
                    printf("Enter position to delete: ");
                    scanf("%d", &pos);
                    if (pos == 1) {
                        temp = start;
                        start = start->link;
                        free(temp);
                    } else {
                        prev = NULL;
                        ptr = start;
                        c = 1;
                        while (c < pos && ptr != NULL) {
                            prev = ptr;
                            ptr = ptr->link;
                            c++;
                        }
                        if (ptr == NULL) {
                            printf("Invalid position\n");
                        } else {
                            prev->link = ptr->link;
                            free(ptr);
                        }
                    }
                }
                break;

            case 8:
                ans = 0;
                break;

            default:
                printf("Invalid choice!\n");
        }

        if (ch != 8) {
            printf("Press 1 to continue, 0 to exit: ");
            scanf("%d", &ans);
        }

    } while (ans == 1);

    return 0;
}
