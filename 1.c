#include <stdio.h>
#include <stdlib.h>

/*

Practice question 1:

Add Two Numbers

Shivam is the youngest programmer in the world, he is just 12 years old. Shivam is learning programming and today he is writing his first program.

The task is very simple: given two integers A and B, write a program to add these two numbers and output it.

Input
The first line contains an integer T, the total number of test cases. Then follow T lines, each line contains two Integers A and B.

Output
For each test case, add A and B and display the sum in a new line.

Constraints
1 ≤ T ≤ 1000
0 ≤ A,B ≤ 10000

Sample Input 1
3
1 2
100 200
10 40

Sample Output 1
3
300
50

*/

void main()
{
    printf("\n\nCodeChef Program 1.\n\n");
    char choice;
    int T = 1;
    int A, B;
    int* sum = (int*) calloc(T, sizeof(int)); // Dynamically declaring an array of size T using pointers.
    do
    {
        printf("\nEnter two numbers for addition where 0 <= (Each number entered) <= 10000:\n\n");
        do // Input validation for A.
        {
            printf("First number: ");
            scanf("%d", &A);
            if(A < 0 || A > 10000)
                printf("\nInvalid entry. Please enter again:\n\n");
        } while (A < 0 || A > 10000);
        do // Input validation for B.
        {
            printf("Second number: ");
            scanf("%d", &B);
            if(B < 0 || B > 10000)
                printf("\nInvalid entry. Please enter again:\n\n");
        } while (B < 0 || B > 10000);

        sum[T] = A + B;

        // Displaying the output in the desired format after each test case:
        printf("\n%d\n", T);
        for(int i = 1; i <= T; i++)
            printf("%d\n", sum[i]);

        if(T < 1000) // Value range validation for T. Take T < 2 for e.g. which is gonna take 2 test cases. For T = 1, the below if block runs - tbat is the user can enter the 2nd test case now. For T = 2, the 2nd case has already been entered and now the if condition becomes false and the below block doesn't execute. 
        {
            printf("\nEnter 'y' or 'Y' to enter another (test case) pair of numbers for addition. To exit enter any value: ");
            fflush(stdin); // Clears the input and output buffers.
            scanf("%c", &choice);
            if(choice == 'y' || choice == 'Y') // Because min value of T is 1. Therefore, after the user has decided to enter another test case, I'm incrementing T below.
                sum = (int*) realloc(sum, ++T); // Increasing the size dynamically of the dynamically allocated array to incorporate the value of the new test case's sum.
            printf("\n\n");
        }
        else
        {
            printf("\nMax Test cases' value reached. Not allowed to enter more test cases.\n\n");
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');
}