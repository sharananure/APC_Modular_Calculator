#include "main.h"

/* 
 * Function to perform subtraction of two numbers represented by doubly linked lists.
 * The result is stored in a new linked list.
 */
Status subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **head3, Dlist **tail3)
{
    int sub = 0;  // Variable to store the subtraction result for each node.
    Dlist* temp1 = tail1;  // Pointer to traverse the first list from the tail.
    Dlist* temp2 = tail2;  // Pointer to traverse the second list from the tail.
    Dlist* temp3 = temp1;  // Temporary pointer used for borrowing during subtraction.

    // Loop until both lists have been completely traversed.
    while (temp1 != NULL || temp2 != NULL)
    {
        // Check if borrowing is needed.
        if (temp1->data >= temp2->data)
        {
            // Direct subtraction if no borrowing is required.
            sub = (temp1->data) - (temp2->data);
        }
        else
        {
            // Borrow logic: Traverse backwards to find a digit greater than 0.
            temp3 = temp1->prev;
            while (temp3 != NULL)
            {
                if (temp3->data > 0)
                {
                    temp3->data--;  // Decrement the first non-zero digit found.
                    break;
                }
                else if (temp3->data == 0 && temp3->prev != NULL)
                {
                    temp3->data = 9;  // Replace zero with 9 if borrowing continues further back.
                }
                temp3 = temp3->prev;  // Move to the previous node.
            }
            // Subtract using the borrowed value by adding 10 to the current digit.
            sub = ((temp1->data) + 10) - (temp2->data);
        }

        // Add the computed result to the result list.
        add_result(head3, tail3, sub);

        // Move both pointers to the previous nodes for the next iteration.
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    return success;  // Return success after successful completion of subtraction.
}
