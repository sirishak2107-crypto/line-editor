#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 500

char *lines[MAX_LINES];
int lineCount = 0;

void displayLines() {
    if (lineCount == 0) {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void insertLine(int position) {
    if (lineCount >= MAX_LINES) {
        printf("Document is full.\n");
        return;
    }

    if (position < 1 || position > lineCount + 1) {
        printf("Invalid line number.\n");
        return;
    }

    char text[MAX_LENGTH];

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    for (int i = lineCount; i >= position; i--) {
        lines[i] = lines[i - 1];
    }

    lines[position - 1] = malloc(strlen(text) + 1);

    if (lines[position - 1] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(lines[position - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine(int position) {
    if (lineCount == 0) {
        printf("Document is empty.\n");
        return;
    }

    if (position < 1 || position > lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    free(lines[position - 1]);

    for (int i = position - 1; i < lineCount - 1; i++) {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

void showHelp() {
    printf("\n===== HELP =====\n");
    printf("insert <number>  - Insert a new line\n");
    printf("delete <number>  - Delete a line\n");
    printf("display          - Display the document\n");
    printf("help             - Show commands\n");
    printf("exit             - Exit the editor\n");
    printf("================\n");
}

void freeDocument() {
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }
}

int main() {
    char command[100];
    int position;

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");

    printf("Type 'help' to see available commands.\n");

    while (1) {
        printf("\n> ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "display") == 0) {
            displayLines();
        }

        else if (strcmp(command, "help") == 0) {
            showHelp();
        }

        else if (strcmp(command, "exit") == 0) {
            freeDocument();
            printf("Goodbye!\n");
            break;
        }

        else if (sscanf(command, "insert %d", &position) == 1) {
            insertLine(position);
        }

        else if (sscanf(command, "delete %d", &position) == 1) {
            deleteLine(position);
        }

        else {
            printf("Unknown command. Type 'help'.\n");
        }
    }

    return 0;
}