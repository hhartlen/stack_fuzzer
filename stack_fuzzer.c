#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stack_fuzzer(int max_number_of_commands) {
    const char *commands[] = {"ISEMPTY", "ISFULL", "PUSH", "POP", "PEEK"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    srand(time(NULL));

    for (int i = 0; i < max_number_of_commands; i++) {
        int cmd_index = rand() % num_commands;
        printf("%s\n", commands[cmd_index]);

        if (cmd_index == 2) {  // If PUSH, add a random integer
            printf("%d\n", rand() % 100);
        }
    }
    
    printf("EXIT\n");  // EXIT must be the last command
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_commands>\n", argv[0]);
        return 1;
    }

    int max_number_of_commands = atoi(argv[1]);
    if (max_number_of_commands <= 0) {
        fprintf(stderr, "Error: number_of_commands must be positive.\n");
        return 1;
    }

    stack_fuzzer(max_number_of_commands);
    return 0;
}
