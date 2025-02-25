// things to add
// a way to swap tasks
// a way to delete tasks
// learn how to make tui apps or fullstack with C# and .NET framework
// remake this in RUST

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

int main() {
    int run = true;
    int count = 0;
    int input = 0;
    int choice = 0;
    Node *list = (Node *)malloc(sizeof(Node));
    list->data.num = count;
    list->next = NULL;
    splash();

    while (run) {
        splashRun();
        scanf("%d", &input);
        getchar();
        switch (input) {
            case 1:
                count++;
                char task[100];
                printf("Task: ");
                scanf("%[^\n]", task);
                getchar();
                addEvent(list, count, task);
                break;
            case 2:
                printf("Enter the tasks ID: ");
                scanf("%d", &choice);
                getchar();
                completeEvent(list, choice);
                break;
            case 3:
                listEvent(list);
                break;
            case 4:
                freeList(list);
                printf("Exiting...\n");
                run = false;
                break;
            default:
                printf("ERR: Bad input\n\n");
                break;
        }
    }
    return 0;
}

Node *newNode(int x, char input[100]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data.num = x;
    newNode->data.completed = false;
    strcpy(newNode->data.task, input);
    newNode->next = NULL;
    return newNode;
}

Node *addEvent(Node *head, int x, char input[100]) {
    Node *new_node = newNode(x, input);
    if (head == NULL) {
        return new_node;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    printf("\n");
    return head;
}

void completeEvent(Node *task, int count) {
    if (task == NULL) {
        printf("ERR: Empty list!\n\n");
        return;
    }
    Node *temp = task;
    while (temp != NULL) {
        if (temp->data.num == count) {
            temp->data.completed = true;
            printf("completed task %d\n\n", temp->data.num);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("ERR: No task with that id\n\n");
    }
}

void listEvent(Node *list) {
    printf("\n");
    Node *temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
        if (temp->data.completed == true) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }
        printf("%d ", temp->data.num);
        printf("%s\n", temp->data.task);
    }
    printf("\n");
}

void freeList(Node *list) {
    Node *temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

void splash() {
    system("clear");  // do cls if you are using windows
    printf("Welcome to my Todo list app!\n\n");
}

void splashRun() {
    printf("Please select one of the following options\n");
    printf("1) Create a task\n");
    printf("2) Complete a task\n");
    printf("3) List Tasks\n");
    printf("4) Exit\n");
    printf("> ");
}