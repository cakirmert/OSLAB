#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Include the sys/wait.h header for the wait function

void childProcess(char character) {
    while(1) {
        putchar(character);
        fflush(stdout); // Flush the output buffer to ensure characters are immediately displayed, 
	// otherwise they will not appear until the buffer is full or newline is encountered, since
	// we have no newline and we want to display immediately, we use this. 
        usleep(1); // Sleep for 1 milliseconds
    }
}

int main() {
    pid_t pid1, pid2;

    // Create the first child process
    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Failed to create first child process\n");
        return 1;
    } else if (pid1 == 0) {
        // This is the first child process
        childProcess('A');
        exit(0);
    }

    // Create the second child process
    pid2 = fork();

    if (pid2 < 0) {
        fprintf(stderr, "Failed to create second child process\n");
        return 1;
    } else if (pid2 == 0) {
        // This is the second child process
        childProcess('B');
        exit(0);
    }

    // Parent process waits for both child processes to terminate
    wait(NULL); // Include this line to wait for the first child process
    wait(NULL); // Include this line to wait for the second child process

    return 0;
}

