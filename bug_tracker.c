#include <stdio.h>
#include <string.h>

#define MAX 100

struct Issue {
    int id;
    char title[50];
    char status[10];
};

int main() {
    struct Issue issues[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== SIMPLE BUG TRACKER =====\n");
        printf("1. Add Issue\n");
        printf("2. List Issues\n");
        printf("3. Change Issue Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter issue title: ");
            fgets(issues[count].title, sizeof(issues[count].title), stdin);
            issues[count].title[strcspn(issues[count].title, "\n")] = '\0';
            issues[count].id = count + 1;
            strcpy(issues[count].status, "OPEN");
            count++;
            printf("✅ Issue added successfully!\n");
        }
        else if (choice == 2) {
            printf("\n--- List of Issues ---\n");
            if (count == 0)
                printf("No issues found.\n");
            else {
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Title: %s | Status: %s\n",
                           issues[i].id, issues[i].title, issues[i].status);
                }
            }
        }
        else if (choice == 3) {
            int id;
            printf("Enter issue ID to close: ");
            scanf("%d", &id);
            getchar();

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (issues[i].id == id) {
                    strcpy(issues[i].status, "CLOSED");
                    printf("✅ Issue #%d closed successfully.\n", id);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("❌ Issue not found.\n");
        }
        else if (choice == 4) {
            printf("Exiting Bug Tracker... 👋\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
