#include "stack.h"
#include <stdbool.h>
#include <stdio.h>


void initStack(Stack *s){
  s->top = -1;
}

Stack newStack(){
  Stack s;
  s.top = -1;
  return s;
}

bool isEmpty(Stack s){
  return s.top == -1;
}

bool isFull(Stack s){
  return s.top == MAX-1;
}

bool push(Stack *s, Student stud){
  if(!isFull(*s)){
    s->data[++s->top] = stud;
    return true;
  } else 
  return false;
}

bool pop(Stack *s){
  if(!isEmpty(*s)){
    s->top--;
    return true;
  } return false;
}

Student peek(Stack s){
  if(!isEmpty(s)){
    return s.data[s.top];
  } else {
    Student empty = {0};
    return empty;
  }
}

void visualize(Stack s){
  if(isEmpty(s)) 
    return;
  puts("\nVISUALIZE");
  for(int i = s.top; i >= 0; --i){
    printf("| %-8s %10d|\n", "id:", s.data[i].id);
    printf("| %-8s %10s|\n", "name:", s.data[i].name);
    printf("| %-8s %10c|\n", "sex:", s.data[i].sex);
    printf("| %-8s %10s|\n", "program:", s.data[i].program);
    printf("| %-8s %10d|\n", "year:", s.data[i].year);
    puts("\t------");
  }
}

void display(Stack s){
  if(isEmpty(s))
    return;
  printf("id: %d\n", s.data[s.top].id);
  printf("name: %s\n", s.data[s.top].name);
  printf("sex: %c\n", s.data[s.top].sex);
  printf("program: %s\n", s.data[s.top].program);
  printf("year: %d\n", s.data[s.top].year);
}

