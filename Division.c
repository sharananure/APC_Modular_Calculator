#include "main.h"
extern int negative_flag;  // External flag indicating if the result should be negative

/* Function to perform division of two numbers represented by doubly linked lists */
Status division(Dlist* head1, Dlist* tail1, Dlist* head2, Dlist* tail2, Dlist** head3, Dlist** tail3)
{
	int stop_flag = 0;       // Flag to stop the division process when the remainder is smaller than the divisor
	int count = 0, flag, result = 0;  // Declare and initialize variables
	Dlist* temp;

	// Loop until the division process is complete
	while (stop_flag != 1)
	{							 
		// Perform subtraction based on whether the result is even or odd
		if (result % 2 == 0)  // If result value is even
		{
			count++;  // Increment quotient count
			subtraction(head1, tail1, head2, tail2, head3, tail3);  // Perform subtraction operation
			temp = *head3;  // Store the result in a temporary pointer
		}
		else
		{
			count++;
			subtraction(*head3, *tail3, head2, tail2, &head1, &tail1);  // Perform subtraction and swap the lists
			temp = head1;
		}

		// Check if the current remainder is smaller than the divisor
		stop_flag = check_node(&temp, &head2);  
		if (stop_flag == 1)  // If true, stop the process
		{
			break;
		}
		else
		{
			// Free nodes based on the result value
			if (result % 2 == 0)
				free_node(&head1, &tail1);
			else
				free_node(head3, tail3);
			result++;  // Increment result counter
		}
	}
	
	// Print the final result
	printf("Result is: ");
	if (negative_flag)
		printf("-");  // Print negative sign if the result should be negative
	printf("%d\n", count);  // Print the quotient count
}

