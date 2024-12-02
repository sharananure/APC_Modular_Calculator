#include "main.h"  // Include the header file that contains declarations for the linked list functions and data structures.

/* 
 * Function to perform addition of two numbers represented by doubly linked lists.
 * The result is stored in a new linked list.
 */
Status addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3)
{
    int carry = 0, sum = 0, res = 0, cc = 0;  // Initialize variables for carry, sum, result, and carry calculation.

    Dlist *temp1 = tail1;  // Pointer to traverse the first linked list from the tail.
    Dlist *temp2 = tail2;  // Pointer to traverse the second linked list from the tail.

    // Traverse both linked lists until both reach the beginning.
    while (temp1 != NULL || temp2 != NULL)
    {
        // Pad with zeros if one list is shorter than the other.
        if (temp1->prev == NULL && temp2->prev != NULL)
        {
            add_result(&head1, &tail1, 0);  // Add 0 to the beginning of the first list if it is shorter.
        }
        else if (temp2->prev == NULL && temp1->prev != NULL)
        {
            add_result(&head2, &tail2, 0);  // Add 0 to the beginning of the second list if it is shorter.
        }

        // Calculate the sum of corresponding digits along with the carry.
        res = (temp1->data) + (temp2->data) + carry;
        cc = res / 10;       // Calculate the carry for the next iteration.
        res = res % 10;       // Extract the current digit by taking modulo 10.
        sum = res;            // Store the result digit.

        add_result(head3, tail3, sum);  // Add the result digit to the result list.

        // Move to the previous nodes in both lists.
        temp1 = temp1->prev;
        temp2 = temp2->prev;
        carry = cc;  // Update carry for the next iteration.
    }

    // If there's a carry left after the final iteration, add it to the result list.
    if (carry != 0)
    {
        add_result(head3, tail3, carry);
    }

    return success;  // Return success status after completing the addition.
}
