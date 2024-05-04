#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include<stdlib.h>
using namespace std;
 

int main() {
    char* userInput;

    // Prompt the user for input using Readline
    userInput = readline("Enter a line of text: ");

    // Display the input
    printf("You entered: %s\n", userInput);

    // Free the memory allocated by Readline
    free(userInput);

    return 0;
}
