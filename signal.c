#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static void sighandler( int signo ) {
    if (signo == SIGINT ) {

        int a = open("foo.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
        if (a == -1) {
		    printf("Error: %s\n", strerror(errno));
		    return;
	    }
        char msg[40] = "Program exited due to SIGINT";
        int b = write(a, msg, 40);
        if (b == -1) {
		    printf("Error: %s\n", strerror(errno));
		    return;
	    }

        close(a);
        exit(0);

    }

    if (signo == SIGUSR1) {
        printf("Parent process PID: %d\n", getppid());
    }

}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (1) {
        printf("Process PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
    

}