#include "main.h"

// Function to insert the arguments into the doubly linked lists
Status insert_args(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv1, char *argv2)
{
    // Insert both argument vectors into their respective lists
    insert_at_last(head1, tail1, argv1);		
    insert_at_last(head2, tail2, argv2);
    return success;
}

// Function to insert elements at the end of the doubly linked list
Status insert_at_last(Dlist **head, Dlist **tail, char *argv)
{
    for (int i = 0; i < strlen(argv); i++)  // Traverse each character of the argument
    {
        Dlist *new_node = malloc(sizeof(Dlist));  // Allocate memory for a new node
        if (new_node == NULL)
        {
            printf("Memory not allocated\n");  // Check if memory allocation failed
            return failure;
        }
        
        if (argv[i] != '-' && argv[i] != '+')  // Ignore '+' and '-' signs
        {
            new_node->data = argv[i] - 48;  // Convert character to integer (ASCII to decimal)
            if (new_node->data >= 0 && new_node->data <= 9)
            {
                new_node->prev = NULL;
                new_node->next = NULL;  // Initialize new node links as NULL

                if (*head == NULL)  // If list is empty, set new node as head and tail
                {
                    *head = new_node; 
                    *tail = new_node;
                }
                else
                {
                    new_node->prev = *tail;  // Link new node to the tail
                    (*tail)->next = new_node;  // Update tail’s next pointer
                    *tail = new_node;  // Update the tail pointer to the new node
                }
            }
        }
    }
    return success;
}

// Function to free all nodes in the given lists
Status free_all_nodes(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3)
{
    free_node(head1, tail1);  // Free nodes from the first list
    free_node(head2, tail2);  // Free nodes from the second list
    free_node(head3, tail3);  // Free nodes from the third list
    return success;
}

// Function to free each node in the given list
void free_node(Dlist **head, Dlist **tail)
{
    Dlist *temp = (*head);
    Dlist *backup = NULL;
    while (temp != NULL)  // Traverse through the list and free each node
    {
        backup = temp->next;  // Store next node in backup
        free(temp);  // Free the current node
        temp = backup;  // Move to the next node
    }
    *head = NULL;  // Reset head and tail to NULL
    *tail = NULL;
}

// Function to find which list represents a larger number
int find_bigger(Dlist **head1, Dlist **head2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;

    while (temp1 && temp2)  // Compare nodes of both lists
    {
        if (temp1->data > temp2->data)  // Return 1 if the first list is greater
            return 1;
        else if (temp2->data > temp1->data)  // Return 3 if the second list is greater
            return 3;

        temp1 = temp1->next;  // Move to next nodes
        temp2 = temp2->next;
    }
    return 0;  // Return 0 if both lists are equal
}

// Function to print the result stored in a doubly linked list
void print_result(Dlist **head, Dlist **tail)
{
    printf("Result is ");
    Dlist *temp = *head;
    while (temp != NULL)  // Traverse the list
    {
        if (temp->data == '-')  // Print '-' if it's a negative number
            printf("%c", '-');
        else
            printf("%d", temp->data);  // Print the data
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the length of a numeric string, ignoring signs
int find_length(char *argv)
{
    int i = 0, count = 0;
    while (argv[i] != '\0')  // Loop through the string until the null character
    {
        if (argv[i] == '-' || argv[i] == '+')  // Ignore signs
        {
            i++;
            continue;
        }
        count++;
        i++;
    }
    return count;  // Return the length of the numeric part
}

// Function to add a result node at the beginning of the list
Status add_result(Dlist **head3, Dlist **tail3, int sum)
{
    Dlist *new = malloc(sizeof(Dlist));  // Allocate memory for a new node
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return failure;
    }

    new->data = sum;  // Assign the sum to the node's data
    new->prev = NULL;
    new->next = NULL;

    if (*head3 == NULL)  // If the list is empty
    {	
        *head3 = new;  // Update head and tail with the new node
        *tail3 = new;
    }
    else
    {
        new->next = *head3;  // Link the new node before the current head
        (*head3)->prev = new;
        *head3 = new;  // Update head pointer to the new node
    }
    return success;
}


/* Function to check which of the two lists represents a larger number */
int check_node(Dlist** head1, Dlist** head2)
{
	Dlist* temp1 = *head1;
	Dlist* temp2 = *head2;

	// Traverse both lists node by node
	while (temp1)
	{
		// Compare corresponding data nodes
		if (temp1->data > temp2->data)  // If first list's data is greater than second list's data, return 0
			return 0;
		else if (temp1->data < temp2->data)  // If vice versa, return 1
			return 1;

		// Move to the next nodes
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return 0;  // If all nodes are equal, return 0
}



