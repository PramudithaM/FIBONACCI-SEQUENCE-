#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    // Initialize Fibonacci sequence terms and the next term
    int firstTerm = 0, secondTerm = 1, nextTerm = firstTerm + secondTerm;
    int sequenceLength, i;

    pid_t pid; // Process ID variable

    printf(" Enter the length of the Fibonacci Sequence:");
    scanf("%d", &sequenceLength);

    if (sequenceLength < 0)
    {
        printf("\n You entered a negative number. Please enter a non-negative number!\n");
    }
    else
    {

        // Create a new process (child) using fork
        pid = fork();

        if (pid == 0)
        { // Child process
            printf(" Child is generating the Fibonacci Sequence...\n");
            if (sequenceLength > 2)
            {
                sequenceLength -= 2;
                printf(" %d %d ", firstTerm, secondTerm);
                // Generate and print the Fibonacci sequence
                for (i = 0; i < sequenceLength; i++)
                {
                    nextTerm = firstTerm + secondTerm;
                    printf("%d ", nextTerm);
                    firstTerm = secondTerm;
                    secondTerm = nextTerm;
                }
            }
            else
            {
                printf(" %d %d ", firstTerm, secondTerm);
            }
            printf("\n Child ends\n");
        }
        else
        { // Parent process
            printf(" Parent is waiting for child to complete...\n");
            // Wait for the child process to finish
            wait(NULL);
            printf(" Parent ends\n");
        }
    }
    return 0;
}