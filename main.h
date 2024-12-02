#include <stdio.h>   // Include standard I/O library for input/output operations.
#include <string.h>  // Include string library for string manipulation functions.
#include <stdlib.h>  // Include standard library for memory allocation and other utilities.


typedef enum 
{
    failure, // Represents a failure state.
    success  // Represents a success state.
} Status;

// Define a doubly linked list node structure.
typedef struct node
{
    int data;            // Holds the data value for the node.
    struct node* prev;   // Pointer to the previous node in the list.
    struct node* next;   // Pointer to the next node in the list.
} Dlist;

// Function declarations for various linked list operations and calculations.
Status insert_args(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv1, char *argv2); 
// Inserts arguments into two doubly linked lists.

Status insert_at_last(Dlist **head1, Dlist **tail1, char *data); 
// Inserts a node with the given data at the end of the first doubly linked list.

Status add_result(Dlist **head3, Dlist **tail3, int sum); 
// Adds a node with the sum result to the third doubly linked list.

Status free_all_nodes(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3); 
// Frees all nodes in the three doubly linked lists.

void free_node(Dlist **head, Dlist **tail); 
// Frees a single node from the specified doubly linked list.

int find_bigger(Dlist **head1, Dlist **head2); 
// Compares two lists to determine which one represents a larger value.

void print_result(Dlist **head, Dlist **tail); 
// Prints the elements of a doubly linked list from head to tail.

int find_length(char *argv); 
// Returns the length of the given string.

int check_node(Dlist **head1, Dlist **head2); 
// Checks the validity of nodes in two linked lists.

void insert_last(Dlist **head, Dlist **tail); 
// Inserts a node at the end of the linked list.

void insert_first(Dlist **head, Dlist **tail, int data); 
// Inserts a node with the given data at the beginning of the linked list.

void free_first(Dlist **head); 
// Frees the first node of the linked list.

// Function declarations for arithmetic operations on doubly linked lists.
Status addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3); 
// Adds two doubly linked lists.

Status subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3); 
// Subtracts the second list from the first list.

Status division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3); 
// Divides the first list by the second list.

Status multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3); 
// Multiplies two doubly linked lists.


