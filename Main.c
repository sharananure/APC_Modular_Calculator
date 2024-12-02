#include <stdio.h>      // For standard input/output functions.
#include <string.h>     // For string handling functions (e.g., strcmp).
#include "main.h"        // Include the custom header file "apc.h" (assumed to contain necessary declarations).

int negative_flag = 0;       // Global flag to indicate if the result should be negative.

int main(int argc, char *argv[])
{
    /* Declare pointers for the doubly linked lists to represent operands and the result. */
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    /* Check for valid number of command-line arguments. */
    if (argc < 4)
    {
        printf("ERROR: Please Pass Valid Arguments\n");
        printf("USAGE: <operand> <operator> <operand>\n");
        return 0;
    }

    /* Validate the operator. */
    if ((strcmp(argv[2], "+") != 0) && (strcmp(argv[2], "-") != 0) && (strcmp(argv[2], "x") != 0) && (strcmp(argv[2], "/") != 0))
    {
        printf("Please pass a valid operator (+, -, x, /)\n");
        return 0;
    }

    /* Insert the operands into linked lists. */
    if (insert_args(&head1, &tail1, &head2, &tail2, argv[1], argv[3]) == success)
    {
        printf("Inserting successful\n");

    }
    else
    {
        printf("Inserting failed\n");
        return 0;
    }

    char op = argv[2][0]; // Store the operator.
    int diff;

    if (op != 'x')  // Check if operator is not multiplication.
    {
        /* Find the length of both operands (excluding sign). */
        int length1 = find_length(argv[1]);
        int length2 = find_length(argv[3]);

        /* Pad with zeros to equalize lengths. */
        if (length1 > length2)
        {
            diff = length1 - length2;
            for (int i = 0; i < diff; i++)
            {
                add_result(&head2, &tail2, 0);
            }
        }
        else if (length2 > length1)
        {
            diff = length2 - length1;
            for (int i = 0; i < diff; i++)
            {
                add_result(&head1, &tail1, 0);
            }
        }
    }

    /* Determine which operand is larger. */
    int big_num = find_bigger(&head1, &head2);

    /* Handle sign for addition and subtraction based on the operands. */
    if (op == '+')
    {
        if (argv[1][0] == '-' && argv[3][0] == '-')
        {
            negative_flag = 1;  // Both operands are negative.
        }
        else if (argv[big_num][0] == '-')
        {
            negative_flag = 1;  // The larger number is negative.
        }
    }
    else if (op == '-')
    {
        if ((big_num == 1 && argv[1][0] == '-') || (argv[3][0] != '-' && big_num != 1))
        {
            negative_flag = 1;
        }
    }
    else if (op == '/' || op == 'x')
    {
        if ((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
        {
            negative_flag = 1;
        }
    }

    /* Adjust operator based on sign handling for addition and subtraction. */
    if (argv[2][0] == '+')
    {
        op = ((argv[1][0] != '-' && argv[3][0] == '-') || (argv[1][0] == '-' && argv[3][0] != '-')) ? '-' : '+';
    }
    else if (argv[2][0] == '-')
    {
        op = ((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-')) ? '+' : '-';
    }

    /* Switch case to handle arithmetic operations. */
    switch (op)
    {
        case '+':
            if (addition(head1, tail1, head2, tail2, &head3, &tail3) == success)
			{
				printf("Addition successfully done\n");
			}
            else
			{
				printf("Addition failed\n");
			}
            break;
        case '-':
            if (big_num == 1)
                if(subtraction(head1, tail1, head2, tail2, &head3, &tail3) == success)
				{
					printf("Subtraction successfully done\n");
				}
				else
				{
					printf("Subtraction failed\n");
				}
            else if (big_num == 3)
                if(subtraction(head2, tail2, head1, tail1, &head3, &tail3) == success)
				{
					printf("Subtraction successfully done\n");
				}
				else
				{
					printf("Subtraction failed\n");
				}
            else
            {
                printf("Result is 0\n");
                return 0;
            }
            break;
        case '/':
            if (big_num == 3)
            {
                printf("Division is not possible\nResult is 0\n");
                return 0;
            }
            else
                division(head1, tail1, head2, tail2, &head3, &tail3);
				printf("Division successfully done\n");
            break;
        case 'x':
            if (multiplication(head1, tail1, head2, tail2, &head3, &tail3) == success)
                printf("Multiplication successfully done\n");
            else
                printf("Multiplication failed\n");
            break;
    }

    /* Add negative sign to the result if required. */
    if (negative_flag == 1)
    {
        add_result(&head3, &tail3, '-');
    }

    /* Print the result for non-multiplication and non-division operations. */
    if (op != 'x' && op != '/')
    {
        print_result(&head3, &tail3);
    }

    /* Free all nodes after the operation. */
    free_all_nodes(&head1, &tail1, &head2, &tail2, &head3, &tail3);

    return 0;
}
