#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// --- Data Structures ---
typedef struct
{
    int taskID;
    char description[100];
    int priority;
} Task;

typedef struct Node
{
    Task task;
    struct Node *next;
} TaskNode, *TaskList;

// --- Function Prototypes ---
void initializeTaskList(TaskList *list);
void displayTaskList(TaskList list, const char *name);


// todo Implement these functions
void markTaskToList(TaskList *list, Task t);            // Inserts a task into a sorted list, no duplicates
TaskList commonTasks(TaskList A, TaskList B);           // Set Intersection
TaskList kaguyaOnlyTasks(TaskList A, TaskList B);       // Set Difference (A - B)
TaskList shiroganeOnlyTasks(TaskList A, TaskList B);    // Set Difference (B - A)
TaskList allFestivalTasks(TaskList A, TaskList B);      // Set Union
bool isKaguyaSubsetOfShirogane(TaskList A, TaskList B); // Is Subset (A is subset of B)


// --- Helper Functions (Provided) ---
void initializeTaskList(TaskList *list)
{
    *list = NULL;
}

void displayTaskList(TaskList list, const char *name)
{
    printf("-- %s ---\n", name);
    if (list == NULL)
    {
        printf("  [Empty]\n");
    }
    else
    {
        for (TaskList trav = list; trav != NULL; trav = trav->next)
        {
            printf("  Task ID: %d, Description: %s, Priority: %d\n", trav->task.taskID, trav->task.description, trav->task.priority);
        }
    }
    printf("--------------------\n");
}

// --- Main Function (Test Cases) ---
int main()
{
    TaskList kaguyaTasks;
    TaskList shiroganeTasks;

    initializeTaskList(&kaguyaTasks);
    initializeTaskList(&shiroganeTasks);

    // Kaguya's Tasks
    markTaskToList(&kaguyaTasks, (Task){1, "Prepare festival budget", 3});
    markTaskToList(&kaguyaTasks, (Task){3, "Oversee cultural exhibits", 1});
    markTaskToList(&kaguyaTasks, (Task){5, "Arrange tea ceremony", 2});
    markTaskToList(&kaguyaTasks, (Task){7, "Review club proposals", 4});
    markTaskToList(&kaguyaTasks, (Task){9, "Secretly help Shirogane", 5});

    // Shirogane's Tasks
    markTaskToList(&shiroganeTasks, (Task){1, "Prepare festival budget", 3});
    markTaskToList(&shiroganeTasks, (Task){2, "Coordinate security", 1});
    markTaskToList(&shiroganeTasks, (Task){5, "Arrange tea ceremony", 2});
    markTaskToList(&shiroganeTasks, (Task){6, "Manage student volunteers", 3});
    markTaskToList(&shiroganeTasks, (Task){9, "Secretly help Kaguya", 5});
    markTaskToList(&shiroganeTasks, (Task){10, "Final speech preparation", 1});

    displayTaskList(kaguyaTasks, "Kaguya's Tasks");
    displayTaskList(shiroganeTasks, "Shirogane's Tasks");

    printf("\n--- Testing Set Operations ---\n");

    // 1. Common Tasks (Intersection)
    TaskList common = commonTasks(kaguyaTasks, shiroganeTasks);
    displayTaskList(common, "Common Tasks (Expected: 1, 5, 9)");

    // 2. Kaguya Only Tasks (Difference A - B)
    TaskList kaguyaOnly = kaguyaOnlyTasks(kaguyaTasks, shiroganeTasks);
    displayTaskList(kaguyaOnly, "Kaguya Only Tasks (Expected: 3, 7)");

    // 3. Shirogane Only Tasks (Difference B - A)
    TaskList shiroganeOnly = shiroganeOnlyTasks(shiroganeTasks, kaguyaTasks);
    displayTaskList(shiroganeOnly, "Shirogane Only Tasks (Expected: 2, 6, 10)");

    // 4. All Festival Tasks (Union)
    TaskList allTasks = allFestivalTasks(kaguyaTasks, shiroganeTasks);
    displayTaskList(allTasks, "All Tasks (Expected: 1, 2, 3, 5, 6, 7, 9, 10)");

    // 5. Subset Check
    printf("Is Kaguya subset of Shirogane? %s (Expected: NO)\n", isKaguyaSubsetOfShirogane(kaguyaTasks, shiroganeTasks) ? "YES" : "NO");

    return 0;
}


// todo Implement functions below

void markTaskToList(TaskList *list, Task t)
{
    // todo Insert task into sorted linked list by taskID. Do not insert duplicates.
  TaskList *trav = list;
  while(*trav && t.taskID > (*trav)->task.taskID){
    trav = &(*trav)->next;
  }

  if(*trav && (*trav)->task.taskID == t.taskID){
    return;
  }
  TaskList newn = malloc(sizeof(TaskNode));
  newn->task = t;
  newn->next = *trav;
  *trav = newn;
}

TaskList commonTasks(TaskList A, TaskList B)
{
    // todo Intersection of two sorted lists. Return new list with tasks present in both.
  TaskList a = A;
  TaskList b = B;
  TaskList head = NULL;
  while(a && b){
    if(a->task.taskID == b->task.taskID){
      Task bago = a->task;
      markTaskToList(&head, bago);
      a = a->next;
      b = b->next;
    } else if (a->task.taskID < b->task.taskID){
      a = a->next;
    } else {
      b = b->next;
    }
  }

  return head;
}

TaskList kaguyaOnlyTasks(TaskList A, TaskList B)
{
    // todo Difference (A - B). Return new list with tasks in A but not in B.
  TaskList a = A;
  TaskList b = B;
  TaskList head = NULL;

  while(a && b){
    if(a->task.taskID == b->task.taskID){
      a=a->next;
      b=b->next;
    } else if (a->task.taskID < b->task.taskID){
      markTaskToList(&head, a->task);
      a = a->next;
    } else {
      b = b->next;
    }

  }
  while(a){
    markTaskToList(&head, a->task);
    a = a->next;
  }
  return head;
}

TaskList shiroganeOnlyTasks(TaskList A, TaskList B)
{
    // todo Difference (B - A). Return new list with tasks in B but not in A.
  TaskList b = A;
  TaskList a = B;
  TaskList head = NULL;

  while(a && b){
    if(a->task.taskID == b->task.taskID){
      a = a->next;
      b = b->next;
    } else if (b->task.taskID < a->task.taskID){
      markTaskToList(&head, b->task);
      b = b->next;
    } else {
      a = a->next;
    }
  }
  while(b){
    markTaskToList(&head, b->task);
    b = b->next;
  }
  return head;
}

TaskList allFestivalTasks(TaskList A, TaskList B)
{
    // todo Union of two sorted lists. Return new list with all unique tasks sorted by taskID.
  TaskList a = A;
  TaskList b = B;
  TaskList head = NULL;
  while(a){
    markTaskToList(&head, a->task);
    a = a->next;
  }
  while(b){
    markTaskToList(&head, b->task);
    b = b->next;
  }
  return head;
}

bool isKaguyaSubsetOfShirogane(TaskList A, TaskList B)
{
  // todo Check if every task in A is also present in B.
  TaskList a = A;
  TaskList b = B;
  TaskList head = NULL;

  while(a && b){
    if(a->task.taskID == b->task.taskID){
      a = a->next;
      b = b->next;
    } else if(a->task.taskID > b->task.taskID) {
      b = b->next;
    } else {
      return false;
    }
  }


  return a == NULL;
}

