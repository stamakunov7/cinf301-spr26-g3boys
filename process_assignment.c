#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void process_demo() {
    fflush(stdout);
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("[Child ] PID=%d, Parent PID=%d\n", getpid(), getppid());
        printf("[Child ] Doing child work...\n");
        sleep(1);
        printf("[Child ] Child done.\n");
        exit(42);
    } else {
        int status = 0;
        printf("[Parent] PID=%d, created child PID=%d\n", getpid(), pid);
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("[Parent] Child exited with code %d\n", WEXITSTATUS(status));
        } else {
            printf("[Parent] Child ended abnormally.\n");
        }
    }
}

void file_demo() {
    const char *filename = "demo_output.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        return;
    }

    char buffer[256];
    int written = snprintf(
        buffer,
        sizeof(buffer),
        "File demo line from PID %d\nThis file was created with open/write/close.\n",
        getpid()
    );

    if (write(fd, buffer, (size_t)written) < 0) {
        perror("write failed");
        close(fd);
        return;
    }

    close(fd);
    printf("Wrote demo text to %s\n", filename);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open for read failed");
        return;
    }

    memset(buffer, 0, sizeof(buffer));
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read failed");
        close(fd);
        return;
    }
    close(fd);

    printf("Read back from file:\n%s\n", buffer);
}

void exec_demo() {
    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("[Child ] Running exec: ls -la\n");
        execlp("ls", "ls", "-la", (char *)NULL);
        perror("exec failed");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
        printf("[Parent] exec demo complete.\n");
    }
}

void pipe_demo() {
    int fd[2];
    if (pipe(fd) < 0) {
        perror("pipe failed");
        return;
    }

    fflush(stdout);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        close(fd[0]);
        close(fd[1]);
        return;
    }

    if (pid == 0) {
        close(fd[0]);
        const char *msg = "Hello parent, this came through a pipe!";
        if (write(fd[1], msg, strlen(msg) + 1) < 0) {
            perror("pipe write failed");
        }
        close(fd[1]);
        exit(0);
    } else {
        char recv[128];
        close(fd[1]);
        memset(recv, 0, sizeof(recv));
        if (read(fd[0], recv, sizeof(recv)) < 0) {
            perror("pipe read failed");
        } else {
            printf("[Parent] Received from child: %s\n", recv);
        }
        close(fd[0]);
        waitpid(pid, NULL, 0);
    }
}

int main() {
    int choice = -1;
    setvbuf(stdout, NULL, _IONBF, 0);

    while (choice != 5) {
        printf("\n1. Process Demo\n");
        printf("2. File Demo\n");
        printf("3. Exec Demo\n");
        printf("4. Pipe Demo\n");
        printf("5. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("Invalid input. Enter a number from 1-5.\n");
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                process_demo();
                break;
            case 2:
                file_demo();
                break;
            case 3:
                exec_demo();
                break;
            case 4:
                pipe_demo();
                break;
            case 5:
                printf("Exiting program. Good luck with submission!\n");
                break;
            default:
                printf("Invalid option. Choose 1-5.\n");
                break;
        }
    }

    return 0;
}
