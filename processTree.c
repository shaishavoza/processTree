#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>

int main (int argc, char *argv[]) {

    int L = atoi(argv[1]);
    int N = atoi(argv[2]);

   	
    for (int i = 0; L > 0 && i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            printf("Something went wrong at process pid = %d\n", getpid());
            exit(EXIT_FAILURE);
        } else if (!pid) {
            pid_t current_pid = getpid();
            pid_t parent_pid = getppid();
            printf("(%d): Process starting\n", current_pid);
            printf("(%d): Parent's id = (%u)\n", current_pid, parent_pid);
            printf("(%d): Level in the tree = %d\n", current_pid, L);
            printf("(%d): Creating %d children at Level %d\n", current_pid, N, L);


			char str[20];
            sprintf(str, "%d", L - 1);

            argv[1] = str;
            execve(argv[0], argv, NULL);
            _exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
            printf("(%d): Terminating at Level %d\n", getpid(), L);
        }
    }

    return 0;

}
