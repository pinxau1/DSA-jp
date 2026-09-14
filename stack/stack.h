#ifndef STACK
#define STACK

#define MAX 100

typedef struct {
  int id;
  char name[20];
  char sex;
  char program[10];
  int year;
} Student;

typedef struct{
  Student data[MAX];
  int top;
} Stack;

void initStack(Stack *s);
Stack newStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
bool push(Stack *s, Student stud);
bool pop(Stack *s);
Student peek(Stack s);
void visualize(Stack s);
void display(Stack s);

#endif
