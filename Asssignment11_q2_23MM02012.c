#include <stdio.h>
#include <stdlib.h> // For malloc

char *removeDuplicates(char *s) {
    // Variables to track the stack and its size
    char stack[100000];
    int stackSize = 0;

    // Iterate through the input string
    while (*s != '\0') {
        // If the stack is empty or the current character is different from the top of the stack
        if (stackSize == 0 || stack[stackSize-1] != *s) {
            // Add the character to the stack
            stack[stackSize++] = *s;
        } else {
            // Otherwise, remove the top character from the stack
            stackSize--;
        }
        // Move to the next character in the input string
        s++;
    }

    // Build the result string from the characters left in the stack
    char *resStr = (char *)malloc(sizeof(char) * (stackSize + 1));
    for (int i = 0; i < stackSize; i++) {
        resStr[i] = stack[i];
    }
    resStr[stackSize] = '\0';

    // Return the result string
    return resStr;
}

int main() {
    // Example input string
    char input[100000];
    
    // Prompt user to input a string
    printf("Enter a string: ");
    scanf("%s", input);

    // Call the function and print the result
    char *result = removeDuplicates(input);
    printf("Result: %s\n", result);
    // Free dynamically allocated memory
    free(result);
    return 0;
}
