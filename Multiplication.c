#include "main.h"
extern int negative_flag;  // External flag to indicate if the result should be negative

/* Function to perform multiplication of two numbers represented by doubly linked lists */
Status multiplication(Dlist* head1, Dlist* tail1, Dlist* head2, Dlist* tail2, Dlist** head3, Dlist** tail3)
{
	int result = 0, count = 0, multiply = 0, carry = 0;  // Declare necessary variables for calculation
	Dlist* temp1 = tail1;  // Pointer to traverse first number from the end
	Dlist* temp2 = tail2;  // Pointer to traverse second number from the end
	Dlist* result_head1 = NULL;  
	Dlist* result_tail1 = NULL;  
	Dlist* result_head2 = NULL;  
	Dlist* result_tail2 = NULL;  

	// Loop through each digit of the second number
	while (temp2)
	{
		carry = 0;  // Reset carry for each new digit in the second number
		temp1 = tail1;  // Reset temp1 to the last digit of the first number

		// Loop through each digit of the first number
		while (temp1)
		{
			multiply = carry;  // Start with the carry from the previous multiplication
			for (int i = 0; i < temp2->data; i++)
			{
				multiply += temp1->data;  // Add the current digit of the first number multiple times
			}
			carry = multiply / 10;  // Extract the carry for the next iteration
			multiply = multiply % 10;  // Keep the current digit as the result

			// Add the result to the appropriate result list
			if (count == 0)
			{
				add_result(&result_head1, &result_tail1, multiply);
			}
			else
			{
				add_result(&result_head2, &result_tail2, multiply);
			}

			temp1 = temp1->prev;  // Move to the previous digit in the first number
		}

		// If there's a carry left after processing all digits of the first number
		if (carry > 0 && count > 0)
		{
			add_result(&result_head2, &result_tail2, carry);
		}
		if (count == 0)
		{
			if (carry > 0)
			{
				add_result(&result_head1, &result_tail1, carry);
			}
			add_result(&result_head1, &result_tail1, 0);  // Append a zero for the next iteration
		}

		// For subsequent iterations, append zeros to align the results
		if (count >= 1)
		{
			for (int i = 1; i <= count; i++)
			{
				insert_last(&result_head2, &result_tail2);  // Insert zeros at the end
			}
			if (count % 2 == 1)
			{
				// Alternate addition of partial results
				addition(result_head1, result_tail1, result_head2, result_tail2, head3, tail3);
				free_node(&result_head2, &result_tail2);  // Free temporary nodes
				free_node(&result_head1, &result_tail1);
				add_result(head3, tail3, 0);
			}
			else
			{
				addition(*head3, *tail3, result_head2, result_tail2, &result_head1, &result_tail1);
				free_node(head3, tail3);  // Free current result list nodes
				free_node(&result_head2, &result_tail2);
				add_result(&result_head1, &result_tail1, 0);  // Append a zero for the next iteration
			}
		}
		temp2 = temp2->prev;  // Move to the previous digit in the second number
		count++;  // Increment the position counter for the next digit
	}

	// Handle the final result based on the iteration count
	if (count % 2)
	{
		free_first(&result_head1);  // Remove leading zero from the result
		if (negative_flag)
			add_result(&result_head1, &result_tail1, '-');  // Add negative sign if needed
		print_result(&result_head1, &result_tail1);  // Print the final result
	}
	else
	{
		free_first(head3);  // Remove leading zero from the result
		if (negative_flag)
			add_result(head3, tail3, '-');  // Add negative sign if needed
		print_result(head3, tail3);  // Print the final result
	}

	// Free all temporary nodes
	free_node(&result_head1, &result_tail1);
	free_node(&result_head2, &result_tail2);

	return success;  // Return success status
}

/* Function to insert a node with a value of 0 at the end of the list */
void insert_last(Dlist** head, Dlist** tail)
{
	Dlist* new_node = malloc(sizeof(Dlist));  // Allocate memory for a new node
	if (new_node == NULL)
	{
		printf("Memory allocation failed\n");  // Handle memory allocation failure
	}
	else
	{
		new_node->data = 0;  // Initialize the new node with data '0'
		new_node->prev = *tail;  // Set the previous pointer to the current tail
		(*tail)->next = new_node;  // Link the current tail to the new node
		new_node->next = NULL;  // Set the next pointer of the new node to NULL
		*tail = new_node;  // Update the tail to the new node
	}
}

/* Function to free the first node of the list */
void free_first(Dlist** head)
{
	Dlist* temp = *head;  // Store the current head in a temporary pointer
	*head = (*head)->next;  // Move the head pointer to the next node
	if (*head != NULL)
	{
		(*head)->prev = NULL;  // Set the previous pointer of the new head to NULL
	}
	free(temp);  // Free the memory of the old head
}
