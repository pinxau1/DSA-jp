#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

/* =========================================================================
 * 1. DATA STRUCTURE DEFINITION
 * ========================================================================= */

// Defines a single node in the linked list
typedef struct Node {
    int data;           // The value stored in the node
    struct Node* next;  // Pointer to the next node in the sequence
} Node;

/* =========================================================================
 * 2. C.R.U.D. FUNCTION PROTOTYPES
 * ========================================================================= */

// -------------------------------------------------------------------------
// CREATE (Insertion)
// -------------------------------------------------------------------------

// Allocates memory for a new node and initializes it
Node* createNode(int data);

// Inserts a new node at the very beginning of the list
void insertAtHead(Node** head, int data);

// Inserts a new node at the very end of the list
void insertAtTail(Node** head, int data);

// Inserts a new node at a specific zero-based index (returns false if out of bounds)
bool insertAtIndex(Node** head, int data, size_t index);


// -------------------------------------------------------------------------
// READ (Retrieval & Traversal)
// -------------------------------------------------------------------------

// Prints the entire list to standard output (e.g., "1 -> 2 -> 3 -> NULL")
void displayList(const Node* head);

// Searches for a value and returns a pointer to the first matching node
Node* searchNode(const Node* head, int target);

// Returns the total number of nodes currently in the list
size_t getListLength(const Node* head);


// -------------------------------------------------------------------------
// UPDATE (Modification)
// -------------------------------------------------------------------------

// Finds the first occurrence of oldData and replaces it with newData
bool updateNodeByValue(Node* head, int oldData, int newData);

// Updates the data of a node at a specific zero-based index
bool updateNodeByIndex(Node* head, size_t index, int newData);


// -------------------------------------------------------------------------
// DELETE (Removal & Cleanup)
// -------------------------------------------------------------------------

// Removes and frees the first node in the list
void deleteAtHead(Node** head);

// Removes and frees the last node in the list
void deleteAtTail(Node** head);

// Removes and frees the first node containing the target value
bool deleteByValue(Node** head, int target);

// Removes a node at a specific zero-based index
bool deleteByIndex(Node** head, size_t index);

// Frees all memory allocated for the linked list and sets head to NULL
void freeList(Node** head);

#endif // LINKEDLIST_H
