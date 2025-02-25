#ifndef TODO_H_
#define TODO_H_

typedef struct ToDo {
    int num;
    char task[100];
    bool completed;
} ToDo;

typedef struct Node {
    ToDo data;
    struct Node *next;
} Node;

Node *newNode(int, char[]);
Node *addEvent(Node *, int, char[100]);
void completeEvent(Node *, int);
void listEvent(Node *);
void freeList(Node *);
void splash();
void splashRun();

#endif